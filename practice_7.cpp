// 练习7: 指针运算

#include <iostream>

using namespace std;

void func(int **a ) {
  *a = new int; //callee
  *(*a) = 123; //.data
  //.rodata
}
struct SS{
  int a;
};
void init_xxx(SS **a) {
  *a = (SS*)malloc(sizeof(SS));
  (*a)->a = 123;
}

int main(){

  // SEH 
  int *a; // mov eax, 0
  int b = 12; // mov ebx, 12
  cout << &a << endl;
  a = &b; // mov eax, 
  cout << &a << endl;
  cout<< *a << endl;
  // *a = 1; // mov [eax], 1
  // a = new int;

  int *c = NULL; //caller
  func(&c);
  cout << *c <<endl;
  free(c);
  c = &b;
  cout << *c <<endl;

  return 0;
}