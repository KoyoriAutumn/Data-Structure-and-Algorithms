#include <iostream>

#define MAXSIZE 100

struct SqList {
  int data[MAXSIZE];
  int len;
};

void InitList(SqList &L, std::string name);
void Move(SqList &L);

int main() {
  SqList A, B, C;
  InitList(A, "A");
  Move(A);
  return 0;
}

void InitList(SqList &L, std::string name) {
  /* Ԫ�ظ������� */
  std::cout << "������˳��� " << name << " ��Ԫ��:\n";
  std::cout << "������Ԫ�ظ���: ";
  int n;
  std::cin >> n;

  /* Ԫ�ظ������Ϸ���ֱ����ֹ���� */
  if (n > MAXSIZE || n < 0) exit(1);

  L.len = n;
  if (n == 0) return;

  /* �������Ԫ�� */
  std::cout << "������ " << n << " ��������ȵ�����: ";
  for (int i = 0; i < n; i++) {
    std::cin >> L.data[i];
  }
}

void Move(SqList &L) {
  int i = 0, j = L.len - 1;
  while (i < j) {
    while (i < j && (L.data[i] & 1) == 0) i++; //λ����
    while (i < j && (L.data[j] & 1) == 1) j--;

    if (i < j) { //�����ж��Ǳ�Ҫ�ģ��ܼ�Сʱ�临�Ӷ�
      std::swap(L.data[i], L.data[j]);
    }
  }
  std::cout << "���ڱ�Ϊ:\n";
  for (int i = 0; i < L.len; i++) {
    std::cout << L.data[i] << " ";
  }
  std::cout << std::endl;
}