#include <iostream>
#include <stack>

struct Node
{
  int data;
  Node* next = nullptr;
};

void Reverse(Node*& head);
void Insert(Node*& head, int data);
void Print(Node* head);

int main()
{
  Node* head = nullptr;
  Insert(head, 0);
  Insert(head, 1);
  Insert(head, 2);
  Insert(head, 3);
  Insert(head, 4);
  Insert(head, 5);
  Print(head);

  Reverse(head);
  Print(head);

  return 0;
}

void Reverse(Node*& head)
{
  std::stack<Node*> L;
  Node* current = head;
  while (current)
  {
    L.push(current);
    current = current->next;
  }

  current = head = L.top();
  L.pop();

  /* ������ջ������������Ϊ�㵽����������β�ڵ�ָ��nullptr����Ҫ��ô���������� */
  while (!L.empty())
  {
    current->next = L.top(); 
    current = current->next;
    L.pop();
  }
  current->next = nullptr;
  return;
}

void Insert(Node*& head, int data)
{
  Node* NewNode = new Node{data, nullptr};
  if(head == nullptr)
  {
    head = NewNode;
    return;
  }

  Node* current = head;
  while(current->next != nullptr)
  {
    current = current->next;
  }
  current->next = NewNode;
  return;
}

void Print(Node* head)
{
  Node* current = head;
  std::cout << "����";
  while(current != nullptr)
  {
    std::cout << current->data << " ";
    current = current->next;
  }
  std::cout << std::endl;
  return;
}