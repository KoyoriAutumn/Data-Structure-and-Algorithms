#include <iostream>
#include <vector>
using namespace std;

// 快速排序函数
void quickSort(vector<int> &arr, int left, int right)
{
  if (left >= right)
    return;
  int pivot = arr[left]; // 选最左边为基准
  int i = left, j = right;
  while (i < j)
  {
    while (i < j && arr[j] >= pivot)
      j--;
    while (i < j && arr[i] <= pivot)
      i++;
    if (i < j)
      swap(arr[i], arr[j]);
  }
  swap(arr[left], arr[i]); // 把 pivot 放到正确位置
  quickSort(arr, left, i - 1);
  quickSort(arr, i + 1, right);
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

  quickSort(arr, 0, n - 1);

  cout << "排序后的结果为：" << endl;
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}
