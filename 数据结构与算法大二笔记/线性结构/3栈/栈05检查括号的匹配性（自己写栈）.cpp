#include <iostream>
#include <string>

bool isValid(std::string s);

int main()
{
  std::cout << "请输入一个只包括 '(', ')', '{', '}', '[', ']' 的字符串: ";
  std::string s;
  std::cin >> s;

  std::cout << "该字符串的括号" << (isValid(s) ? "是" : "不是") << "左右匹配的！\n";
  return 0;
}

bool isValid(std::string s)
{
  char Stack[10000];
  int top = -1;
  for (char c : s) //Modern C++的用法，使用范围循环安全遍历所有字符，避免索引越界
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