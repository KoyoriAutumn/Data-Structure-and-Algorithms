#include <iostream>

#define MAXSIZE 100

/* ջ�Ľṹ�嶨�� */
struct Stack {
  int data[MAXSIZE]; //����ʵ��ջ
  int top = -1; //ջ����ֵΪ-1��ʾ��ջ
};

/* ջ�Ĺ��� */
void Push(Stack &L, int x);
void Pop(Stack &L);
int Top(const Stack &L);
bool IsEmpty(const Stack &L);

void Print(const Stack &L); //�ⲻ��ջ����Ҫʵ�ֵĹ���

int main() {
  Stack A;

  /* ������� */
  Push(A, 0);
  Push(A, 1);
  Push(A, 5);
  Print(A);

  /* �������� */
  Pop(A);
  Pop(A);
  Print(A);

  /* �ձ������� */
  Pop(A);
  Print(A);
  Pop(A);

  /* ��ջ������� */
  for (int i = 0; i < MAXSIZE; i++) {
    Push(A, i);
  }
  Push(A, 100);
  Print(A);
  return 0;
}

void Push(Stack &L, int x) {
  /* ջ�����Ĵ�����ʾ */
  if (L.top == MAXSIZE - 1) {
    std::cerr << "[ERROR] ��ջ���" << std::endl;
    return;
  }

  /* ջ��+1��Ȼ����������ջ�� */
  L.data[++L.top] = x;
  return;
}

void Pop(Stack &L) {
/* ��ջ�޷��������� */
  if (L.top == -1) {
    std::cerr << "[ERROR] ��ջ�޷���������" << std::endl;
    return;
  }

  /* topֱ�Ӽ�һ��ԭ�������ݲ��ù��ģ��Ḳ�ǵ� */
  L.top--;
}

int Top(const Stack &L)
{
  return L.top;
}

bool IsEmpty(const Stack &L)
{
  /* ֵΪ-1��ʾ��ջ */
  if (L.top == -1) {
    return true;
  }

  return false;
}

void Print(const Stack &L) {
  /* �ձ��ɴ�ӡ */
  if (IsEmpty(L)) {
    std::cerr << "[ERROR] �ձ��ɴ�ӡ" << std::endl;
    return;
  }

  for (int i = 0; i <= L.top; i++) {
    std::cout << L.data[i] << " ";
  }
  std::cout << std::endl;
  return;
}
