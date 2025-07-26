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
  void InOrderVector(std::vector<int>& Vect); // ���������IsBST()�ĸ�����������Ӧ�����������е�������
  bool IsBST();
};

int main()
{
  // ������ڵ�
  BstNode *tree1 = new BstNode(30);
  int values[] = {15, 7, 3, 20, 5, 10};

  // �������
  for (int v : values)
  {
    tree1->BTInsert(v);
  }

  // ��Ⲣ��ӡ���
  std::cout << "After BTInsert, tree1 IsBST()? "
            << (tree1->IsBST() ? "Yes" : "No") << std::endl;

  // ֱ�ӱ��� tree1->Vec ����ӡ
  std::cout << "tree1 Vec (in-order): [ ";
  for (size_t i = 0; i < tree1->Vec.size(); ++i)
  {
    std::cout << tree1->Vec[i]
              << (i + 1 < tree1->Vec.size() ? " " : " ");
  }
  std::cout << "]\n\n";

  // �ڶ��������� BST ����
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

  // �ٴ������������ӡ����֤˳��
  std::cout << "Tree1 InOrder: ";
  tree1->InOrder();
  std::cout << "\nTree2 InOrder: ";
  tree2->InOrder();
  std::cout << std::endl;

  // �ͷ�
  delete tree1;
  delete tree2;
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
  // ���ò���������߼�
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