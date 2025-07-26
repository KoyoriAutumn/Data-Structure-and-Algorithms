#include <iostream>
#include <string>
#include <stack>

void Reverse(std::string& str);

int main()
{
  std::cout << "请输入字符串: ";
  std::string str;
  std::cin >> str;

  Reverse(str);
  std::cout << "字符串已反转: " << str;
  return 0;
}

void Reverse(std::string& str)
{
  std::stack<char> L;
  for(char c : str) L.push(c);

  /* 使用引用才能修改值，不然是拷贝 */
  /* 旧版的写法就可寻其踪迹，因为数组的本质就是指针 */
  for(char &c : str)
  {
    c = L.top();
    L.pop();
  }
  return;
}