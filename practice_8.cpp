// 练习8: 重新回顾下经典的快速排序

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

class Exception{
  public:
    Exception(){}
};

int partion(int data[], int start, int end){
  if(data == NULL || start < 0 || start > end){
    throw Exception();
  }
  int index = start + rand() % (end - start + 1);
  swap(data[start], data[index]);
  int v = data[start];

  int i = start + 1, j = end;
  while(1){
    while(i <= end && data[i] < v){
      ++i;
    }
    while(j >= start + 1 && data[j] > v){
      --j;
    }
    if(i > j){
      break;
    }
    swap(data[i], data[j]);
  }
  
  swap(data[start], data[j]);
  return j;
}

void quick_sort(int data[], int start, int end){
  if(start >= end){
    return;
  }
  
  int p = partion(data, start, end);
  quick_sort(data, start, p - 1);
  quick_sort(data, p + 1, end);
}

int main(){
  const int num = 5;
  int data[num] = {5, 1, 0, 2, 3};
  quick_sort(data, 0, num - 1);

  for(int i = 0; i < num; i++){
    cout<< data[i] << " ";
  }
  cout<< endl;

  return 0;
}