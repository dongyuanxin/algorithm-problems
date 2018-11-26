// 练习9: 基数排序，时间复杂度为O(N)

#include <iostream>

using namespace std;

void sort_ages(int ages[], int length){
  if(ages == NULL || length <= 0){
    return;
  }

  const int max_num = 99;
  int times[max_num + 1];
  for(int i = 0; i < max_num + 1; ++i){
    times[i] = 0;
  }

  for(int i = 0; i < length; ++i){
    ++times[ages[i]];
  }

  for(int i = 0; i < max_num + 1; ++i){
    for(int j = 0; j < times[i]; ++j){
      cout << i << " ";
    }
  }

  cout << endl;

  return;
}

int main(){
  int ages[] = {2, 5, 5, 1, 1, 0};
  sort_ages(ages, 6);
  return 0;
}