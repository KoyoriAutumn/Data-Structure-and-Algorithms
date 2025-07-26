#include <iostream>
#include <queue>

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
  void LevelOrder();

  /*
  前序遍历PreOrder: <root><left><right>
  中序遍历InOrder: <left><root><right>
  后序遍历PostOrder: <left><right><root>
  */
  void PreOrder();
  void InOrder();
  void PostOrder();
};

int main()
{
  BstNode *root = new BstNode(10);
  root->Insert(5);
  root->Insert(15);
  root->Insert(3);
  root->Insert(7);
  root->Insert(12);
  root->Insert(18);

  std::cout << "PreOrder Traversal: ";
  root->PreOrder();
  std::cout << std::endl;

  std::cout << "InOrder Traversal: ";
  root->InOrder();
  std::cout << std::endl;

  std::cout << "PostOrder Traversal: ";
  root->PostOrder();
  std::cout << std::endl;

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

void BstNode::LevelOrder()
{
  std::queue<BstNode *> Q;
  Q.push(this);

  while (!Q.empty())
  {
    BstNode *current = Q.front();
    if (current->left)
    {
      Q.push(current->left);
    }
    if (current->right)
    {
      Q.push(current->right);
    }
    std::cout << current->data << ' ';
    Q.pop();
  }
  return;
}

void BstNode::PreOrder()
{
  std::cout << data << ' ';
  if (left)
  {
    left->PreOrder();
  }
  if (right)
  {
    right->PreOrder();
  }
  return;
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

void BstNode::PostOrder()
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