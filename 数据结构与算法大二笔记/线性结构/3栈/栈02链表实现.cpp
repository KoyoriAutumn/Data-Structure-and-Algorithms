#include <iostream>

/* ����ʵ��ջ */
struct Node
{
  int data;
  Node* next = nullptr;
};

/* ջ�Ĺ��� */
void Push(Node*& top, int x);
void Pop(Node*& top);
int Top(Node* top);
bool IsEmpty(Node* top);

void Print(Node* top);
Node* InitializeStack();

int main()
{
  Node* A = InitializeStack();

  /* ������� */
  Push(A, 0);
  Push(A, 1);
  Push(A, 5);
  Print(A);

  /* Top�������� */
  std::cout << Top(A) <<std::endl;

  /* �������� */
  Pop(A);
  Pop(A);
  Print(A);

  /* �ձ������� */
  Pop(A);
  Print(A);
  Pop(A);
  std::cout << Top(A) <<std::endl;

  return 0;
}

void Push(Node*& top, int data)
{
  /* ����topΪ�ջ��ǲ�Ϊ�գ����ﶼ������ */
  Node* NewNode = new Node{data, top};
  top = NewNode;
  return;
}

void Pop(Node*& top)
{
  if (!top)
  {
    std::cerr << "[ERROR] ��ջ�޷���������" << std::endl;
    return;
  }

  Node* newtop = top->next;
  delete top;
  top = newtop;
  return;
}

int Top(Node* top)
{
  if (!top)
  {
    std::cerr << "[ERROR] ��ջ������ջ��, �����0" << std::endl;
    return 0;
  }
  return top->data;
}

bool IsEmpty(Node* top)
{
  if (top) return false;
  return true;
}

Node* InitializeStack()
{
  return nullptr;
}

void Print(Node* top)
{
  if (IsEmpty(top)) {
    std::cerr << "[ERROR] �ձ��ɴ�ӡ" << std::endl;
    return;
  }

  Node* current = top;
  std::cout << "����\n";
  while(current->next != nullptr)
  {
    std::cout << current->data << std::endl;
    current = current->next;
  }
  std::cout << current->data << std::endl;
  return;
}