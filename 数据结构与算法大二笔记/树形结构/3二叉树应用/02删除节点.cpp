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
  void InOrderVector(std::vector<int> &Vect); // 这个函数是IsBST()的辅助函数，不应当在主函数中调用它。
  bool IsBST();

  BstNode *Delete(int val);
};

int main()
{
  // 1. 构造一棵 BST
  BstNode *root = new BstNode(50);
  int values_to_insert[] = {30, 70, 20, 40, 60, 80, 65};
  for (int v : values_to_insert)
  {
    root->Insert(v);
  }

  // 2. 初始中序遍历（应当是升序）
  std::cout << "插入完成后，中序遍历：";
  root->InOrder();
  std::cout << std::endl;

  // 3. 删除叶子节点：20
  std::cout << "删除叶子节点 20 之前，中序遍历：";
  root->InOrder();
  std::cout << std::endl;
  root = root->Delete(20);
  std::cout << "删除叶子节点 20 之后，中序遍历：";
  root->InOrder();
  std::cout << std::endl
            << std::endl;

  // 4. 删除只有一个子节点的节点：60 （它只有右子节点 65）
  std::cout << "删除只有一个子节点的节点 60 之前，中序遍历：";
  root->InOrder();
  std::cout << std::endl;
  root = root->Delete(60);
  std::cout << "删除只有一个子节点的节点 60 之后，中序遍历：";
  root->InOrder();
  std::cout << std::endl
            << std::endl;

  // 5. 删除有两个子节点的节点：30 （它的子节点 40 和 20/已被删后 40）
  std::cout << "删除有两个子节点的节点 30 之前，中序遍历：";
  root->InOrder();
  std::cout << std::endl;
  root = root->Delete(30);
  std::cout << "删除有两个子节点的节点 30 之后，中序遍历：";
  root->InOrder();
  std::cout << std::endl
            << std::endl;

  // 6. 最终的层序遍历查看整体结构
  std::cout << "最终层序遍历（LevelOrder）：";
  root->LevelOrder();
  std::cout << std::endl;

  // 7. 清理内存
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

void BstNode::InOrderVector(std::vector<int> &Vect)
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

BstNode *BstNode::Delete(int val)
{
  if (!this)
  {
    return nullptr;
  }
  if (val < data)
  {
    left = left->Delete(val);
    return this;
  }
  else if (val > data)
  {
    right = right->Delete(val);
    return this;
  }
  else if (val == data)
  {
    if (!left && !right)
    {
      delete this;
      return nullptr;
    }
    else if (!left)
    {
      BstNode *temp = right;
      left = right = nullptr;
      delete this;
      return temp;
    }
    else if (!right)
    {
      BstNode *temp = left;
      left = right = nullptr;
      delete this;
      return temp;
    }
    else
    {
      data = right->FindMin();
      right = right->Delete(data);
      return this;
    }
  }
  return this;
}