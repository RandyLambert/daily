#include <iostream>
class Singleton {
public:
  static Singleton& GetInstance() {
    static Singleton intance;
    return intance;
  }

  ~Singleton() = default;

private:
  Singleton() = default;

  Singleton(const Singleton&) = delete;
  Singleton& operator=(const Singleton&) = delete;
};

int main() {
  Singleton& s1 = Singleton::GetInstance();
  std::cout << &s1 << std::endl;

  Singleton& s2 = Singleton::GetInstance();
  std::cout << &s2 << std::endl;

  return 0;
}
