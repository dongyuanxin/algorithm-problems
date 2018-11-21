// 题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
// 请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

#include <iostream>
#include <vector>

using namespace std;

bool find_ele(int matrix[][4], int row, int col, int ele){
  bool found = false;

  if(matrix == NULL || row <= 0 || col <= 0){
    return found;
  }

  for(int i = 0, j = col - 1; i < row && j >= 0 ;){
    // cout<< matrix[i][j] << " " << ele << endl;
    if(matrix[i][j] == ele){
      found = true;
      break;
    }else if(matrix[i][j] > ele){
      j--;
    }else{
      i++;
    }
  }

  return found;
}

int main(){
  int matrix[4][4] = {
    {1,2,8,9},
    {2,4,9,12},
    {6,7,10,13},
    {6,8,11,15}
  };
  cout<< find_ele(matrix, 4, 4, 11) << endl;
  return 0;
}