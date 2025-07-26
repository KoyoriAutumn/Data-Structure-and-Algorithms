#include <iostream>

#define MAXSIZE 100

/* 栈的结构体定义 */
struct Stack {
  int data[MAXSIZE]; //数组实现栈
  int top = -1; //栈顶：值为-1表示空栈
};

/* 栈的功能 */
void Push(Stack &L, int x);
void Pop(Stack &L);
int Top(const Stack &L);
bool IsEmpty(const Stack &L);

void Print(const Stack &L); //这不是栈必须要实现的功能

int main() {
  Stack A;

  /* 推入测试 */
  Push(A, 0);
  Push(A, 1);
  Push(A, 5);
  Print(A);

  /* 弹出测试 */
  Pop(A);
  Pop(A);
  Print(A);

  /* 空表弹出测试 */
  Pop(A);
  Print(A);
  Pop(A);

  /* 堆栈溢出测试 */
  for (int i = 0; i < MAXSIZE; i++) {
    Push(A, i);
  }
  Push(A, 100);
  Print(A);
  return 0;
}

void Push(Stack &L, int x) {
  /* 栈已满的错误提示 */
  if (L.top == MAXSIZE - 1) {
    std::cerr << "[ERROR] 堆栈溢出" << std::endl;
    return;
  }

  /* 栈顶+1，然后数据推入栈顶 */
  L.data[++L.top] = x;
  return;
}

void Pop(Stack &L) {
/* 空栈无法弹出数据 */
  if (L.top == -1) {
    std::cerr << "[ERROR] 空栈无法弹出数据" << std::endl;
    return;
  }

  /* top直接减一，原来的数据不用关心，会覆盖掉 */
  L.top--;
}

int Top(const Stack &L)
{
  return L.top;
}

bool IsEmpty(const Stack &L)
{
  /* 值为-1表示空栈 */
  if (L.top == -1) {
    return true;
  }

  return false;
}

void Print(const Stack &L) {
  /* 空表不可打印 */
  if (IsEmpty(L)) {
    std::cerr << "[ERROR] 空表不可打印" << std::endl;
    return;
  }

  for (int i = 0; i <= L.top; i++) {
    std::cout << L.data[i] << " ";
  }
  std::cout << std::endl;
  return;
}
