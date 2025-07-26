#include <iostream>

#define MAXSIZE 100

struct SqList {
  int data[MAXSIZE];
  int len;
};

void InitList(SqList &L, std::string name);
void MergeList(SqList &C, const SqList &A, const SqList &B, std::string name);

int main() {
  SqList A, B, C;
  InitList(A, "A");
  InitList(B, "B");
  MergeList(C, A, B, "C");
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
  std::cout << "������ " << n << " �������������Ԫ��: ";
  for (int i = 0; i < n; i++) {
    std::cin >> L.data[i];
  }

  /* ���ǵ��������ֱ����ֹ���� */
  for (int i = 0; i < n-1; i++) {
    if(L.data[i] > L.data[i+1]) exit(1);
  }
}

/* �б�A���б�B�ϳ��б�C */
void MergeList(SqList &C, const SqList &A, const SqList &B, std::string name) {
  C.len = A.len + B.len; //�����趨
  int i = 0, j = 0, k = 0;
  while (k < C.len) {
    /* ���һ */
    if (i < A.len && j < B.len) {
      if (A.data[i] < B.data[j]) {
        C.data[k++] = A.data[i++];
      } else {
        C.data[k++] = B.data[j++];
      }
    }

    /* ����� */
    if (i >= A.len && j < B.len) C.data[k++] = B.data[j++];

    /* ����� */
    if (i < A.len && j >= B.len) C.data[k++] = A.data[i++];
  }
  std::cout << "�ϲ����˳��� " << name << " Ϊ: \n";
  for (int i = 0; i < C.len; i++) {
    std::cout << C.data[i] << " ";
  }
  std::cout << std::endl;
}