#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

struct Node
{
  int num;
  string name;
  Node *next = nullptr;
};
typedef Node *LinkList;

void LoopLink(int N, LinkList Lst);
void Remove(LinkList &Lst, Node *node);
void DieFunc(int N, LinkList &Lst);

int main()
{
  cout
      << "有N个旅客同乘一条船，因为严重超载，加上风高浪大，危险万分；因此船长告" << endl
      << "诉乘客，只有将全船一半的旅客投入海中，其余人才能幸免于难；无奈，大家只" << endl
      << "得同意这种办法，并议定N个人围成一圈，由第一个人开始，依次报数，数到第9" << endl
      << "人，便把他投入大海中，然后再从他的下一个人开始，数到第9人，再把他投入大" << endl
      << "海中，如此循环地进行，直到剩下N/2个乘客为止。" << endl;
  int N;
  cout << "请输入乘客总人数N（N为偶数）：";
  while (true)
  {
    cin >> N;
    if (cin && (N > 0) && (N % 2 == 0) && cin.peek() == '\n')
    {
      break;
    }
    else
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "请输入乘客总人数N（N为偶数）：";
    }
  }
  /*while (!(cin >> N) || N <= 0 || N % 2 != 0)
  {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "请输入乘客总人数N（N为偶数）：";
  }*/
  /*do
  {
    cout << "请输入乘客总人数N（N为偶数）：";
    cin >> N;
  } while (N % 2 != 0 or N <= 0);*/
  LinkList AllMemberList = new Node;
  LoopLink(N, AllMemberList);
  DieFunc(N, AllMemberList);
  return 0;
}

void LoopLink(int N, LinkList Lst)
{
  Node *prev;
  for (int i = 0; i < N; i++)
  {
    cout << "请输入第" << i + 1 << "个乘客的姓名：";
    if (i == 0) // 头结点特判
    {
      Lst->num = i + 1;
      cin >> Lst->name;
      prev = Lst;
    }
    else
    {
      Node *NewNode = new Node;
      NewNode->num = i + 1;
      cin >> NewNode->name;
      prev->next = NewNode;
      prev = prev->next;
    }
  }
  prev->next = Lst;
}

void Remove(LinkList &Lst, Node *node)
{
  if (Lst == node) // 删除头结点特判
    Lst = Lst->next;

  Node *current = Lst;
  while (current->next != node)
  {
    current = current->next;
  }
  // current->next == node;
  current->next = node->next;
}

void DieFunc(int N, LinkList &Lst)
{
  Node *current = Lst;
  int DieNum = 0;
  vector<Node *> DieList(N / 2);
  while (DieNum != N / 2)
  {
    for (int i = 1; i < 9; i++)
    {
      current = current->next;
    }
    DieList[DieNum] = current;
    Node *temp = current;
    current = current->next;
    Remove(Lst, temp);
    DieNum++;
  }
  cout << "被投入大海的乘客名单如下（共 " << DieNum << " 人）：" << endl;
  for (int i = 0; i < DieNum; i++)
  {
    cout << "姓名：" << DieList[i]->name << "，位置：" << DieList[i]->num << endl;
  }
  cout << "幸存乘客名单如下（共 " << N - DieNum << " 人）：" << endl;
  Node *current1 = Lst;
  for (int i = 0; i < N - DieNum; i++)
  {
    cout << "姓名：" << current1->name << "，位置：" << current1->num << endl;
    Node *temp = current1;
    current1 = current1->next;
    delete temp;
  }
  for (int i = 0; i < DieNum; i++)
  {
    delete DieList[i];
  }
}