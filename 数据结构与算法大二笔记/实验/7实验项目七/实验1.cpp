#include <iostream>
#include <vector>

int SearchBin1(std::vector<int> lst, int key);                    // �ǵݹ�
int SearchBin2(std::vector<int> lst, int key, int low, int high); // �ݹ�

int main()
{
  int lstlength, key;
  std::cout << "�������������еĳ��ȣ�" << std::endl;
  std::cin >> lstlength;
  std::vector<int> lst(lstlength);
  std::cout << "������ " << lstlength << " ��������������С���󣩣�" << std::endl;
  for (int i = 0; i < lstlength; i++)
  {
    std::cin >> lst[i];
  }
  std::cout << "������Ҫ���ҵĹؼ��֣�" << std::endl;
  std::cin >> key;
  int index1 = SearchBin1(lst, key);
  std::cout << "�ǵݹ��۰���ҽ���±꣺" << index1 << std::endl;
  int index2 = SearchBin2(lst, key, 0, lst.size() - 1);
  std::cout << "�ݹ��۰���ҽ���±꣺" << index2 << std::endl;
}

int SearchBin1(std::vector<int> lst, int key)
{
  int low = 0, high = lst.size() - 1;
  int current = (low + high) / 2;
  while (lst[current] != key)
  {
    if (low > high)
    {
      std::cout << "δ�ҵ���������-1" << std::endl;
      return -1;
    }
    if (lst[current] < key)
    {
      low = current + 1;
      current = (low + high) / 2;
    }
    else if (lst[current] > key)
    {
      high = current - 1;
      current = (low + high) / 2;
    }
  }
  return current;
}

int SearchBin2(std::vector<int> lst, int key, int low, int high)
{
  int current = (low + high) / 2;
  if (low > high)
  {
    std::cout << "δ�ҵ���������-1" << std::endl;
    return -1;
  }
  if (lst[current] == key)
  {
    return current;
  }
  if (lst[current] < key)
  {
    return SearchBin2(lst, key, current + 1, high);
  }
  else if (lst[current] > key)
  {
    return SearchBin2(lst, key, low, current - 1);
  }
}