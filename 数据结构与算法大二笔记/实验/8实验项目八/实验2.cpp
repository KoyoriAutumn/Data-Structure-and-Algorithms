#include <iostream>
#include <vector>
using namespace std;

// 合并两个子数组
void merge(vector<int> &arr, int left, int mid, int right)
{
  vector<int> temp(right - left + 1);
  int i = left, j = mid + 1, k = 0;

  while (i <= mid && j <= right)
  {
    if (arr[i] <= arr[j])
      temp[k++] = arr[i++];
    else
      temp[k++] = arr[j++];
  }

  while (i <= mid)
    temp[k++] = arr[i++];
  while (j <= right)
    temp[k++] = arr[j++];

  for (int m = 0; m < temp.size(); ++m)
  {
    arr[left + m] = temp[m];
  }
}

// 归并排序递归函数
void mergeSort(vector<int> &arr, int left, int right)
{
  if (left >= right)
    return;
  int mid = (left + right) / 2;
  mergeSort(arr, left, mid);
  mergeSort(arr, mid + 1, right);
  merge(arr, left, mid, right);
}

int main()
{
  int n;
  cout << "请输入数组元素个数：";
  cin >> n;
  vector<int> arr(n);
  cout << "请输入 " << n << " 个整数（用空格分隔）：" << endl;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  mergeSort(arr, 0, n - 1);

  cout << "排序后的结果为：" << endl;
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}