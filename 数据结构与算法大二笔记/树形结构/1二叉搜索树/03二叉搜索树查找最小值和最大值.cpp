#include <iostream>

struct BstNode
{
  int data;
  BstNode *left, *right;
  BstNode(int val) : data(val), left(nullptr), right(nullptr) {}

  void Insert(int val);
  bool Search(int val);
  ~BstNode();

  int FindMin();
  int FindMax();
};

int main()
{
  // ����һ�� BST�����������ɽڵ�
  BstNode *root = new BstNode(50);
  int values[] = {30, 70, 20, 40, 60, 80};
  for (int v : values)
  {
    root->Insert(v);
  }

  // ���� findmin �� findmax
  std::cout << "BST ����Сֵ: " << root->FindMin() << std::endl; // ���� 20
  std::cout << "BST �����ֵ: " << root->FindMax() << std::endl; // ���� 80

  // �����ڴ�
  delete root;
  return 0;
}

void BstNode::Insert(int val)
{
  if (val == data)
  {
    return; // �ظ����ݲ�����
  }
  if (val > data)
  {
    if (right)
    {
      right->Insert(val);
    }
    else
    {
      right = new BstNode(val);
    }
  }
  else if (val < data)
  {
    if (left)
    {
      left->Insert(val);
    }
    else
    {
      left = new BstNode(val);
    }
  }
  return;
}

bool BstNode::Search(int val)
{
  if (val == data)
  {
    return true;
  }
  else if (val > data)
  {
    if (right)
    {
      return right->Search(val);
    }
    else
    {
      return false;
    }
  }
  else
  {
    if (left)
    {
      return left->Search(val);
    }
    else
    {
      return false;
    }
  }
}

BstNode::~BstNode()
{
  delete left;
  delete right;
}

int BstNode::FindMin()
{
  if (!left)
  {
    return data;
  }
  else
  {
    return left->FindMin();
  }
}

int BstNode::FindMax()
{
  if (!right)
  {
    return data;
  }
  else
  {
    return right->FindMax();
  }
}