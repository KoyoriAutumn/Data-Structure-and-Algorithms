#include <iostream>
#include <random>
#include <vector>
#include <sstream>
#include <string>
#include <chrono>
#include <algorithm>
#include <queue> // ���ڶ������priority_queue
#include <cmath> // ����ϣ����������м���
using namespace std;
using namespace chrono;

// ��������
void RandomArr(vector<int> &Arr, int len);
void BubbleSort(vector<int> &Arr);
void InsertionSort(vector<int> &Arr);
void SelectionSort(vector<int> &Arr);
void QuickSort(vector<int> &Arr);
void ShellSort(vector<int> &Arr);
void HeapSort(vector<int> &Arr);
void MergeSort(vector<int> &Arr);

// ��������������
void QuickSortRecursive(vector<int> &Arr, int low, int high, int &CmpTimes, int &MovTimes);

// ������������
void Heapify(vector<int> &Arr, int n, int i, int &CmpTimes, int &MovTimes);

// �鲢����������
void MergeSortRecursive(vector<int> &Arr, int left, int right, int &CmpTimes, int &MovTimes);
void Merge(vector<int> &Arr, int left, int mid, int right, int &CmpTimes, int &MovTimes);

int main()
{
  cout << "���һ�����Գ���Ƚϼ����ڲ������㷨�Ĺؼ��ֱȽϴ������ƶ�������ȡ��ֱ�۸��ܡ�Ҫ��" << endl
       << "1.��ð������ֱ�����򡢼�ѡ�����򡢿�������ϣ�����򡢶����򡢹鲢�����㷨���бȽϣ�" << endl
       << "2.�������¼�Ĺؼ���Ϊ���������е�����Ҫ��α��������������(��10000��)��������5�鲻ͬ��" << endl
       << "�����������Ƚϣ���ʹ�ø����㷨����������򣬼�¼������ʱ�䣬�ٻ��ܱȽϡ�" << endl
       << "3.ÿ�β��������ʾ���ֱȽ�ָ��ֵ���б��Ա�Ƚϸ�����������ӡ�" << endl;

  cout << endl
       << "1 �ֶ���������" << endl
       << "2 �Զ���������" << endl
       << "3 �˳�����" << endl
       << "�������Ӧ�Ĳ������֣�";
  int option;
  do
  {
    cin >> option;
    if (option == 3) // 3 �˳�����
    {
      return 0;
    }
  } while (option != 1 && option != 2);

  vector<int> Arr0;
  if (option == 2) // 2 �Զ���������
  {
    int Len;
    cout << "�������������ĳ��ȣ�";
    cin >> Len;
    RandomArr(Arr0, Len);
  }
  else if (option == 1) // 1 �ֶ���������
  {
    cin.ignore();
    string InputLine;
    cout << "���������ݣ�����֮����ո�������ϰ��س�����";
    getline(cin, InputLine);
    istringstream iss(InputLine);
    int num;
    while (iss >> num)
    {
      Arr0.push_back(num);
    }
  }

  vector<int> Arr1 = Arr0;
  vector<int> Arr2 = Arr0;
  vector<int> Arr3 = Arr0;
  vector<int> Arr4 = Arr0;
  vector<int> Arr5 = Arr0;
  vector<int> Arr6 = Arr0;
  vector<int> Arr7 = Arr0;

  BubbleSort(Arr1);
  InsertionSort(Arr2);
  SelectionSort(Arr3);
  QuickSort(Arr4);
  ShellSort(Arr5);
  HeapSort(Arr6);
  MergeSort(Arr7);

  return 0;
}

void RandomArr(vector<int> &Arr, int len)
{
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> dis(1, 10000); // 1-10000֮��������

  Arr.resize(len); // ���������С
  for (int i = 0; i < len; i++)
  {
    Arr[i] = dis(gen);
  }
}

void BubbleSort(vector<int> &Arr)
{
  int CmpTimes = 0, MovTimes = 0;
  auto start = system_clock::now();

  int n = Arr.size();
  bool swapped;
  for (int i = 0; i < n - 1; i++)
  {
    swapped = false;
    for (int j = 0; j < n - i - 1; j++)
    {
      CmpTimes++;
      if (Arr[j] > Arr[j + 1])
      {
        swap(Arr[j], Arr[j + 1]);
        MovTimes += 3; // ������������3�θ�ֵ
        swapped = true;
      }
    }
    if (!swapped)
      break;
  }

  auto end = system_clock::now();
  auto duration = duration_cast<microseconds>(end - start);

  cout << "\n��ð������ ��������" << endl
       << "�����ǰ10��Ԫ�أ�";
  for (int i = 0; i < 10 && i < Arr.size(); i++)
  {
    cout << Arr[i] << ' ';
  }
  cout << endl
       << "�Ƚϴ�����" << CmpTimes
       << "���ƶ�������" << MovTimes
       << "����ʱ��" << duration.count() << "΢��" << endl;
}

void InsertionSort(vector<int> &Arr)
{
  int CmpTimes = 0, MovTimes = 0;
  auto start = system_clock::now();

  int n = Arr.size();
  for (int i = 1; i < n; i++)
  {
    int key = Arr[i];
    MovTimes++; // ��¼key�ĸ�ֵ
    int j = i - 1;

    while (j >= 0)
    {
      CmpTimes++;
      if (Arr[j] > key)
      {
        Arr[j + 1] = Arr[j];
        MovTimes++;
        j--;
      }
      else
      {
        break;
      }
    }
    Arr[j + 1] = key;
    MovTimes++;
  }

  auto end = system_clock::now();
  auto duration = duration_cast<microseconds>(end - start);

  cout << "\n���������� ��������" << endl
       << "�����ǰ10��Ԫ�أ�";
  for (int i = 0; i < 10 && i < Arr.size(); i++)
  {
    cout << Arr[i] << ' ';
  }
  cout << endl
       << "�Ƚϴ�����" << CmpTimes
       << "���ƶ�������" << MovTimes
       << "����ʱ��" << duration.count() << "΢��" << endl;
}

void SelectionSort(vector<int> &Arr)
{
  int CmpTimes = 0, MovTimes = 0;
  auto start = system_clock::now();

  int n = Arr.size();
  for (int i = 0; i < n - 1; i++)
  {
    int minIndex = i;
    for (int j = i + 1; j < n; j++)
    {
      CmpTimes++;
      if (Arr[j] < Arr[minIndex])
      {
        minIndex = j;
      }
    }
    if (minIndex != i)
    {
      swap(Arr[i], Arr[minIndex]);
      MovTimes += 3; // ������������3�θ�ֵ
    }
  }

  auto end = system_clock::now();
  auto duration = duration_cast<microseconds>(end - start);

  cout << "\n��ѡ������ ��������" << endl
       << "�����ǰ10��Ԫ�أ�";
  for (int i = 0; i < 10 && i < Arr.size(); i++)
  {
    cout << Arr[i] << ' ';
  }
  cout << endl
       << "�Ƚϴ�����" << CmpTimes
       << "���ƶ�������" << MovTimes
       << "����ʱ��" << duration.count() << "΢��" << endl;
}

// ��������ʵ��
void QuickSort(vector<int> &Arr)
{
  int CmpTimes = 0, MovTimes = 0;
  auto start = system_clock::now();

  if (!Arr.empty())
  {
    QuickSortRecursive(Arr, 0, Arr.size() - 1, CmpTimes, MovTimes);
  }

  auto end = system_clock::now();
  auto duration = duration_cast<microseconds>(end - start);

  cout << "\n���������� ��������" << endl
       << "�����ǰ10��Ԫ�أ�";
  for (int i = 0; i < 10 && i < Arr.size(); i++)
  {
    cout << Arr[i] << ' ';
  }
  cout << endl
       << "�Ƚϴ�����" << CmpTimes
       << "���ƶ�������" << MovTimes
       << "����ʱ��" << duration.count() << "΢��" << endl;
}

void QuickSortRecursive(vector<int> &Arr, int low, int high, int &CmpTimes, int &MovTimes)
{
  if (low < high)
  {
    // ѡ���׼�㣨����ѡ���м�Ԫ�أ�
    int pivot = Arr[(low + high) / 2];
    int i = low;  // ��ָ��
    int j = high; // ��ָ��

    // ��������
    while (i <= j)
    {
      // ���������Ҵ��ڵ��ڻ�׼��Ԫ��
      while (true)
      {
        CmpTimes++;
        if (Arr[i] < pivot)
        {
          i++;
        }
        else
        {
          break;
        }
      }

      // ����������С�ڵ��ڻ�׼��Ԫ��
      while (true)
      {
        CmpTimes++;
        if (Arr[j] > pivot)
        {
          j--;
        }
        else
        {
          break;
        }
      }

      // ����Ԫ��
      if (i <= j)
      {
        swap(Arr[i], Arr[j]);
        MovTimes += 3; // ������������3�θ�ֵ
        i++;
        j--;
      }
    }

    // �ݹ�������������
    if (low < j)
    {
      QuickSortRecursive(Arr, low, j, CmpTimes, MovTimes);
    }

    // �ݹ�������������
    if (i < high)
    {
      QuickSortRecursive(Arr, i, high, CmpTimes, MovTimes);
    }
  }
}

// ϣ������ʵ��
void ShellSort(vector<int> &Arr)
{
  int CmpTimes = 0, MovTimes = 0;
  auto start = system_clock::now();

  int n = Arr.size();
  // ʹ��Knuth���м�����
  int h = 1;
  while (h < n / 3)
  {
    h = 3 * h + 1;
  }

  while (h >= 1)
  {
    for (int i = h; i < n; i++)
    {
      int temp = Arr[i];
      MovTimes++; // ��¼temp�ĸ�ֵ
      int j;
      for (j = i; j >= h; j -= h)
      {
        CmpTimes++;
        if (Arr[j - h] > temp)
        {
          Arr[j] = Arr[j - h];
          MovTimes++;
        }
        else
        {
          break;
        }
      }
      Arr[j] = temp;
      MovTimes++;
    }
    h /= 3;
  }

  auto end = system_clock::now();
  auto duration = duration_cast<microseconds>(end - start);

  cout << "\n��ϣ������ ��������" << endl
       << "�����ǰ10��Ԫ�أ�";
  for (int i = 0; i < 10 && i < Arr.size(); i++)
  {
    cout << Arr[i] << ' ';
  }
  cout << endl
       << "�Ƚϴ�����" << CmpTimes
       << "���ƶ�������" << MovTimes
       << "����ʱ��" << duration.count() << "΢��" << endl;
}

// ������ʵ��
void HeapSort(vector<int> &Arr)
{
  int CmpTimes = 0, MovTimes = 0;
  auto start = system_clock::now();

  int n = Arr.size();

  // ��������
  for (int i = n / 2 - 1; i >= 0; i--)
  {
    Heapify(Arr, n, i, CmpTimes, MovTimes);
  }

  // һ�����ӶѶ�ȡ��Ԫ��
  for (int i = n - 1; i > 0; i--)
  {
    swap(Arr[0], Arr[i]);
    MovTimes += 3;
    Heapify(Arr, i, 0, CmpTimes, MovTimes);
  }

  auto end = system_clock::now();
  auto duration = duration_cast<microseconds>(end - start);

  cout << "\n�������� ��������" << endl
       << "�����ǰ10��Ԫ�أ�";
  for (int i = 0; i < 10 && i < Arr.size(); i++)
  {
    cout << Arr[i] << ' ';
  }
  cout << endl
       << "�Ƚϴ�����" << CmpTimes
       << "���ƶ�������" << MovTimes
       << "����ʱ��" << duration.count() << "΢��" << endl;
}

void Heapify(vector<int> &Arr, int n, int i, int &CmpTimes, int &MovTimes)
{
  int largest = i; // ��ʼ�����Ԫ��Ϊ��
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  // ������ӽڵ���ڸ�
  if (left < n)
  {
    CmpTimes++;
    if (Arr[left] > Arr[largest])
    {
      largest = left;
    }
  }

  // ������ӽڵ���ڵ�ǰ���ֵ
  if (right < n)
  {
    CmpTimes++;
    if (Arr[right] > Arr[largest])
    {
      largest = right;
    }
  }

  // ������ֵ���Ǹ�
  if (largest != i)
  {
    swap(Arr[i], Arr[largest]);
    MovTimes += 3;
    // �ݹ�ضѻ���Ӱ����Ӷ�
    Heapify(Arr, n, largest, CmpTimes, MovTimes);
  }
}

// �鲢����ʵ��
void MergeSort(vector<int> &Arr)
{
  int CmpTimes = 0, MovTimes = 0;
  auto start = system_clock::now();

  if (!Arr.empty())
  {
    MergeSortRecursive(Arr, 0, Arr.size() - 1, CmpTimes, MovTimes);
  }

  auto end = system_clock::now();
  auto duration = duration_cast<microseconds>(end - start);

  cout << "\n���鲢���� ��������" << endl
       << "�����ǰ10��Ԫ�أ�";
  for (int i = 0; i < 10 && i < Arr.size(); i++)
  {
    cout << Arr[i] << ' ';
  }
  cout << endl
       << "�Ƚϴ�����" << CmpTimes
       << "���ƶ�������" << MovTimes
       << "����ʱ��" << duration.count() << "΢��" << endl;
}

void MergeSortRecursive(vector<int> &Arr, int left, int right, int &CmpTimes, int &MovTimes)
{
  if (left < right)
  {
    int mid = left + (right - left) / 2;

    // �ݹ���������������
    MergeSortRecursive(Arr, left, mid, CmpTimes, MovTimes);
    MergeSortRecursive(Arr, mid + 1, right, CmpTimes, MovTimes);

    // �ϲ��������������
    Merge(Arr, left, mid, right, CmpTimes, MovTimes);
  }
}

void Merge(vector<int> &Arr, int left, int mid, int right, int &CmpTimes, int &MovTimes)
{
  int n1 = mid - left + 1;
  int n2 = right - mid;

  // ������ʱ����
  vector<int> L(n1), R(n2);

  // �������ݵ���ʱ����
  for (int i = 0; i < n1; i++)
  {
    L[i] = Arr[left + i];
    MovTimes++;
  }
  for (int j = 0; j < n2; j++)
  {
    R[j] = Arr[mid + 1 + j];
    MovTimes++;
  }

  // �ϲ���ʱ����
  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2)
  {
    CmpTimes++;
    if (L[i] <= R[j])
    {
      Arr[k] = L[i];
      MovTimes++;
      i++;
    }
    else
    {
      Arr[k] = R[j];
      MovTimes++;
      j++;
    }
    k++;
  }

  // ����ʣ��Ԫ��
  while (i < n1)
  {
    Arr[k] = L[i];
    MovTimes++;
    i++;
    k++;
  }
  while (j < n2)
  {
    Arr[k] = R[j];
    MovTimes++;
    j++;
    k++;
  }
}