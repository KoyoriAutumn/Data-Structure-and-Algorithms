#include <iostream>
#include <string>
#include <stack>

void Reverse(std::string& str);

int main()
{
  std::cout << "�������ַ���: ";
  std::string str;
  std::cin >> str;

  Reverse(str);
  std::cout << "�ַ����ѷ�ת: " << str;
  return 0;
}

void Reverse(std::string& str)
{
  std::stack<char> L;
  for(char c : str) L.push(c);

  /* ʹ�����ò����޸�ֵ����Ȼ�ǿ��� */
  /* �ɰ��д���Ϳ�Ѱ���ټ�����Ϊ����ı��ʾ���ָ�� */
  for(char &c : str)
  {
    c = L.top();
    L.pop();
  }
  return;
}