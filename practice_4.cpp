// 练习：说明输出和原因
// 附加：C++声明字符串的正确方法
// 1. const char* str = "hello"; // str存储在静态存储区，全局可引用地址
// 2. char str[] = "hello"; // str存储在栈空间，超出作用域，立即被释放

#include <iostream>

using namespace std;

int main(){
  // 这种声明要在栈空间上分配新空间，因此，地址不一样
  char str1[] = "hello world";
  char str2[] = "hello world";
  
  // “hello world”是常量字符串，它在内存中只有一个拷贝，因此str3和str4指向的是同一个地址”
  const char* str3 = "hello world";
  const char* str4 = "hello world";

  if(str1 == str2){
    cout<< "str1 == str2\n";
  }else{
    cout<< "str1 != str2\n";
  }

  if(str3 == str4){
    cout<< "str3 == str4\n";
  }else{
    cout<< "str3 != str4\n";
  }

  return 0;
}