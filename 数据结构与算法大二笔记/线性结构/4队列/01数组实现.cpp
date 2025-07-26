#include <iostream>

#define MAX_SIZE 5

class Queue
{
private:
  int A[MAX_SIZE];
  int front, rear;

public:
  Queue()
  {
    front = -1;
    rear = -1;
  }

  bool IsEmpty()
  {
    return (front == -1 && rear == -1);
  }

  bool IsFull()
  {
    /*
    return (rear == front - 1 || (rear == MAX_SIZE - 1 && front == 0));
    ˼·��
    rear == front - 1
    rear + 1 == front
    (rear + 1) % MAX_SIZE == front
    ԭ����ʽ�ӣ������һ��������ұ����������������ͼ���������⡣
    */
    return (rear + 1) % MAX_SIZE == front;
  }

  void EnQueue(int n)
  {
    if (IsEmpty())
    {
      front = 0;
      rear = 0;
      A[rear] = n;
      return;
    }
    else if (!IsEmpty() && !IsFull())
    {
      rear++;
      rear %= MAX_SIZE;
      A[rear] = n;
      return;
    }
    else if (IsFull())
    {
      std::cerr << "[ERROR] ��������" << std::endl;
    }
    else
      std::cerr << "[ERROR] EnQueue��������δ֪����" << std::endl;
  }

  void DeQueue()
  {
    if (IsEmpty())
    {
      std::cerr << "[ERROR] �ձ��޷�ɾ������" << std::endl;
    }
    else if (!IsEmpty() && (front == rear))
    {
      front = -1;
      rear = -1;
      return;
    }
    else if (!IsEmpty())
    {
      front++;
      front %= MAX_SIZE;
      return;
    }
    else
    {
      std::cerr << "[ERROR] DeQueue��������δ֪����" << std::endl;
    }
  }

  int Front()
  {
    if (IsEmpty())
    {
      std::cerr << "[ERROR] �ձ��������ݣ�������0" << std::endl;
      return 0;
    }
    else if (!IsEmpty())
    {
      return A[front];
    }
    else
    {
      std::cerr << "[ERROR] Front��������δ֪���󣬽�����0" << std::endl;
      return 0;
    }
  }

  void Print()
  {
    if (IsEmpty())
    {
      std::cerr << "[ERROR] �ձ��޷���ӡ" << std::endl;
    }
    else if (!IsEmpty())
    {
      if (front < rear)
      {
        for (int i = front; i <= rear; i++)
        {
          std::cout << A[i] << ' ';
        }
        std::cout << std::endl;
      }
      else if (front == rear)
      {
        std::cout << A[front] << std::endl;
      }
      else if (front > rear)
      {
        for (int i = front; i < MAX_SIZE; i++)
        {
          std::cout << A[i] << ' ';
        }
        for (int i = 0; i <= rear; i++)
        {
          std::cout << A[i] << ' ';
        }
        std::cout << std::endl;
      }
    }
    else
      std::cerr << "[ERROR] Print��������δ֪����" << std::endl;
  }
};

int main()
{
  Queue q;
  std::cout << "Enqueue 1 �� " << MAX_SIZE << ":\n";
  for (int i = 1; i <= MAX_SIZE; ++i)
  {
    q.EnQueue(i);
  }
  q.Print();

  std::cout << "\n���� EnQueue һ�����Ԫ�� (6):\n";
  q.EnQueue(6);

  std::cout << "\n��ǰ��ͷԪ��: " << q.Front() << "\n";

  std::cout << "\nDeQueue ����Ԫ�غ�: \n";
  q.DeQueue();
  q.DeQueue();
  q.Print();

  std::cout << "\nEnQueue 6 �� 7: \n";
  q.EnQueue(6);
  q.EnQueue(7);
  q.Print();

  std::cout << "\nDeQueue ����Ԫ��: \n";
  while (!q.IsEmpty())
  {
    std::cout << q.Front() << ' ';
    q.DeQueue();
  }
  std::cout << std::endl;

  std::cout << "\n���Դӿն��� DeQueue: \n";
  q.DeQueue();

  return 0;
}