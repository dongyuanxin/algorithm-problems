// 面试题9: 斐波那契数列
// 拓展题目1：“一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。”
// 拓展题目2: “我们可以用2×1（图2.13的左边）的小矩形横着或者竖着去覆盖更大的矩形。请问用8个2×1的小矩形无重叠地覆盖一个2×8的大矩形（图2.13的右边），总共有多少种方法？”

#include <iostream>

using namespace std;

long long fibonacci(int n){
  if(n == 1 || n == 2){
    return n;
  }

  long long a = 1, b = 2, c;
  for(long long i = 3; i <= n; ++i){
    c = a + b;
    a = b;
    b = c;
  }
  return c;
}

int main(){
  // 1 2 3 5
  cout << fibonacci(2) << endl;
  return 0;
}