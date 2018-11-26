// 面试题8: “把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。”

#include <iostream>
#include <exception>

using std::cin;
using std::cout;
using std::endl;

int min_in_order(int data[], int start, int end){
  int min_ele = data[start];
  // cout << "min ele is " << min_ele << endl;
  for(int i = start + 1; i <= end; i++){
    if(min_ele > data[i]){
      min_ele = data[i];
    }
  }
  return min_ele;
}

int min_order(int data[], int length){
  if(data == NULL || length <= 0){
    return -1;
  }

  int start = 0, end = length - 1;
  int mid_index = start;

  while(data[start] >= data[end]){
    
    if(end - start <= 1){
      return data[end];
    }

    mid_index = (start + end) / 2; 

    if(
      data[start] == data[end]
      && data[start] == data[mid_index]
    ){
      return min_in_order(data, start, end);
    }
    
    if(data[mid_index] >= data[start]){
      start = mid_index;
    } else {
      end = mid_index;
    }
  }
  
  return data[mid_index];
}

int main(){
  int data[] = {3, 4, 5, 1, 2};
  cout << min_order(data, 5) << endl;
  int data2[] = {1, 0, 1, 1, 1};
  cout << min_order(data2, 5) << endl;
  int data3[] = {2, 0, 1};
  cout << min_order(data3, 3) << endl;
  return 0;
}