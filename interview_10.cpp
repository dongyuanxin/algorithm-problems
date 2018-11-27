// “题目：请实现一个函数，输入一个整数，输出该数二进制表示中1的个数。”

#include <iostream>

using namespace std;

// 错误做法1: 如果n为负数，进入死循环
int number_of_one_1(int n){
  int count = 0;
  while(n){
    if(n & 1){
      ++count;
    }
    n = n >> 1;
  }
  return count;
}

// 正确做法: 时间复杂度32（32位系统）或者64（64位系统）
int number_of_one_2(int n){
  int count = 0;
  unsigned int flag = 1; 
  // flag = 1 = Ox1
  // flag = 2 = Ox10
  // flag = 4 = Ox100
  // ... 
  // 最后左移溢出，flag会变成0，然后退出循环
  while(flag){
    if(flag & n){ // flag 和 n 做与运算，而不是 n 和 1 做与运算
      ++count;
    }
    flag = flag << 1;
  }
  return count;
}

// 完美做法：整数减去1的结果 和 整数本身 进行“与”操作
// 例如 Ox1100: Ox1100 & 0x1011 = 0x1000
// 二进制中的 1 被剔除了。
// 时间复杂度：有多少个1，进行多少次循环
int number_of_one_3(int n){
  int count = 0;
  while(n){
    ++count;
    n = (n - 1) & n;
  }
  return count;
}


int main(){
  int a = 0x80000000;
  // cout << number_of_one_1(a) << endl;
  cout << number_of_one_2(a) << endl;
  cout << number_of_one_3(a) << endl;
  return 0;
}