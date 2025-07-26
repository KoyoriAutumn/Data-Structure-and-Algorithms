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
  std::cout << "����������Ľڵ���: ";
  std::cin >> n;
  Node* head = CreateList(n);
  std::cout << "\n���нڵ����������: " << std::endl;
  PrintList(head);
  std::cout << "\n�������ֵ�ڵ�: " << std::endl;
  FindMaxNode(head);
  return 0;
}

Node* CreateList(const int n)
{
  if (n <= 0) return nullptr;
  Node* head = nullptr; //ͷָ��
  Node* tail = nullptr; //βָ��
  for (int i = 0; i < n; i++) {
    int data;
    std::cout << "������� " << i + 1 << " ���ڵ��ֵ: ";
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
    std::cerr << "[ERROR] �ձ��޷���ӡ" << std::endl;
    return;
  }
  Node* current = head;
  std::cout << "����";
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
    std::cerr << "[ERROR] �ձ��������ڵ�" << std::endl;
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
  std::cout << "���Ľڵ��ǵ� " << n << " ���ڵ㣬ֵΪ " << max << std::endl;
}