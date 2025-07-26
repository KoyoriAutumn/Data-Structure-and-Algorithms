#include <iostream>

/* 链表实现栈 */
struct Node
{
  int data;
  Node* next = nullptr;
};

/* 栈的功能 */
void Push(Node*& top, int x);
void Pop(Node*& top);
int Top(Node* top);
bool IsEmpty(Node* top);

void Print(Node* top);
Node* InitializeStack();

int main()
{
  Node* A = InitializeStack();

  /* 推入测试 */
  Push(A, 0);
  Push(A, 1);
  Push(A, 5);
  Print(A);

  /* Top函数测试 */
  std::cout << Top(A) <<std::endl;

  /* 弹出测试 */
  Pop(A);
  Pop(A);
  Print(A);

  /* 空表弹出测试 */
  Pop(A);
  Print(A);
  Pop(A);
  std::cout << Top(A) <<std::endl;

  return 0;
}

void Push(Node*& top, int data)
{
  /* 不论top为空还是不为空，这里都能运行 */
  Node* NewNode = new Node{data, top};
  top = NewNode;
  return;
}

void Pop(Node*& top)
{
  if (!top)
  {
    std::cerr << "[ERROR] 空栈无法弹出数据" << std::endl;
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
    std::cerr << "[ERROR] 空栈不存在栈顶, 将输出0" << std::endl;
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
    std::cerr << "[ERROR] 空表不可打印" << std::endl;
    return;
  }

  Node* current = top;
  std::cout << "链表：\n";
  while(current->next != nullptr)
  {
    std::cout << current->data << std::endl;
    current = current->next;
  }
  std::cout << current->data << std::endl;
  return;
}