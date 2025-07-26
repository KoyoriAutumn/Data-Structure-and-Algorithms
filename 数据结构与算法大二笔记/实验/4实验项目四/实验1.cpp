#include <iostream>
#include <string>

const int MAX_SIZE = 100; // 循环队列的最大容量

class CircularQueue
{
private:
  char data[MAX_SIZE]; // 存储队列元素的数组
  int front, rear;     // 队列的头指针和尾指针
  int size;            // 队列中元素的数量

public:
  CircularQueue() : front(0), rear(0), size(0) {} // 构造函数，初始化队列

  // 判断队列是否为空
  bool isEmpty()
  {
    return size == 0;
  }

  // 判断队列是否已满
  bool isFull()
  {
    return size == MAX_SIZE;
  }

  // 入队操作
  void enqueue(char ch)
  {
    if (isFull())
    { // 如果队列已满，输出提示信息
      std::cout << "队列已满，无法入队！" << std::endl;
      return;
    }
    data[rear] = ch;              // 将元素存入队尾
    rear = (rear + 1) % MAX_SIZE; // 更新队尾指针（循环队列）
    size++;                       // 队列元素数量加1
  }

  // 出队操作
  void dequeue()
  {
    if (isEmpty())
    { // 如果队列为空，输出提示信息
      std::cout << "队列为空，无法出队！" << std::endl;
      return;
    }
    front = (front + 1) % MAX_SIZE; // 更新队头指针（循环队列）
    size--;                         // 队列元素数量减1
  }

  // 清空队列
  void clear()
  {
    front = 0;
    rear = 0;
    size = 0;
  }

  // 显示队列中的所有元素
  void display()
  {
    if (isEmpty())
    { // 如果队列为空，输出提示信息
      std::cout << "队列为空！" << std::endl;
      return;
    }
    int current = front; // 从队头开始遍历
    for (int i = 0; i < size; i++)
    {
      std::cout << data[current];         // 输出当前元素
      current = (current + 1) % MAX_SIZE; // 移动到下一个元素（循环队列）
    }
    std::cout << std::endl;
  }
};

int main()
{
  CircularQueue queue; // 创建循环队列对象
  std::string input;   // 用于存储用户输入的字符串

  while (true)
  {
    std::cout << "请输入字符串（输入 exit 退出程序）：";
    std::cin >> input;

    if (input == "exit")
    { // 如果输入为 "exit"，退出程序
      break;
    }

    for (char ch : input)
    {
      if (std::isalpha(ch))
      { // 如果是字母字符，入队
        queue.enqueue(ch);
      }
      else if (std::isdigit(ch))
      { // 如果是数字字符，出队
        queue.dequeue();
      }
      // 其他字符忽略
    }

    std::cout << "队列中的字符：";
    queue.display(); // 显示队列中的所有字符

    // 清空队列
    queue.clear();
    std::cout << "队列已清空。" << std::endl;
  }

  return 0;
}
