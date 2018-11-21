// 题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，则输出“We%20are%20happy.
// 注意：
// 1. 是否开辟新的空间？还是直接在原来的空间上修改
// 2. 如果在原来空间上修改，是否保证字符串后面有充足的内存（防止覆盖）

// a bc: 3
// a%20bc: 3 + 1*3

#include <iostream>
#include <string>

using namespace std;

// 从后向前进行替换，时间复杂度为 O(N)
// length参数：能分配给字符串的安全空间

void replace_blank(char str[], int length){
  if(str == NULL && length <= 0){
    return;
  }

  int origin_len = 0, blank_num = 0;
  for(int i = 0; str[i] != '\0'; ){
    ++origin_len;
    if(str[i++] == ' '){
      ++blank_num;
    }
  }

  int new_len = origin_len + blank_num * 2;
  // 如果超出备用空间，可能会引起内存覆盖，退出程序
  if(new_len > length){
    return;
  }

  // 不能从 origin_len - 1 和 new_len - 1 开始
  // 在C语言中，字符串是以 '\0' 结尾，不能丢弃 
  int index_of_origin = origin_len,
    index_of_new = new_len;
  while(index_of_origin >= 0 && index_of_new > index_of_origin){
    if(str[index_of_origin] == ' '){
      str[index_of_new--] = '0';
      str[index_of_new--] = '2';
      str[index_of_new--] = '%';
    }else{
      str[index_of_new--] = str[index_of_origin];
    }
    --index_of_origin;
  }
  
  return;
}

int main(){
  char str[] = "a bc  ";
  replace_blank(str, 100);
  cout<< str << endl;
  return 0; 
}