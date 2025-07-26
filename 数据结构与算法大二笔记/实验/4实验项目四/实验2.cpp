#include <iostream>
#include <queue>

int main() {
  int n, m;
  std::cout << "请输入两个队列的元素个数 n 和 m（例如：3 4）：" << std::endl;
  std::cin >> n >> m;

  std::queue<int> Q1, Q2, Q3;

  std::cout << "请输入队列 Q1 的 " << n << " 个整数元素（以空格分隔）：" << std::endl;
  for (int i = 0; i < n; i++) {
    int element;
    std::cin >> element;
    Q1.push(element);
  }

  std::cout << "请输入队列 Q2 的 " << m << " 个整数元素（以空格分隔）：" << std::endl;
  for (int i = 0; i < m; i++) {
    int element;
    std::cin >> element;
    Q2.push(element);
  }

  // 将 Q1 的元素加入 Q3
  while (!Q1.empty()) {
    Q3.push(Q1.front());
    Q1.pop();
  }

  // 将 Q2 的元素加入 Q3
  while (!Q2.empty()) {
    Q3.push(Q2.front());
    Q2.pop();
  }

  std::cout << "合并后的队列元素为：" << std::endl;
  while (!Q3.empty()) {
    std::cout << Q3.front() << " ";
    Q3.pop();
  }
  std::cout << std::endl;

  return 0;
}
