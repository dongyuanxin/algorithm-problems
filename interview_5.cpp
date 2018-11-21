// 题目5: 从尾到头打印链表
// 

#include <iostream>
#include <stack>

using namespace std;

struct ListNode{
  int value;
  ListNode* next;
  ListNode(int val){
    this->value = val;
    this->next = NULL;
  }
};

bool add_to_tail(ListNode* head, int value){
  if(head == NULL){
    return false;
  }
  
  ListNode* new_node = new ListNode(value);

  ListNode* now = head;
  while(now->next){
    now = now->next;
  }
  now->next = new_node;
  return true;
}

// 逆序输出：采用栈结构实现的代码比递归调用实现的代码的鲁棒性更高
// 如果链表过长，会导致函数调用层级过深！
void print_list_desc(ListNode* head){
  
  stack<ListNode*> nodes;

  ListNode* now = head;
  while(now != NULL){
    nodes.push(now);
    now = now->next;
  }
  
  while(!nodes.empty()){
    ListNode* top = nodes.top();
    nodes.pop();
    cout<< top->value << endl;
  }

}

int main(){
  ListNode* head = new ListNode(0);

  for(int i = 1; i <= 10; i++){
    add_to_tail(head, i);
  }

  print_list_desc(head);

  return 0;
}