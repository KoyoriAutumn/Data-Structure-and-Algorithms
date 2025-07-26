#include <iostream>

struct Student
{
  std::string name;
  float score;
  Student* next;
};

Student* CreateList(const int n);
void PrintList(Student* const head);
Student* Delete_Low_Score_Students(Student* head);

int main() {
  int n;
  std::cout << "������ѧ������: ";
  std::cin >> n;
  Student* head = CreateList(n);
  std::cout << "\n����ѧ���ĳɼ���Ϣ����: " << std::endl;
  PrintList(head);
  std::cout << "\nɾ���ɼ�����60�ֵ�ѧ����, ʣ��ѧ����Ϣ: " << std::endl;
  head = Delete_Low_Score_Students(head);
  PrintList(head);
  return 0;
}

Student* CreateList(const int n)
{
  if (n <= 0) return nullptr;
  Student* head = nullptr; //ͷָ��
  Student* tail = nullptr; //βָ��
  for (int i = 0; i < n; i++) {
    std::string name;
    std::cout << "������� " << i + 1 << " ��ѧ��������: ";
    std::cin >> name;

    float score;
    std::cout << "������" << name << "�ĳɼ�: ";
    std::cin >> score;

    Student* NewStudent = new Student{name, score, nullptr};
    if (!head) { //head == nullptr
      head = tail = NewStudent;
      continue;
    } else {
      tail->next = NewStudent;
      tail = tail->next;
    }
  }
  return head;
}

void PrintList(Student* const head) {
  if (!head) {
    std::cerr << "[ERROR] �ձ��޷���ӡ" << std::endl;
    return;
  }
  Student* current = head;
  std::cout << "����\t����\n";
  while(current)
  {
    std::cout << current->name << "\t" << current->score << std::endl;
    current = current->next;
  }
  std::cout << std::endl;
  return;
}

Student* Delete_Low_Score_Students(Student* head) {
  if (!head) return head;

  Student* before = head;
  Student* current = before->next;

  while(current) {
    if (current->score >= 60) {
      before = current;
      current = before->next;
    } else {
      before->next = current->next;
      Student* temp = current;
      current = current->next;
      delete temp;
    }
  }

  /* ������һ���ڵ� */
  current = head;
  if (current->score < 60) {
    head = current->next;
    delete current;
  }
  return head;
}