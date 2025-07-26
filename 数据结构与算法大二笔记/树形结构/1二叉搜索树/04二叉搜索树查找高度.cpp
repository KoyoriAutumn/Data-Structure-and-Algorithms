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

  int FindHeight();
};

int main()
{
  // �������ڵ�
  BstNode *root = new BstNode(10);

  // ����һЩ�ڵ�
  int values[] = {5, 15, 3, 7, 12, 18, 1, 4};
  for (int v : values)
    root->Insert(v);

  // ���� FindHeight
  std::cout << "���ĸ߶�Ϊ: " << root->FindHeight() << std::endl;

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

int BstNode::FindHeight()
{
  if (left && right)
  {
    return (left->FindHeight() > right->FindHeight()
                ? (left->FindHeight() + 1)
                : (right->FindHeight() + 1));
  }
  else if (left && !right)
  {
    return (left->FindHeight() + 1);
  }
  else if (!left && right)
  {
    return (right->FindHeight() + 1);
  }
  else
  {
    return 0;
  }
}