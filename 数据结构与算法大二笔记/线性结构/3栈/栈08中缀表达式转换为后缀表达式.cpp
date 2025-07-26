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
  std::cout << "������һ����׺���ʽ: ";
  std::string Expression;
  std::getline(std::cin, Expression);
  std::string NewExpression = Trans(Expression);
  std::cout << "ת����ĺ�׺���ʽΪ: " << NewExpression << std::endl;
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

/* �㷨˼· */
/*
����˵����׺���ʽ���������ȼ���
1. (��)���������ȣ�
2. *��/�˳��������ң�
3. +��-�Ӽ��������ҡ�

������ô˵����׺���ʽ�ͺ�׺���ʽ�����ǵ�����˳���ڱ�������һ���ģ�
ֻ����ǰ�ߵ�����˳���������������������ȼ�������ߵ�����˳����ʽ���ɷ��Ŵ����ұ��ֳ�����
�����ͬ������˶��߿����໥ת����

e.g. (A+B)*C-D-E*F
���������������׺���ʽ��������ô��������ģ�
1. (             //һ�������ţ�����������ȼ�����Ҫһ�����������պ�
2. (A            //Ŀǰ��׺���ʽΪA
3. (A+           //
4. (A+B          //A+B�𣿻��ǻ����һ�������ȼ�����������ǲ�����ģ���Ҫ��ʱ����Ӻš�Ŀǰ��׺���ʽΪAB
5. (A+B)         //�����ţ���˵�������ڲ�����������Ĳ�������ȷ���ˣ����Ӻ�������Ĳ�����ȷ���ˣ�����Ҫ����Ӻ��ˣ�Ŀǰ��׺���ʽΪAB+

6. (A+B)*        //���������������ʱ����˺�
7. (A+B)*C       //����Ҫ����˺��ˣ��˺�������Ĳ�����ȷ���ˣ�Ŀǰ��׺���ʽΪAB+C*
8. (A+B)*C-      //��ʱ������š�����Ҫ���ĳ��������ţ���ֻ����ֿ�ͷ�����������������

9. (A+B)*C-D     //�����һ�������ȼ��������Ŀǰ��׺���ʽΪAB+C*D
10.(A+B)*C-D-    //���Ǽ��ţ������һ�����ţ�ǰһ��������������ñ����ˣ��������ȷ����Ŀǰ��׺���ʽΪAB+C*D-

11.(A+B)*C-D-E   //�����һ�������ȼ��������AB+C*D-E
12.(A+B)*C-D-E*  //���ź����ǳ˺ţ���˵��E��Ҫ���⴦��������������Ĳ�������ȷ��������˺�

13.(A+B)*C-D-E*F //�����ˣ��˺źͼ��Ų��ñ����ˣ��˺źͼ���������Ĳ�����ȷ���ˣ�Ŀǰ��׺���ʽΪAB+C*D-EF*-
��׺���ʽ��AB+C*D-EF*-
���������������������ӱ��ֵúܵ��͡�
���ǿ��Կ�����Ҫʹ������Ĳ�����ȷ�����������ȼ��͵��ǽ���ġ�
��������Ĳ���������ȷ���Ļ�����˵���������ȼ��Ƿ��ϸ�����ġ�
��Ϊ���������ȼ������ʱ�������ȴ���������Ĳ�����

Ϊ��ȷ��������Ĳ�������������Ҫ��ʱ��ס��������ڼ�����Ͼ��Ǳ��档
ͬʱ���������ȼ������ʱ�����ȴ���������Ĳ����������ȼ�������Ǻ����ģ�ȴҪ�ȴ��������LIFOԭ��
����������ʵ���Խ���һ���������ջ��
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
      std::cerr << "[ERROR] �Ƿ����ʽ\n";
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