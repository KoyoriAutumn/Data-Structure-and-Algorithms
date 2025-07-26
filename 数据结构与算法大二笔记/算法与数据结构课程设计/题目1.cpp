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
      << "��N���ÿ�ͬ��һ��������Ϊ���س��أ����Ϸ���˴�Σ����֣���˴�����" << endl
      << "�߳˿ͣ�ֻ�н�ȫ��һ����ÿ�Ͷ�뺣�У������˲����������ѣ����Σ����ֻ" << endl
      << "��ͬ�����ְ취�����鶨N����Χ��һȦ���ɵ�һ���˿�ʼ�����α�����������9" << endl
      << "�ˣ������Ͷ����У�Ȼ���ٴ�������һ���˿�ʼ��������9�ˣ��ٰ���Ͷ���" << endl
      << "���У����ѭ���ؽ��У�ֱ��ʣ��N/2���˿�Ϊֹ��" << endl;
  int N;
  cout << "������˿�������N��NΪż������";
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
      cout << "������˿�������N��NΪż������";
    }
  }
  /*while (!(cin >> N) || N <= 0 || N % 2 != 0)
  {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "������˿�������N��NΪż������";
  }*/
  /*do
  {
    cout << "������˿�������N��NΪż������";
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
    cout << "�������" << i + 1 << "���˿͵�������";
    if (i == 0) // ͷ�������
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
  if (Lst == node) // ɾ��ͷ�������
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
  cout << "��Ͷ��󺣵ĳ˿��������£��� " << DieNum << " �ˣ���" << endl;
  for (int i = 0; i < DieNum; i++)
  {
    cout << "������" << DieList[i]->name << "��λ�ã�" << DieList[i]->num << endl;
  }
  cout << "�Ҵ�˿��������£��� " << N - DieNum << " �ˣ���" << endl;
  Node *current1 = Lst;
  for (int i = 0; i < N - DieNum; i++)
  {
    cout << "������" << current1->name << "��λ�ã�" << current1->num << endl;
    Node *temp = current1;
    current1 = current1->next;
    delete temp;
  }
  for (int i = 0; i < DieNum; i++)
  {
    delete DieList[i];
  }
}