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

  std::cout << "初始队列: ";
  q.Print();

  std::cout << "\n=== 入队测试 ===" << std::endl;
  for (int i = 1; i <= 5; ++i)
  {
    int val = i * 100;
    std::cout << "EnQueue(" << val << ")" << std::endl;
    q.EnQueue(val);
    std::cout << "当前队列: ";
    q.Print();
  }

  std::cout << "\n=== 出队并获取队头 ===" << std::endl;
  while (!q.IsEmpty())
  {
    std::cout << "Front() = " << q.Front() << std::endl;
    std::cout << "DeQueue()" << std::endl;
    q.DeQueue();
    std::cout << "当前队列: ";
    q.Print();
  }

  std::cout << "\n=== 空队列操作测试 ===" << std::endl;
  q.DeQueue(); // 错误提示
  q.Print();   // 错误提示
  int f = q.Front();
  std::cout << "Returned Front() = " << f << std::endl;

  std::cout << "\n=== 再次入队 ===" << std::endl;
  q.EnQueue(999);
  std::cout << "EnQueue(999)后队列: ";
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
    std::cerr << "[ERROR] 空表无法删除数据" << std::endl;
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
    std::cerr << "[ERROR] 空表不存在数据，将返回0" << std::endl;
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
    std::cerr << "[ERROR] 空表无法打印" << std::endl;
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