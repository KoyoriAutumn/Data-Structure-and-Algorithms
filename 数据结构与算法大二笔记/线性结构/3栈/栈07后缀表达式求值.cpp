#include <iostream>
#include <stack>
#include <string>

int Result(std::string Expression);
bool IsNumber(char c);
bool IsOperator(char c);
bool IsInterval(char c);
void Calculate(std::stack<int>& Number, char c);

int main()
{
  std::cout
  << "��׺���ʽ��Ҳ��Ϊ�沨�����ʽ����һ����ѧ���ʽ�ı�ʾ���������в�����λ�ڲ������ĺ��档\n"
  << "���ֱ�ʾ�����������ţ��ڼ������ѧ�зǳ����ã���Ϊ�����ڼ������˵�����׼���ͽ�����\n"
  << "����׺���ʽ��ͨ������ʹ�õ���ѧ���ʽ�����硰a * (b + c)������ͬ����׺���ʽ����������ڲ�����֮�����磺��a b c + *����\n"
  << "���������԰���������׺���ʽ��ע�⣺���޼Ӽ��˳���+-*/������ͬ�Ĳ������������֮��ֻ���ÿո�򶺺ŷֿ���\n\n"
  << "��������Ҫ����ĺ�׺���ʽ: ";

  std::string Expression;
  std::getline(std::cin, Expression);
  int RResult = Result(Expression);
  std::cout << "���ʽ���Ϊ " << RResult << std::endl;
  return 0;
}

int Result(std::string Expression)
{
  std::stack<int> Number;
  /*
  for (char c : Expression)
  ����������������������ǻ�������λ���ֵ����
  */
  for (int i = 0; i < Expression.size(); i++)
  {
    if (IsInterval(Expression[i]))
    {
      continue;
    }
    else if (IsOperator(Expression[i]))
    {
      if (Number.size() < 2)
      {
        std::cerr << "[ERROR] ����� " << Expression[i] << " ȱ���㹻�Ĳ�����\n";
        exit(1);
      }
      Calculate(Number, Expression[i]);
    }
    else if (IsNumber(Expression[i]))
    {
      int TempAns = Expression[i] - '0';
      for (; i + 1 < Expression.size() && IsNumber(Expression[i + 1]);)
      {
        TempAns = 10 * TempAns + Expression[++i] - '0';
      }
      Number.push(TempAns);
      continue;
    }
    else
    {
      std::cerr << "[ERROR] �Ƿ��ַ� " << Expression[i] << std::endl;
      exit(1);
    }
  }
  if(Number.size() == 1)
  {
    return Number.top();
  }
  else
  {
    std::cerr << "[ERROR] �Ƿ����ʽ\n";
    exit(1);
  }
}

bool IsNumber(char c)
{
  if (c >= '0' && c <= '9') return true;
  return false;
}

bool IsOperator(char c)
{
  switch (c)
  {
    case '+':
    case '-':
    case '*':
    case '/': return true;
  }
  return false;
}

bool IsInterval(char c)
{
  if (c == ',' || c == ' ') return true;
  return false;
}

void Calculate(std::stack<int>& Number, char c)
{
  int num2 = Number.top();
  Number.pop();
  int num1 = Number.top();
  Number.pop();
  switch (c)
  {
    case '+': Number.push(num1 + num2); break;
    case '-': Number.push(num1 - num2); break;
    case '*': Number.push(num1 * num2); break;
    case '/':
    {
      if (num2 == 0)
      {
        std::cerr << "[ERROR] ��������Ϊ0\n";
        exit(1);
      }
      Number.push(num1 / num2);
      break;
    }
  }
  return;
}