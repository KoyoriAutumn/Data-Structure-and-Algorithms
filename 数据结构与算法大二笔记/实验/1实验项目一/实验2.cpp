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
  std::cout << "请输入 " << n << " 个互不相等的整数: ";
  for (int i = 0; i < n; i++) {
    std::cin >> L.data[i];
  }
}

void Move(SqList &L) {
  int i = 0, j = L.len - 1;
  while (i < j) {
    while (i < j && (L.data[i] & 1) == 0) i++; //位运算
    while (i < j && (L.data[j] & 1) == 1) j--;

    if (i < j) { //条件判断是必要的，能减小时间复杂度
      std::swap(L.data[i], L.data[j]);
    }
  }
  std::cout << "现在表为:\n";
  for (int i = 0; i < L.len; i++) {
    std::cout << L.data[i] << " ";
  }
  std::cout << std::endl;
}