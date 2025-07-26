#include <iostream>
#include <queue>

int main() {
  int n, m;
  std::cout << "�������������е�Ԫ�ظ��� n �� m�����磺3 4����" << std::endl;
  std::cin >> n >> m;

  std::queue<int> Q1, Q2, Q3;

  std::cout << "��������� Q1 �� " << n << " ������Ԫ�أ��Կո�ָ�����" << std::endl;
  for (int i = 0; i < n; i++) {
    int element;
    std::cin >> element;
    Q1.push(element);
  }

  std::cout << "��������� Q2 �� " << m << " ������Ԫ�أ��Կո�ָ�����" << std::endl;
  for (int i = 0; i < m; i++) {
    int element;
    std::cin >> element;
    Q2.push(element);
  }

  // �� Q1 ��Ԫ�ؼ��� Q3
  while (!Q1.empty()) {
    Q3.push(Q1.front());
    Q1.pop();
  }

  // �� Q2 ��Ԫ�ؼ��� Q3
  while (!Q2.empty()) {
    Q3.push(Q2.front());
    Q2.pop();
  }

  std::cout << "�ϲ���Ķ���Ԫ��Ϊ��" << std::endl;
  while (!Q3.empty()) {
    std::cout << Q3.front() << " ";
    Q3.pop();
  }
  std::cout << std::endl;

  return 0;
}
