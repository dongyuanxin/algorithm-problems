// 题目: 用两个栈实现队列

#include <iostream>
#include <stack>
#include <exception>
#include <memory>
#include <string>

using namespace std;

class Exception{
  private:
    string msg;
  public:
    Exception(){}
    Exception(string msg):msg(msg){}
    string what(){ return msg; }
};

template <typename T> 
class CQueue{
  public:
    CQueue(void);
    ~CQueue(void);
    
    void append_tail(const T&node);
    T delete_head();
  
  private:
    stack<T> stack1;
    stack<T> stack2;
};

template <typename T>
CQueue<T>::CQueue(void){}

template <typename T>
CQueue<T>::~CQueue(void){}

// 元素入队
template <typename T>
void CQueue<T>::append_tail(const T&node){
  stack1.push(node);
}

// 元素出队
template <typename T>
T CQueue<T>::delete_head(){
  T top;
  if(stack2.empty()){
    while(!stack1.empty()){
      top = stack1.top();
      stack1.pop();
      stack2.push(top);
    }
  }

  if(stack2.empty()){
    throw Exception("CQueue Empty Error.");
  }

  top = stack2.top();
  stack2.pop();
  return top;
}

int main(){
  CQueue<int> queue = CQueue<int>();
  
  for(int i = 0; i < 10; i++){
    queue.append_tail(i);
  }

  for(int i = 0; i < 11; i++){
    try{
      cout<< queue.delete_head() << endl;
    } catch(Exception e) { // traits
      cout << e.what() << endl;
    } catch(std::exception e) {
      e.what();
    } catch(...) {
      cout << "Unknown Error" << endl;
    }
  }

  return 0;
}