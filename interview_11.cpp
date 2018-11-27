// 题目：“实现函数double Power（double base, int exponent），求base的exponent次方。不得使用库函数，同时不需要考虑大数问题。”
// 难点：考虑多种情况（包括错误处理）

#include <iostream>
#include <math.h>
#include <string>

#define MIN_VALUE 1e-8

using namespace std;

class Exception{
  private:
    string msg;
  public:
    Exception(){}
    Exception(string msg):msg(msg){}
    string what(){ return msg; }
};

// 浮点数运算有精度差别
bool double_equal(double num1, double num2){
  return abs(num1 - num2) < MIN_VALUE ? true : false;
}

double power_with_valid_value(double base, int exponent){
  if(exponent == 1){
    return base;
  }

  if(exponent == 0){
    return 1.0;
  }
  
  double unsigned_res = power_with_valid_value(base, exponent >> 1);
  unsigned_res *= unsigned_res;

  // 判断指数是不是奇数
  if((exponent & 1) == 1){
    unsigned_res *= base;
  }

  return unsigned_res;
}

double power(double base, int exponent){
  // 0的负数次方没有意义
  if(double_equal(base, 0.0) && exponent <= 0){
    throw Exception("0的非正次方没有意义");
  }

  // 任何数的0次方都是 1. 除了前面的 0
  if(exponent == 0){
    return 1.0;
  }
  
  // 对于负指数，先计算正数绝对值的结果；然后对结果取倒数
  int abs_exponent = abs(exponent);

  // 方法1: 循环乘
  // double result = 1.0;
  // for(int i = 0; i < abs_exponent; i++){
  //   result *= base;
  // }

  // 方法2: 时间复杂度为O(lgN)
  double result = power_with_valid_value(base, abs_exponent);

  return exponent < 0 ? (1.0 / result) : result;
}

int main(){
  int base, exponent;
  while(1){
    cout << "base: "; cin >> base;
    cout << "exponent: "; cin >> exponent;
    try {
      cout << "result is: " << power(base, exponent) << endl;
    }catch(Exception e){
      cout << e.what() << endl;
    }catch(...){}
  }
  
  return 0;
}