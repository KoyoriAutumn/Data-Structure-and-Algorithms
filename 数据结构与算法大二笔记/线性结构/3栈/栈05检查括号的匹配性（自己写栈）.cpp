#include <iostream>
#include <string>

bool isValid(std::string s);

int main()
{
  std::cout << "������һ��ֻ���� '(', ')', '{', '}', '[', ']' ���ַ���: ";
  std::string s;
  std::cin >> s;

  std::cout << "���ַ���������" << (isValid(s) ? "��" : "����") << "����ƥ��ģ�\n";
  return 0;
}

bool isValid(std::string s)
{
  char Stack[10000];
  int top = -1;
  for (char c : s) //Modern C++���÷���ʹ�÷�Χѭ����ȫ���������ַ�����������Խ��
  {
    switch (c)
    {
      case '(':
      case '[':
      case '{': 
        Stack[++top] = c; continue;
      case ')':
      {
        if (top == -1)
        {
          return false;
        }
        else if (Stack[top] == '(')
        {
          top--;
          continue;
        }
        else
        {
          return false;
        }
      }
      case ']':
      {
        if (top == -1)
        {
          return false;
        }
        else if (Stack[top] == '[')
        {
          top--;
          continue;
        }
        else
        {
          return false;
        }
      }
      case '}':
      {
        if (top == -1)
        {
          return false;
        }
        else if (Stack[top] == '{')
        {
          top--;
          continue;
        }
        else
        {
          return false;
        }
      }
    }
  }
  if (top > -1)
  {
    return false;
  }
  else
  {
    return true;
  }
}