// 题目： 创建一个线程安全的单例模式

// lock 头文件：http://www.cplusplus.com/reference/mutex/mutex/lock/

#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx;

using namespace std;

class Singleton{
public:
	static Singleton* getInstance();

private:
	Singleton();
	//把复制构造函数和=操作符也设为私有,防止被复制
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);

	static Singleton* instance;
};

Singleton::Singleton(){}

Singleton::Singleton(const Singleton&){}

Singleton& Singleton::operator=(const Singleton&){}

Singleton* Singleton::instance = NULL;

// 惰性单例模式
Singleton* Singleton::getInstance(){
  // 判断是否创建过
  if(instance == NULL){
    // std::mutex.lock();
    mtx.lock();
    if(instance == NULL){ // 防止多个线程同时进入临界区
      instance = new Singleton();
    }
    mtx.unlock();
  }
  return instance;
}

int main(){
  Singleton* singleton1 = Singleton::getInstance();
	Singleton* singleton2 = Singleton::getInstance();

	if (singleton1 == singleton2){
    cout << true << endl;
  }

	return 0;
}