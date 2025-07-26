#include <iostream>
#include <string>
#include <stack>

class BTNode
{
private:
  char data;
  BTNode *left, *right;

public:
  BTNode() : left(nullptr), right(nullptr) {}
  BTNode(char val) : data(val), left(nullptr), right(nullptr) {}
  ~BTNode();
  void Insert(std::string str);
  int Count();
};

int main()
{
  std::string preorder;
  std::cout << "����������������У��սڵ��� '#' ��ʾ������ exit �˳�����\n���룺";
  std::cin >> preorder;
  if (preorder == "exit" || preorder == "EXIT")
  {
    std::cout << "�������˳���" << std::endl;
    return 0;
  }

  BTNode *root = new BTNode();
  root->Insert(preorder);

  std::cout << "�ö�������Ҷ�ӽ��ĸ���Ϊ��" << root->Count() << std::endl;
  return 0;
}

BTNode::~BTNode()
{
  delete left;
  delete right;
}

void BTNode::Insert(std::string str)
{
  bool LR = true;         // left or right? trueΪleft��falseΪright
  bool begin = true;      // �ж��Ƿ��ǵ�һ���ַ�
  std::stack<BTNode *> Q; // ��¼������ĸ�������

  for (char s : str)
  {
    if (begin)
    {
      this->data = s;
      begin = !begin;
      Q.push(this);
      continue;
    }
    if (s != '#')
    {
      if (LR)
      {
        Q.top()->left = new BTNode(s);
        Q.push(Q.top()->left);
      }
      else if (!LR)
      {
        Q.top()->right = new BTNode(s);
        Q.push(Q.top()->right);
        LR = !LR;
      }
    }
    else if (s == '#')
    {
      if (LR)
      {
        LR = !LR;
      }
      else if (!LR)
      {
        Q.pop();
      }
    }
  }
}

int BTNode::Count()
{
  int num = 0;
  if (left)
  {
    num += left->Count();
  }
  if (right)
  {
    num += right->Count();
  }
  if (!left && !right)
  {
    return num + 1;
  }
  return num;
}