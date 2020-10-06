#include<iostream>
#include<atomic>
#include<thread>

std::atomic<bool> flag(true);

void PrintNumber() {
    for (int i = 0; i < 26; i++) {
        while(!flag.load(std::memory_order_acquire))
            std::this_thread::yield();
    	std::cout << i << std::endl;
        flag.store(false, std::memory_order_release);
    }
}

void PrintLetter() {
    for (int i = 0; i < 26; i++) {
        while(flag.load(std::memory_order_acquire))
            std::this_thread::yield();
    	std::cout << static_cast<char>(65+i) << std::endl;
        flag.store(true, std::memory_order_release);
    }
}

int main(){
	std::thread Xiyou(PrintNumber), LinuxGroup(PrintLetter);
	
	Xiyou.join();
	LinuxGroup.join();
	
	return 0;
}
