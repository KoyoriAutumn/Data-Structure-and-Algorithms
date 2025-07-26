#include <iostream>
#include <stack>

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