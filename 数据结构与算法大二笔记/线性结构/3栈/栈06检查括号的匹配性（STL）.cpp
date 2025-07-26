#include <iostream>
#include <stack>

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
  std::stack<char> L;
  for (char c : s)
  {
    switch (c)
    {
      case '(':
      case '[':
      case '{': 
        L.push(c); continue;
      case ')':
      {
        if (L.empty())
        {
          return false;
        }
        else if (L.top() == '(')
        {
          L.pop();
          continue;
        }
        else
        {
          return false;
        }
      }
      case ']':
      {
        if (L.empty())
        {
          return false;
        }
        else if (L.top() == '[')
        {
          L.pop();
          continue;
        }
        else
        {
          return false;
        }
      }
      case '}':
      {
        if (L.empty())
        {
          return false;
        }
        else if (L.top() == '{')
        {
          L.pop();
          continue;
        }
        else
        {
          return false;
        }
      }
    }
  }
  if (!L.empty())
  {
    return false;
  }
  else
  {
    return true;
  }
}