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

  /*
  二叉树的层序遍历：
  即逐层进行遍历，先遍历Lv0的叶子节点，再遍历Lv1的叶子节点，以此类推。
  思路是，将每层的节点存在队列当中，
  然后进行出队（取出节点）和入队（存入下一层的节点）的操作，
  以此达到遍历的目的。
  */
  void LevelOrder();
};

int main()
{
  // 1. 创建根节点
  BstNode *root = new BstNode(8);

  // 2. 向 BST 中插入一组测试数据
  int vals[] = {3, 10, 1, 6, 14, 4, 7, 13};
  for (int v : vals)
  {
    root->Insert(v);
  }

  // 3. 测试 LevelOrder 遍历
  std::cout << "Level-order traversal: ";
  root->LevelOrder(); // 按层次打印，每个节点后有一个空格
  std::cout << std::endl;

  // 4. 释放树的所有节点
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