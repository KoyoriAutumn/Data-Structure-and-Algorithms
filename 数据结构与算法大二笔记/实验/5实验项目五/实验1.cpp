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
  void InOrder();
  void PostOrder();
  void Insert(std::string str);
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

  std::cout << "����������У�";
  root->InOrder();
  std::cout << "\n����������У�";
  root->PostOrder();
  std::cout << std::endl;
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
        /*
        ���ﲻ��Ҫ�л�LR��״̬��
        ����ΪLRΪfalse��sΪ�գ�
        ��ζ��ջ���ڵ�������������Ѿ�������ϣ�
        ��ô��Ҫ������
        �����󣬽��Ź�����ջ���ڵ㡣
        �����ֿ��ܣ�������ջ���ڵ����������
        ����������Ҳ�������ˣ���ô���ٴε�ջ��
        ������ȥ����һ������������Ϊ��������������ѡ������������
        ������������ֻ��ѡ��ʣ�µġ�
        */
      }
    }
  }
}

void BTNode::InOrder()
{
  if (left)
  {
    left->InOrder();
  }
  std::cout << data << ' ';
  if (right)
  {
    right->InOrder();
  }
  return;
}

void BTNode::PostOrder()
{
  if (left)
  {
    left->PostOrder();
  }
  if (right)
  {
    right->PostOrder();
  }
  std::cout << data << ' ';
  return;
}