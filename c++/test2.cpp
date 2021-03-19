#include <mutex>
#include <condition_variable>
#include <deque>
#include <vector>
#include <iostream>
#include <thread>

std::mutex g_mtxDegue;
std::mutex g_mtxCout;
std::condition_variable g_cv_not_empty;
std::condition_variable g_cv_not_full;
std::deque<int> g_deque;
int g_itemIndex = 0;

const int g_kItemSize = 30;
const int g_kDequeSize = 10;

void produceItem()
{
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::unique_lock<std::mutex> lock(g_mtxDegue);
	g_cv_not_full.wait(lock, []() { return g_deque.size() < g_kDequeSize; });

	++g_itemIndex;
	g_deque.push_back(g_itemIndex);
	{
		std::lock_guard<std::mutex> lock_guard(g_mtxCout);
		std::cout << "produce item " << g_itemIndex << std::endl;
	}
	lock.unlock();
	g_cv_not_empty.notify_all();
}

void consumeItem()
{
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::unique_lock<std::mutex> lock(g_mtxDegue);
	g_cv_not_empty.wait(lock, []() { return !g_deque.empty(); });

	int itemIndex = g_deque.front();
	g_deque.pop_front();
	{
		std::lock_guard<std::mutex> lock_guard(g_mtxCout);
		std::cout << "\tconsume item " << itemIndex << std::endl;
	}
	lock.unlock();
	g_cv_not_full.notify_one();
}

void produceTask()
{
	int count = g_kItemSize;
	while (count--)
	{
		produceItem();
	}
}

void consumeTask()
{
	int count = g_kItemSize;
	while (count--)
	{
		consumeItem();
	}
}

//单生产者单消费者模型
void consumeProduceTest()
{
	std::vector<std::thread> threads;
	threads.push_back(std::thread(produceTask));
	threads.push_back(std::thread(consumeTask));
	for (int i = 0; i < 2; i++)
		threads.at(i).join();
}
