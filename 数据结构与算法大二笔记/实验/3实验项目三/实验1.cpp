#include <iostream>
#include <stack>
using namespace std;

// 将 0–15 映射到 '0'–'9','A'–'F'
char toChar(int x)
{
  return (x < 10) ? ('0' + x) : ('A' + (x - 10));
}

// 将 num 转换为 base 进制字符串
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
    cout << "请输入一个非负十进制整数（输入 -1 退出）：";
    if (!(cin >> n))
    {
      cin.clear();
      cin.ignore(10000, '\n');
      cout << "输入无效，请重新输入！\n";
      continue;
    }
    if (n == -1)
      break;
    if (n < 0)
    {
      cout << "负数无效，请输入非负数！\n";
      continue;
    }
    cout << "八进制： " << convertBase(n, 8) << "\n";
    cout << "十六进制： " << convertBase(n, 16) << "\n\n";
  }
  return 0;
}
