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
  << "后缀表达式（也称为逆波兰表达式）是一种数学表达式的表示方法，其中操作符位于操作数的后面。\n"
  << "这种表示法消除了括号，在计算机科学中非常有用，因为它对于计算机来说更容易计算和解析。\n"
  << "与中缀表达式（通常我们使用的数学表达式，例如“a * (b + c)”）不同，后缀表达式的运算符放在操作数之后，例如：“a b c + *”。\n"
  << "这个程序可以帮助你计算后缀表达式。注意：仅限加减乘除（+-*/），不同的操作数和运算符之间只能用空格或逗号分开。\n\n"
  << "请输入你要计算的后缀表达式: ";

  std::string Expression;
  std::getline(std::cin, Expression);
  int RResult = Result(Expression);
  std::cout << "表达式结果为 " << RResult << std::endl;
  return 0;
}

int Result(std::string Expression)
{
  std::stack<int> Number;
  /*
  for (char c : Expression)
  这样是逐个遍历，但是我们会遇到多位数字的情况
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
        std::cerr << "[ERROR] 运算符 " << Expression[i] << " 缺少足够的操作数\n";
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
      std::cerr << "[ERROR] 非法字符 " << Expression[i] << std::endl;
      exit(1);
    }
  }
  if(Number.size() == 1)
  {
    return Number.top();
  }
  else
  {
    std::cerr << "[ERROR] 非法表达式\n";
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
        std::cerr << "[ERROR] 除数不可为0\n";
        exit(1);
      }
      Number.push(num1 / num2);
      break;
    }
  }
  return;
}