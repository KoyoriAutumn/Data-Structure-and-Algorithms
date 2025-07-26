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
  std::cout << "请输入学生人数: ";
  std::cin >> n;
  Student* head = CreateList(n);
  std::cout << "\n所有学生的成绩信息如下: " << std::endl;
  PrintList(head);
  std::cout << "\n删除成绩低于60分的学生后, 剩余学生信息: " << std::endl;
  head = Delete_Low_Score_Students(head);
  PrintList(head);
  return 0;
}

Student* CreateList(const int n)
{
  if (n <= 0) return nullptr;
  Student* head = nullptr; //头指针
  Student* tail = nullptr; //尾指针
  for (int i = 0; i < n; i++) {
    std::string name;
    std::cout << "请输入第 " << i + 1 << " 个学生的姓名: ";
    std::cin >> name;

    float score;
    std::cout << "请输入" << name << "的成绩: ";
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
    std::cerr << "[ERROR] 空表无法打印" << std::endl;
    return;
  }
  Student* current = head;
  std::cout << "姓名\t分数\n";
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

  /* 最后处理第一个节点 */
  current = head;
  if (current->score < 60) {
    head = current->next;
    delete current;
  }
  return head;
}