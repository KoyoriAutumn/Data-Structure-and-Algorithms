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
    思路：
    rear == front - 1
    rear + 1 == front
    (rear + 1) % MAX_SIZE == front
    原来的式子，左边是一般情况，右边是特殊情况。画出图会更容易理解。
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
      std::cerr << "[ERROR] 队列已满" << std::endl;
    }
    else
      std::cerr << "[ERROR] EnQueue函数出现未知错误" << std::endl;
  }

  void DeQueue()
  {
    if (IsEmpty())
    {
      std::cerr << "[ERROR] 空表无法删除数据" << std::endl;
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
      std::cerr << "[ERROR] DeQueue函数出现未知错误" << std::endl;
    }
  }

  int Front()
  {
    if (IsEmpty())
    {
      std::cerr << "[ERROR] 空表不存在数据，将返回0" << std::endl;
      return 0;
    }
    else if (!IsEmpty())
    {
      return A[front];
    }
    else
    {
      std::cerr << "[ERROR] Front函数出现未知错误，将返回0" << std::endl;
      return 0;
    }
  }

  void Print()
  {
    if (IsEmpty())
    {
      std::cerr << "[ERROR] 空表无法打印" << std::endl;
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
      std::cerr << "[ERROR] Print函数出现未知错误" << std::endl;
  }
};

int main()
{
  Queue q;
  std::cout << "Enqueue 1 到 " << MAX_SIZE << ":\n";
  for (int i = 1; i <= MAX_SIZE; ++i)
  {
    q.EnQueue(i);
  }
  q.Print();

  std::cout << "\n尝试 EnQueue 一个溢出元素 (6):\n";
  q.EnQueue(6);

  std::cout << "\n当前队头元素: " << q.Front() << "\n";

  std::cout << "\nDeQueue 两个元素后: \n";
  q.DeQueue();
  q.DeQueue();
  q.Print();

  std::cout << "\nEnQueue 6 和 7: \n";
  q.EnQueue(6);
  q.EnQueue(7);
  q.Print();

  std::cout << "\nDeQueue 所有元素: \n";
  while (!q.IsEmpty())
  {
    std::cout << q.Front() << ' ';
    q.DeQueue();
  }
  std::cout << std::endl;

  std::cout << "\n尝试从空队列 DeQueue: \n";
  q.DeQueue();

  return 0;
}