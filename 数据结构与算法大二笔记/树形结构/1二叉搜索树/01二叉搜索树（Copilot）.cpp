#include <iostream>

struct Node
{
  int data;
  Node *left;
  Node *right;
  Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void Insert(Node *&root, int data);
bool Search(Node *root, int data);

int main()
{
  Node *root = nullptr;

  // ������������в���ڵ�
  Insert(root, 50);
  Insert(root, 30);
  Insert(root, 70);
  Insert(root, 20);
  Insert(root, 40);
  Insert(root, 60);
  Insert(root, 80);

  // �ڶ����������в��ҽڵ�
  if (Search(root, 40))
    std::cout << "Found" << std::endl; // Ӧ����� "Found"
  else
    std::cout << "Not Found" << std::endl;

  if (Search(root, 25))
    std::cout << "Found" << std::endl; // Ӧ����� "Not Found"
  else
    std::cout << "Not Found" << std::endl;

  return 0;
}

void Insert(Node *&root, int data)
{
  if (root == nullptr)
  {
    root = new Node(data);
  }
  else if (data < root->data)
  {
    Insert(root->left, data);
  }
  else
  {
    Insert(root->right, data);
  }
}

bool Search(Node *root, int data)
{
  if (root == nullptr)
  {
    return false;
  }
  if (root->data == data)
  {
    return true;
  }
  else if (data < root->data)
  {
    return Search(root->left, data);
  }
  else
  {
    return Search(root->right, data);
  }
}