#include <iostream>
#include <vector>
using namespace std;

// ����������
void quickSort(vector<int> &arr, int left, int right)
{
  if (left >= right)
    return;
  int pivot = arr[left]; // ѡ�����Ϊ��׼
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
  swap(arr[left], arr[i]); // �� pivot �ŵ���ȷλ��
  quickSort(arr, left, i - 1);
  quickSort(arr, i + 1, right);
}

int main()
{
  int n;
  cout << "����������Ԫ�ظ�����";
  cin >> n;
  vector<int> arr(n);
  cout << "������ " << n << " ���������ÿո�ָ�����" << endl;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  quickSort(arr, 0, n - 1);

  cout << "�����Ľ��Ϊ��" << endl;
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}
