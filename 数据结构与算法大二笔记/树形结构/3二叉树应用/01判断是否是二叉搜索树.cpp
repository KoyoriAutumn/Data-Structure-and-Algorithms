#include <iostream>
#include <queue>
#include <vector>

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
  void PreOrder();
  void InOrder();
  void PostOrder();

  void BTInsert(int val);
  std::vector<int> Vec;
  void InOrderVector(std::vector<int>& Vect); // 这个函数是IsBST()的辅助函数，不应当在主函数中调用它。
  bool IsBST();
};

int main()
{
  // 构造根节点
  BstNode *tree1 = new BstNode(30);
  int values[] = {15, 7, 3, 20, 5, 10};

  // 层序插入
  for (int v : values)
  {
    tree1->BTInsert(v);
  }

  // 检测并打印结果
  std::cout << "After BTInsert, tree1 IsBST()? "
            << (tree1->IsBST() ? "Yes" : "No") << std::endl;

  // 直接遍历 tree1->Vec 并打印
  std::cout << "tree1 Vec (in-order): [ ";
  for (size_t i = 0; i < tree1->Vec.size(); ++i)
  {
    std::cout << tree1->Vec[i]
              << (i + 1 < tree1->Vec.size() ? " " : " ");
  }
  std::cout << "]\n\n";

  // 第二棵树，用 BST 插入
  BstNode *tree2 = new BstNode(30);
  for (int v : values)
  {
    tree2->Insert(v);
  }

  std::cout << "After Insert, tree2 IsBST()? "
            << (tree2->IsBST() ? "Yes" : "No") << std::endl;

  std::cout << "tree2 Vec (in-order): [ ";
  for (size_t i = 0; i < tree2->Vec.size(); ++i)
  {
    std::cout << tree2->Vec[i]
              << (i + 1 < tree2->Vec.size() ? " " : " ");
  }
  std::cout << "]\n\n";

  // 再次用中序遍历打印，验证顺序
  std::cout << "Tree1 InOrder: ";
  tree1->InOrder();
  std::cout << "\nTree2 InOrder: ";
  tree2->InOrder();
  std::cout << std::endl;

  // 释放
  delete tree1;
  delete tree2;
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

void BstNode::BTInsert(int val)
{
  // 采用层序遍历的逻辑
  std::queue<BstNode *> Q;
  Q.push(this);

  while (!Q.empty())
  {
    BstNode *current = Q.front();
    if (current->left)
    {
      Q.push(current->left);
    }
    else
    {
      current->left = new BstNode(val);
      return;
    }
    if (current->right)
    {
      Q.push(current->right);
    }
    else
    {
      current->right = new BstNode(val);
      return;
    }
    Q.pop();
  }
  return;
}

void BstNode::InOrderVector(std::vector<int>& Vect)
{
  if (left)
  {
    left->InOrderVector(Vect);
  }
  Vect.push_back(data);
  if (right)
  {
    right->InOrderVector(Vect);
  }
  return;
}

bool BstNode::IsBST()
{
  Vec.clear();
  InOrderVector(Vec);
  for (int i = 0; i < Vec.size() - 1; i++)
  {
    if (Vec[i] > Vec[i + 1])
    {
      return false;
    }
  }
  return true;
}