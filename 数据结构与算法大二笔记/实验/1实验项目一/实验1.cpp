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
  /* 元素个数输入 */
  std::cout << "请输入顺序表 " << name << " 的元素:\n";
  std::cout << "请输入元素个数: ";
  int n;
  std::cin >> n;

  /* 元素个数不合法就直接终止运行 */
  if (n > MAXSIZE || n < 0) exit(1);

  L.len = n;
  if (n == 0) return;

  /* 逐个输入元素 */
  std::cout << "请输入 " << n << " 个按递增排序的元素: ";
  for (int i = 0; i < n; i++) {
    std::cin >> L.data[i];
  }

  /* 不是递增输入就直接终止运行 */
  for (int i = 0; i < n-1; i++) {
    if(L.data[i] > L.data[i+1]) exit(1);
  }
}

/* 列表A和列表B合成列表C */
void MergeList(SqList &C, const SqList &A, const SqList &B, std::string name) {
  C.len = A.len + B.len; //长度设定
  int i = 0, j = 0, k = 0;
  while (k < C.len) {
    /* 情况一 */
    if (i < A.len && j < B.len) {
      if (A.data[i] < B.data[j]) {
        C.data[k++] = A.data[i++];
      } else {
        C.data[k++] = B.data[j++];
      }
    }

    /* 情况二 */
    if (i >= A.len && j < B.len) C.data[k++] = B.data[j++];

    /* 情况三 */
    if (i < A.len && j >= B.len) C.data[k++] = A.data[i++];
  }
  std::cout << "合并后的顺序表 " << name << " 为: \n";
  for (int i = 0; i < C.len; i++) {
    std::cout << C.data[i] << " ";
  }
  std::cout << std::endl;
}