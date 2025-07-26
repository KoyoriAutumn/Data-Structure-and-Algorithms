#include <iostream>
#include <stack>
using namespace std;

// �� 0�C15 ӳ�䵽 '0'�C'9','A'�C'F'
char toChar(int x)
{
  return (x < 10) ? ('0' + x) : ('A' + (x - 10));
}

// �� num ת��Ϊ base �����ַ���
string convertBase(long num, int base)
{
  if (num == 0)
    return "0";
  stack<int> st;
  while (num > 0)
  {
    st.push(num % base);
    num /= base;
  }
  string res;
  while (!st.empty())
  {
    res += toChar(st.top());
    st.pop();
  }
  return res;
}

int main()
{
  long n;
  while (true)
  {
    cout << "������һ���Ǹ�ʮ�������������� -1 �˳�����";
    if (!(cin >> n))
    {
      cin.clear();
      cin.ignore(10000, '\n');
      cout << "������Ч�����������룡\n";
      continue;
    }
    if (n == -1)
      break;
    if (n < 0)
    {
      cout << "������Ч��������Ǹ�����\n";
      continue;
    }
    cout << "�˽��ƣ� " << convertBase(n, 8) << "\n";
    cout << "ʮ�����ƣ� " << convertBase(n, 16) << "\n\n";
  }
  return 0;
}
