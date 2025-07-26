#include <iostream>

struct BstNode
{
  static bool init;
  int data;
  BstNode *left, *right;
  BstNode() : data(0), left(nullptr), right(nullptr) {}
  BstNode(int val) : data(val), left(nullptr), right(nullptr) {}

  static BstNode *root;

  void Insert(int val);
  ~BstNode();
  void InOrder();
};

BstNode *BstNode::root = new BstNode;
bool BstNode::init = true;

int main()
{
  int arr[] = {16, 5, 17, 29, 11, 3, 15, 20};
  for (int i : arr)
  {
    BstNode::root->Insert(i);
  }
  std::cout << "中序遍历序列：";
  BstNode::root->InOrder();
  delete BstNode::root;
  return 0;
}

void BstNode::Insert(int val)
{
  if (init)
  {
    data = val;
    init = !init;
    return;
  }
  if (val == data)
  {
    return; // 重复数据不插入
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

BstNode::~BstNode()
{
  delete left;
  delete right;
}

void BstNode::InOrder()
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