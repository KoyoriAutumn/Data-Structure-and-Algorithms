#include <iostream>
#include <stack>
#include <list>
#include <cctype>
using namespace std;

bool isPalindrome(const string &s)
{
  // 使用链栈：底层为 std::list
  stack<char, list<char>> st;
  // 预处理：仅保留字母和数字，全部转小写
  for (char c : s)
  {
    if (isalnum((unsigned char)c))
    {
      st.push(tolower((unsigned char)c));
    }
  }
  for (char c : s)
  {
    if (isalnum((unsigned char)c))
    {
      char top = st.top();
      st.pop();
      if (top != tolower((unsigned char)c))
        return false;
    }
  }
  return true;
}

int main()
{
  string s;
  while (true)
  {
    cout << "请输入字符串判断是否为回文（输入 exit 退出）：";
    if (!getline(cin, s))
      break;
    if (s == "exit")
      break;
    cout << (isPalindrome(s) ? "是回文串\n\n" : "不是回文串\n\n");
  }
  return 0;
}
