#include <iostream>
#include <stack>
#include <string>

bool IsLetter(char c);
bool IsOperator(char c);
bool IsInterval(char c);
bool IsBracket(char c);
std::string Trans(std::string Expression);

int main()
{
  std::cout << "请输入一个中缀表达式: ";
  std::string Expression;
  std::getline(std::cin, Expression);
  std::string NewExpression = Trans(Expression);
  std::cout << "转换后的后缀表达式为: " << NewExpression << std::endl;
  return 0;
}

bool IsLetter(char c)
{
  if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) return true;
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
  if (c == ' ') return true;
  return false;
}

bool IsBracket(char c)
{
  if (c == '(' || c == ')')
  {
    return true;
  }
  return false;
}

/* 算法思路 */
/*
首先说明中缀表达式的运算优先级：
1. (、)括号最优先；
2. *、/乘除从左往右；
3. +、-加减从左往右。

可以这么说，中缀表达式和后缀表达式，它们的运算顺序在本质上是一样的，
只不过前者的运算顺序隐藏在上述的运算优先级里，而后者的运算顺序显式地由符号从左到右表现出来。
这个相同点决定了二者可以相互转化。

e.g. (A+B)*C-D-E*F
我们来看看这个中缀表达式到底是怎么计算出来的：
1. (             //一个左括号！这是最高优先级，需要一个右括号来闭合
2. (A            //目前后缀表达式为A
3. (A+           //
4. (A+B          //A+B吗？还是会出现一个高优先级运算符？这是不清楚的，需要暂时保存加号。目前后缀表达式为AB
5. (A+B)         //右括号！这说明括号内部所有运算符的操作数都确定了，即加号运算符的操作数确定了，不需要保存加号了：目前后缀表达式为AB+

6. (A+B)*        //会出现左括号吗？暂时保存乘号
7. (A+B)*C       //不需要保存乘号了，乘号运算符的操作数确定了：目前后缀表达式为AB+C*
8. (A+B)*C-      //暂时保存减号。不需要担心出现左括号，它只会出现开头或在其他运算符后面

9. (A+B)*C-D     //会出现一个高优先级运算符吗？目前后缀表达式为AB+C*D
10.(A+B)*C-D-    //还是减号，保存后一个减号，前一个减号运算符不用保存了，其操作数确定：目前后缀表达式为AB+C*D-

11.(A+B)*C-D-E   //会出现一个高优先级运算符吗？AB+C*D-E
12.(A+B)*C-D-E*  //减号后面是乘号，这说明E需要另外处理，而减号运算符的操作数不确定。保存乘号

13.(A+B)*C-D-E*F //结束了，乘号和减号不用保存了，乘号和减号运算符的操作数确定了：目前后缀表达式为AB+C*D-EF*-
后缀表达式：AB+C*D-EF*-
核心在于运算符，这个例子表现得很典型。
我们可以看到，要使运算符的操作数确定，运算优先级就得是降序的。
但运算符的操作数不能确定的话，就说明运算优先级是非严格升序的。
因为遇到高优先级运算符时，需优先处理其关联的操作。

为了确定运算符的操作数，我们需要暂时记住运算符，在计算机上就是保存。
同时遇到高优先级运算符时需优先处理其关联的操作。高优先级运算符是后来的，却要先处理，这符合LIFO原则。
所以我们其实可以建立一个运算符的栈。
*/
std::string Trans(std::string Expression)
{
  std::string NewExpression;
  std::stack<char> Operator;
  for (int i = 0; i < Expression.size(); i++)
  {
    if (IsInterval(Expression[i]))
    {
      continue;
    }
    else if (IsLetter(Expression[i]))
    {
      NewExpression += Expression[i];
      continue;
    }
    else if (IsOperator(Expression[i]))
    {
      if(Operator.empty())
      {
        Operator.push(Expression[i]);
        continue;
      }
      else if ((Expression[i] == '+' || Expression[i] == '-') && (Operator.top() == '*' || Operator.top() == '/'))
      {
        while (!Operator.empty() && Operator.top() != '(')
        {
          NewExpression += Operator.top();
          Operator.pop();
        }
        Operator.push(Expression[i]);
        continue;
      }
      else if ((Expression[i] == '*' || Expression[i] == '/') && (Operator.top() == '+' || Operator.top() == '-'))
      {
        Operator.push(Expression[i]);
        continue;
      }
      else if ((Expression[i] == '+' || Expression[i] == '-') && (Operator.top() == '+' || Operator.top() == '-'))
      {
        Operator.push(Expression[i]);
        continue;
      }
      else if ((Expression[i] == '*' || Expression[i] == '/') && (Operator.top() == '*' || Operator.top() == '/'))
      {
        Operator.push(Expression[i]);
        continue;
      }
      else if (IsOperator(Expression[i]) && Operator.top() == '(')
      {
        Operator.push(Expression[i]);
      }
    }
    else if (IsBracket(Expression[i]))
    {
      if (Expression[i] == '(')
      {
        Operator.push(Expression[i]);
        continue;
      }
      else if (Expression[i] == ')')
      {
        while (Operator.top() != '(')
        {
          NewExpression += Operator.top();
          Operator.pop();
        }
        Operator.pop();
        continue;
      }
    }
    else
    {
      std::cerr << "[ERROR] 非法表达式\n";
      exit(1);
    }
  }
  while (!Operator.empty())
  {
  NewExpression += Operator.top();
  Operator.pop();
  }
  return NewExpression;
}