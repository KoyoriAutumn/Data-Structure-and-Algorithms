#include <iostream>
#include <random>
#include <vector>
#include <sstream>
#include <string>
#include <chrono>
#include <algorithm>
#include <queue> // 用于堆排序的priority_queue
#include <cmath> // 用于希尔排序的序列计算
using namespace std;
using namespace chrono;

// 函数声明
void RandomArr(vector<int> &Arr, int len);
void BubbleSort(vector<int> &Arr);
void InsertionSort(vector<int> &Arr);
void SelectionSort(vector<int> &Arr);
void QuickSort(vector<int> &Arr);
void ShellSort(vector<int> &Arr);
void HeapSort(vector<int> &Arr);
void MergeSort(vector<int> &Arr);

// 快速排序辅助函数
void QuickSortRecursive(vector<int> &Arr, int low, int high, int &CmpTimes, int &MovTimes);

// 堆排序辅助函数
void Heapify(vector<int> &Arr, int n, int i, int &CmpTimes, int &MovTimes);

// 归并排序辅助函数
void MergeSortRecursive(vector<int> &Arr, int left, int right, int &CmpTimes, int &MovTimes);
void Merge(vector<int> &Arr, int left, int mid, int right, int &CmpTimes, int &MovTimes);

int main()
{
  cout << "设计一个测试程序比较几种内部排序算法的关键字比较次数和移动次数以取得直观感受。要求：" << endl
       << "1.对冒泡排序、直接排序、简单选择排序、快速排序、希尔排序、堆排序、归并排序算法进行比较；" << endl
       << "2.待排序记录的关键字为整数。其中的数据要用伪随机产生程序产生(如10000个)，至少用5组不同的" << endl
       << "输入数据做比较，再使用各种算法对其进行排序，记录其排序时间，再汇总比较。" << endl
       << "3.每次测试完毕显示各种比较指标值的列表，以便比较各种排序的优劣。" << endl;

  cout << endl
       << "1 手动输入数据" << endl
       << "2 自动生成数据" << endl
       << "3 退出程序" << endl
       << "请输入对应的操作数字：";
  int option;
  do
  {
    cin >> option;
    if (option == 3) // 3 退出程序
    {
      return 0;
    }
  } while (option != 1 && option != 2);

  vector<int> Arr0;
  if (option == 2) // 2 自动生成数据
  {
    int Len;
    cout << "请输入测试数组的长度：";
    cin >> Len;
    RandomArr(Arr0, Len);
  }
  else if (option == 1) // 1 手动输入数据
  {
    cin.ignore();
    string InputLine;
    cout << "请输入数据（数据之间隔空格，输入完毕按回车）：";
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
  uniform_int_distribution<> dis(1, 10000); // 1-10000之间的随机数

  Arr.resize(len); // 调整数组大小
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
        MovTimes += 3; // 交换操作包含3次赋值
        swapped = true;
      }
    }
    if (!swapped)
      break;
  }

  auto end = system_clock::now();
  auto duration = duration_cast<microseconds>(end - start);

  cout << "\n【冒泡排序 排序结果】" << endl
       << "排序后前10个元素：";
  for (int i = 0; i < 10 && i < Arr.size(); i++)
  {
    cout << Arr[i] << ' ';
  }
  cout << endl
       << "比较次数：" << CmpTimes
       << "，移动次数：" << MovTimes
       << "，耗时：" << duration.count() << "微秒" << endl;
}

void InsertionSort(vector<int> &Arr)
{
  int CmpTimes = 0, MovTimes = 0;
  auto start = system_clock::now();

  int n = Arr.size();
  for (int i = 1; i < n; i++)
  {
    int key = Arr[i];
    MovTimes++; // 记录key的赋值
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

  cout << "\n【插入排序 排序结果】" << endl
       << "排序后前10个元素：";
  for (int i = 0; i < 10 && i < Arr.size(); i++)
  {
    cout << Arr[i] << ' ';
  }
  cout << endl
       << "比较次数：" << CmpTimes
       << "，移动次数：" << MovTimes
       << "，耗时：" << duration.count() << "微秒" << endl;
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
      MovTimes += 3; // 交换操作包含3次赋值
    }
  }

  auto end = system_clock::now();
  auto duration = duration_cast<microseconds>(end - start);

  cout << "\n【选择排序 排序结果】" << endl
       << "排序后前10个元素：";
  for (int i = 0; i < 10 && i < Arr.size(); i++)
  {
    cout << Arr[i] << ' ';
  }
  cout << endl
       << "比较次数：" << CmpTimes
       << "，移动次数：" << MovTimes
       << "，耗时：" << duration.count() << "微秒" << endl;
}

// 快速排序实现
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

  cout << "\n【快速排序 排序结果】" << endl
       << "排序后前10个元素：";
  for (int i = 0; i < 10 && i < Arr.size(); i++)
  {
    cout << Arr[i] << ' ';
  }
  cout << endl
       << "比较次数：" << CmpTimes
       << "，移动次数：" << MovTimes
       << "，耗时：" << duration.count() << "微秒" << endl;
}

void QuickSortRecursive(vector<int> &Arr, int low, int high, int &CmpTimes, int &MovTimes)
{
  if (low < high)
  {
    // 选择基准点（这里选择中间元素）
    int pivot = Arr[(low + high) / 2];
    int i = low;  // 左指针
    int j = high; // 右指针

    // 分区操作
    while (i <= j)
    {
      // 从左向右找大于等于基准的元素
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

      // 从右向左找小于等于基准的元素
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

      // 交换元素
      if (i <= j)
      {
        swap(Arr[i], Arr[j]);
        MovTimes += 3; // 交换操作包含3次赋值
        i++;
        j--;
      }
    }

    // 递归排序左子数组
    if (low < j)
    {
      QuickSortRecursive(Arr, low, j, CmpTimes, MovTimes);
    }

    // 递归排序右子数组
    if (i < high)
    {
      QuickSortRecursive(Arr, i, high, CmpTimes, MovTimes);
    }
  }
}

// 希尔排序实现
void ShellSort(vector<int> &Arr)
{
  int CmpTimes = 0, MovTimes = 0;
  auto start = system_clock::now();

  int n = Arr.size();
  // 使用Knuth序列计算间隔
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
      MovTimes++; // 记录temp的赋值
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

  cout << "\n【希尔排序 排序结果】" << endl
       << "排序后前10个元素：";
  for (int i = 0; i < 10 && i < Arr.size(); i++)
  {
    cout << Arr[i] << ' ';
  }
  cout << endl
       << "比较次数：" << CmpTimes
       << "，移动次数：" << MovTimes
       << "，耗时：" << duration.count() << "微秒" << endl;
}

// 堆排序实现
void HeapSort(vector<int> &Arr)
{
  int CmpTimes = 0, MovTimes = 0;
  auto start = system_clock::now();

  int n = Arr.size();

  // 构建最大堆
  for (int i = n / 2 - 1; i >= 0; i--)
  {
    Heapify(Arr, n, i, CmpTimes, MovTimes);
  }

  // 一个个从堆顶取出元素
  for (int i = n - 1; i > 0; i--)
  {
    swap(Arr[0], Arr[i]);
    MovTimes += 3;
    Heapify(Arr, i, 0, CmpTimes, MovTimes);
  }

  auto end = system_clock::now();
  auto duration = duration_cast<microseconds>(end - start);

  cout << "\n【堆排序 排序结果】" << endl
       << "排序后前10个元素：";
  for (int i = 0; i < 10 && i < Arr.size(); i++)
  {
    cout << Arr[i] << ' ';
  }
  cout << endl
       << "比较次数：" << CmpTimes
       << "，移动次数：" << MovTimes
       << "，耗时：" << duration.count() << "微秒" << endl;
}

void Heapify(vector<int> &Arr, int n, int i, int &CmpTimes, int &MovTimes)
{
  int largest = i; // 初始化最大元素为根
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  // 如果左子节点大于根
  if (left < n)
  {
    CmpTimes++;
    if (Arr[left] > Arr[largest])
    {
      largest = left;
    }
  }

  // 如果右子节点大于当前最大值
  if (right < n)
  {
    CmpTimes++;
    if (Arr[right] > Arr[largest])
    {
      largest = right;
    }
  }

  // 如果最大值不是根
  if (largest != i)
  {
    swap(Arr[i], Arr[largest]);
    MovTimes += 3;
    // 递归地堆化受影响的子堆
    Heapify(Arr, n, largest, CmpTimes, MovTimes);
  }
}

// 归并排序实现
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

  cout << "\n【归并排序 排序结果】" << endl
       << "排序后前10个元素：";
  for (int i = 0; i < 10 && i < Arr.size(); i++)
  {
    cout << Arr[i] << ' ';
  }
  cout << endl
       << "比较次数：" << CmpTimes
       << "，移动次数：" << MovTimes
       << "，耗时：" << duration.count() << "微秒" << endl;
}

void MergeSortRecursive(vector<int> &Arr, int left, int right, int &CmpTimes, int &MovTimes)
{
  if (left < right)
  {
    int mid = left + (right - left) / 2;

    // 递归排序左右子数组
    MergeSortRecursive(Arr, left, mid, CmpTimes, MovTimes);
    MergeSortRecursive(Arr, mid + 1, right, CmpTimes, MovTimes);

    // 合并已排序的子数组
    Merge(Arr, left, mid, right, CmpTimes, MovTimes);
  }
}

void Merge(vector<int> &Arr, int left, int mid, int right, int &CmpTimes, int &MovTimes)
{
  int n1 = mid - left + 1;
  int n2 = right - mid;

  // 创建临时数组
  vector<int> L(n1), R(n2);

  // 复制数据到临时数组
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

  // 合并临时数组
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

  // 复制剩余元素
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