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
  �������Ĳ��������
  �������б������ȱ���Lv0��Ҷ�ӽڵ㣬�ٱ���Lv1��Ҷ�ӽڵ㣬�Դ����ơ�
  ˼·�ǣ���ÿ��Ľڵ���ڶ��е��У�
  Ȼ����г��ӣ�ȡ���ڵ㣩����ӣ�������һ��Ľڵ㣩�Ĳ�����
  �Դ˴ﵽ������Ŀ�ġ�
  */
  void LevelOrder();
};

int main()
{
  // 1. �������ڵ�
  BstNode *root = new BstNode(8);

  // 2. �� BST �в���һ���������
  int vals[] = {3, 10, 1, 6, 14, 4, 7, 13};
  for (int v : vals)
  {
    root->Insert(v);
  }

  // 3. ���� LevelOrder ����
  std::cout << "Level-order traversal: ";
  root->LevelOrder(); // ����δ�ӡ��ÿ���ڵ����һ���ո�
  std::cout << std::endl;

  // 4. �ͷ��������нڵ�
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