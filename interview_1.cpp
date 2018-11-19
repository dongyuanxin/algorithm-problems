/**
 * 问题：定义赋值运算符
*/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

class CMyString
{
public:
    CMyString(char* pData = nullptr);
    CMyString(const CMyString& str);
    ~CMyString(void);

    CMyString& operator = (const CMyString& str);

    void Print();
      
private:
    char* m_pData;
};

CMyString::CMyString(char *pData)
{
    if(pData == nullptr)
    {
        m_pData = new char[1];
        m_pData[0] = '\0';
    }
    else
    {
        int length = strlen(pData);
        m_pData = new char[length + 1];
        strcpy(m_pData, pData);
    }
}

CMyString::CMyString(const CMyString &str)
{
    int length = strlen(str.m_pData);
    m_pData = new char[length + 1];
    strcpy(m_pData, str.m_pData);
}

void CMyString::Print()
{
  cout<< m_pData << endl;
}

CMyString::~CMyString()
{
    delete[] m_pData;
}

// 题目代码

CMyString& CMyString::operator=(const CMyString &str){ 
  // 参数常量引用：避免复制调用一次构造函数。
  // 声明const：不会改变参数类型。

  if(this != &str){ // 判断是否是同一实例
    CMyString tmp(str); 
    // 创建新实例，并且将str转移到this。然后重载运算执行完，程序会自动释放新实例
    // 原来的内存空间也被释放了
    char *dataTmp = tmp.m_pData;
    tmp.m_pData = this->m_pData;
    this->m_pData = dataTmp;
  }
  return *this; // 返回自身类型的引用：连续赋值
}

int main(){
  cout << "text begin: "<< endl;

  char text[] = "Hello world";

  CMyString str1(text);
  CMyString str2, str3;
  str3 = str2 = str1;

  str2.Print();
  return 0;
}