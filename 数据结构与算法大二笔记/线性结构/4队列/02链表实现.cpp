#include <iostream>

struct Node
{
  int data;
  Node *next;
};

class Queue
{
private:
  Node *front;
  Node *rear;

public:
  Queue();
  bool IsEmpty();
  void EnQueue(int n);
  void DeQueue();
  int Front();
  void Print();
};

int main()
{
  Queue q;

  std::cout << "��ʼ����: ";
  q.Print();

  std::cout << "\n=== ��Ӳ��� ===" << std::endl;
  for (int i = 1; i <= 5; ++i)
  {
    int val = i * 100;
    std::cout << "EnQueue(" << val << ")" << std::endl;
    q.EnQueue(val);
    std::cout << "��ǰ����: ";
    q.Print();
  }

  std::cout << "\n=== ���Ӳ���ȡ��ͷ ===" << std::endl;
  while (!q.IsEmpty())
  {
    std::cout << "Front() = " << q.Front() << std::endl;
    std::cout << "DeQueue()" << std::endl;
    q.DeQueue();
    std::cout << "��ǰ����: ";
    q.Print();
  }

  std::cout << "\n=== �ն��в������� ===" << std::endl;
  q.DeQueue(); // ������ʾ
  q.Print();   // ������ʾ
  int f = q.Front();
  std::cout << "Returned Front() = " << f << std::endl;

  std::cout << "\n=== �ٴ���� ===" << std::endl;
  q.EnQueue(999);
  std::cout << "EnQueue(999)�����: ";
  q.Print();
  std::cout << "Front() = " << q.Front() << std::endl;

  return 0;
}

Queue::Queue()
{
  front = nullptr;
  rear = nullptr;
}

bool Queue::IsEmpty()
{
  return (!front);
}

void Queue::EnQueue(int n)
{
  Node *temp = new Node;
  temp->data = n;
  temp->next = nullptr;
  if (IsEmpty())
  {
    front = temp;
    rear = temp;
  }
  else
  {
    rear->next = temp;
    rear = temp;
  }
  return;
}

void Queue::DeQueue()
{
  if (IsEmpty())
  {
    std::cerr << "[ERROR] �ձ��޷�ɾ������" << std::endl;
    return;
  }
  else if (front == rear)
  {
    Node *temp = front;
    front = nullptr;
    rear = nullptr;
    delete temp;
  }
  else
  {
    Node *temp = front;
    front = front->next;
    delete temp;
    return;
  }
}

int Queue::Front()
{
  if (IsEmpty())
  {
    std::cerr << "[ERROR] �ձ��������ݣ�������0" << std::endl;
    return 0;
  }
  else
  {
    return front->data;
  }
}

void Queue::Print()
{
  if (IsEmpty())
  {
    std::cerr << "[ERROR] �ձ��޷���ӡ" << std::endl;
    return;
  }
  Node *temp = front;
  while (temp)
  {
    std::cout << temp->data << ' ';
    temp = temp->next;
  }
  std::cout << std::endl;
  return;
}