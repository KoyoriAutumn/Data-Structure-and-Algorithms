#include <iostream>

struct BstNode
{
  int data;
  BstNode *left, *right;
  BstNode(int val) : data(val), left(nullptr), right(nullptr) {}

  void Insert(int val);
  bool Search(int val);
  ~BstNode();
};

int main()
{
  // 构造一棵以 10 为根的二叉搜索树
  // BstNode root(10);

  BstNode *root = new BstNode(10);

  // 插入节点
  root->Insert(5);
  root->Insert(15);
  root->Insert(3);
  root->Insert(7);
  root->Insert(12);
  root->Insert(18);

  // 测试搜索
  int tests[] = {7, 12, 20};
  for (int val : tests)
  {
    std::cout << "Search(" << val << ") = "
              << (root->Search(val) ? "Found" : "Not Found")
              << std::endl;
  }
  delete root;

  return 0;
}

void BstNode::Insert(int val)
{
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