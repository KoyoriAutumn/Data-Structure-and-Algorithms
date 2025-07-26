#include <iostream>
#include <stack>
#include <list>
#include <cctype>
using namespace std;

bool isPalindrome(const string &s)
{
  // ʹ����ջ���ײ�Ϊ std::list
  stack<char, list<char>> st;
  // Ԥ������������ĸ�����֣�ȫ��תСд
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
    cout << "�������ַ����ж��Ƿ�Ϊ���ģ����� exit �˳�����";
    if (!getline(cin, s))
      break;
    if (s == "exit")
      break;
    cout << (isPalindrome(s) ? "�ǻ��Ĵ�\n\n" : "���ǻ��Ĵ�\n\n");
  }
  return 0;
}
