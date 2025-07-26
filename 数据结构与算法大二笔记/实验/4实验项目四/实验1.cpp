#include <iostream>
#include <string>

const int MAX_SIZE = 100; // ѭ�����е��������

class CircularQueue
{
private:
  char data[MAX_SIZE]; // �洢����Ԫ�ص�����
  int front, rear;     // ���е�ͷָ���βָ��
  int size;            // ������Ԫ�ص�����

public:
  CircularQueue() : front(0), rear(0), size(0) {} // ���캯������ʼ������

  // �ж϶����Ƿ�Ϊ��
  bool isEmpty()
  {
    return size == 0;
  }

  // �ж϶����Ƿ�����
  bool isFull()
  {
    return size == MAX_SIZE;
  }

  // ��Ӳ���
  void enqueue(char ch)
  {
    if (isFull())
    { // ������������������ʾ��Ϣ
      std::cout << "�����������޷���ӣ�" << std::endl;
      return;
    }
    data[rear] = ch;              // ��Ԫ�ش����β
    rear = (rear + 1) % MAX_SIZE; // ���¶�βָ�루ѭ�����У�
    size++;                       // ����Ԫ��������1
  }

  // ���Ӳ���
  void dequeue()
  {
    if (isEmpty())
    { // �������Ϊ�գ������ʾ��Ϣ
      std::cout << "����Ϊ�գ��޷����ӣ�" << std::endl;
      return;
    }
    front = (front + 1) % MAX_SIZE; // ���¶�ͷָ�루ѭ�����У�
    size--;                         // ����Ԫ��������1
  }

  // ��ն���
  void clear()
  {
    front = 0;
    rear = 0;
    size = 0;
  }

  // ��ʾ�����е�����Ԫ��
  void display()
  {
    if (isEmpty())
    { // �������Ϊ�գ������ʾ��Ϣ
      std::cout << "����Ϊ�գ�" << std::endl;
      return;
    }
    int current = front; // �Ӷ�ͷ��ʼ����
    for (int i = 0; i < size; i++)
    {
      std::cout << data[current];         // �����ǰԪ��
      current = (current + 1) % MAX_SIZE; // �ƶ�����һ��Ԫ�أ�ѭ�����У�
    }
    std::cout << std::endl;
  }
};

int main()
{
  CircularQueue queue; // ����ѭ�����ж���
  std::string input;   // ���ڴ洢�û�������ַ���

  while (true)
  {
    std::cout << "�������ַ��������� exit �˳����򣩣�";
    std::cin >> input;

    if (input == "exit")
    { // �������Ϊ "exit"���˳�����
      break;
    }

    for (char ch : input)
    {
      if (std::isalpha(ch))
      { // �������ĸ�ַ������
        queue.enqueue(ch);
      }
      else if (std::isdigit(ch))
      { // ����������ַ�������
        queue.dequeue();
      }
      // �����ַ�����
    }

    std::cout << "�����е��ַ���";
    queue.display(); // ��ʾ�����е������ַ�

    // ��ն���
    queue.clear();
    std::cout << "��������ա�" << std::endl;
  }

  return 0;
}
