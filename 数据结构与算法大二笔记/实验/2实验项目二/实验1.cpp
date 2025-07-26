#include <iostream>

struct Node
{
  int data;
  Node* next;
};

Node* CreateList(const int n);
void PrintList(Node* const head);
void FindMaxNode(Node* const head);

int main() {
  int n;
  std::cout << "请输入链表的节点数: ";
  std::cin >> n;
  Node* head = CreateList(n);
  std::cout << "\n所有节点的数据如下: " << std::endl;
  PrintList(head);
  std::cout << "\n查找最大值节点: " << std::endl;
  FindMaxNode(head);
  return 0;
}

Node* CreateList(const int n)
{
  if (n <= 0) return nullptr;
  Node* head = nullptr; //头指针
  Node* tail = nullptr; //尾指针
  for (int i = 0; i < n; i++) {
    int data;
    std::cout << "请输入第 " << i + 1 << " 个节点的值: ";
    std::cin >> data;

    Node* NewNode = new Node{data, nullptr};
    if (!head) { //head == nullptr
      head = tail = NewNode;
      continue;
    } else {
      tail->next = NewNode;
      tail = tail->next;
    }
  }
  return head;
}

void PrintList(Node* const head) {
  if (!head) {
    std::cerr << "[ERROR] 空表无法打印" << std::endl;
    return;
  }
  Node* current = head;
  std::cout << "链表：";
  while(current != nullptr)
  {
    std::cout << current->data << " ";
    current = current->next;
  }
  std::cout << std::endl;
  return;
}

void FindMaxNode(Node* const head){
  if (!head) {
    std::cerr << "[ERROR] 空表不存在最大节点" << std::endl;
    return;
  }
  Node* current = head;
  int max = current->data;
  int i = 1;
  int n = i;
  while (current) {
    if (current->data > max) {
      max = current->data;
      n = i;
    }
    current = current->next;
    i++;
  }
  std::cout << "最大的节点是第 " << n << " 个节点，值为 " << max << std::endl;
}