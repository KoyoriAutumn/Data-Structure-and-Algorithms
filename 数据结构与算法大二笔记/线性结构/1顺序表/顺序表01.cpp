#include <iostream>

#define MAXSIZE 100 //˳�������

// ˳���ṹ�嶨�塣
struct SqList
{
  int data[MAXSIZE]; //���˳����Ԫ��
  int len; //��ǰ����
};
 
//Ҫʵ�ֵĹ��ܣ�
void InitList(SqList &L);
int ListLength(const SqList &L);
int GetElem(const SqList &L, int i);
int LocateElem(const SqList &L, int value);
bool ListInsert(SqList &L, int i, int e);
bool ListDelete(SqList &L, int i);
void PrintList(const SqList& L);

int main()
{
  SqList L;
    
  //����1����ʼ������
  InitList(L);
  std::cout << "===== ����1����ʼ���� =====" << std::endl;
  std::cout << "��ʼ����: " << ListLength(L) << std::endl; //��ʼ����Ϊ0
  PrintList(L);

  //����2�������������
  std::cout << "===== ����2��������� =====" << std::endl;
    
  //��������
  ListInsert(L, 1, 10); //10
  ListInsert(L, 2, 30); //10, 30
  ListInsert(L, 2, 20); //10, 20, 30
  std::cout << "����3��Ԫ�غ�" << std::endl;
  PrintList(L); //Ӧ��ʾ10, 20, 30

  //ͷ����
  ListInsert(L, 1, 5); //5, 10, 20, 30
  //β����
  ListInsert(L, 5, 40); //5, 10, 20, 30, 40
  std::cout << "���ͷβԪ�غ�" << std::endl;
  PrintList(L); //Ӧ��ʾ5, 10, 20, 30, 40

  //����������
  std::cout << "���������ԣ�" << std::endl;
  bool ret = ListInsert(L, 0, 100); //λ�ù�С
  ret = ListInsert(L, 7, 100); //λ�ù���
  PrintList(L);

  //����3�����Ҳ�������
  std::cout << "===== ����3�����Ҳ��� =====" << std::endl;
    
  //��λ�ò���
  try
  {
    std::cout << "λ��3��Ԫ��: " << GetElem(L, 3) << std::endl; //Ӧ���20
    std::cout << "λ��5��Ԫ��: " << GetElem(L, 5) << std::endl; //Ӧ���40
        
    //����λ�ò���
    std::cout << "���Ի�ȡλ��0: ";
    std::cout << GetElem(L, 0) << std::endl;
  } 
  catch (const std::exception& e)
  {
    std::cerr << "!! �����쳣: " << e.what() << std::endl;
  }

  //��ֵ����
  std::cout << "\n����Ԫ��20��λ��: " << LocateElem(L, 20) << std::endl; //Ӧ����3
  std::cout << "���Ҳ����ڵ�99: " << LocateElem(L, 99) << std::endl; //Ӧ����0

  //����4��ɾ����������
  std::cout << "\n===== ����4��ɾ������ =====" << std::endl;
    
  // ����ɾ���м�Ԫ��
  ListDelete(L, 3); //ɾ��20
  std::cout << "ɾ��λ��3��" << std::endl;
  PrintList(L); //5, 10, 30, 40

  // ɾ��ͷ��Ԫ��
  ListDelete(L, 1); //ɾ��5
  std::cout << "ɾ��ͷ����" << std::endl;
  PrintList(L); //10, 30, 40

  // ɾ��β��Ԫ��
  ListDelete(L, 3);      //ɾ��40
  std::cout << "ɾ��β����" << std::endl;
  PrintList(L); //10, 30

  // ����ɾ������
  std::cout << "===== ����ɾ������ =====" << std::endl;
  ret = ListDelete(L, 0); //λ�ù�С
  ret = ListDelete(L, 4); //λ�ù���
  PrintList(L); //10, 30

  //����5����ղ�������
  std::cout << "===== ����5����ղ��� =====" << std::endl;
  while (L.len > 0)
  {
    ListDelete(L, 1); //ѭ��ɾ����Ԫ��
  }
  PrintList(L); //Ӧ��ʾ�ձ�
    
  // �ձ�ɾ������
  ret = ListDelete(L, 1);

  return 0;
}

//��ʼ��˳���
void InitList(SqList &L)
{
  //����Ҫ����data���鱾��
  //��������ʱ�Ḳ��ԭ��λ�õ�ֵ��
  L.len = 0;
}

//��ȡ˳���ǰ���ȡ�
int ListLength(const SqList &L) //��const��Ϊ����Ҫ�޸�˳�����&L���´����ʱ���飬�����Ż����ܡ�
{
  return L.len;
}

//��λ�ò���Ԫ�ء�
int GetElem(const SqList &L, int i)
{
  if(i < 1 || i > L.len)
  {
    std::cerr << "[ERROR] λ��" << i << "��Ч��ѡ���λ�ò��ڱ��ڣ�\n"; //����쳣��Ϣ
    throw std::out_of_range("λ��" + std::to_string(i) + "��Ч"); //�׳��쳣����������
  }
  return L.data[i - 1];
}

//��ֵ����Ԫ�ء�
int LocateElem(const SqList &L, int value)
{
  for (int i = 0; i < L.len; i++)
  {
    if (L.data[i] == value)
    {
      return i + 1;
    }
  }
  return 0;
}

//����Ԫ�ء�
//���б�L�ĵ�i��λ�ò���Ԫ��e��
bool ListInsert(SqList &L, int i, int e)
{
  //ѡ���λ�ò��ڱ��ڡ�
  if(i < 1 || i > L.len + 1) //ҪдL.len+1����Ȼ�޷��ڱ�β����
  {
    std::cerr << "[ERROR] λ��" << i << "��Ч��ѡ���λ�ò��ڱ��ڣ�\n";
    return false;
  }
    
  //˳���������
  if(L.len == MAXSIZE)
  {
    std::cerr << "[ERROR] ˳���������";
    return false;
  }

  //�ų������쳣�������ʼ���롣
  for(int j = L.len - 1; j >= i - 1; j--)
  {
    L.data[j + 1] = L.data[j];
  }
  L.len++;
  L.data[i - 1] = e;
  return true;
}

//ɾ��Ԫ�ء�
//ɾ���б�L�ĵ�i��λ�õ�Ԫ�ء�
bool ListDelete(SqList &L, int i)
{
  //�ձ������
  if (L.len == 0)
  {
    std::cerr << "[ERROR] ˳���Ϊ�գ��޷�ɾ����\n";
    return false;
  }

  //ѡ���λ�ò��ڱ��ڡ�
  if(i < 1 || i > L.len)
  {
    std::cerr << "[ERROR] λ��" << i << "��Ч��ѡ���λ�ò��ڱ��ڣ�\n";
    return false;
  }

  //�ų������쳣�������ʼɾ����
  for(int j = i - 1; j < L.len - 1; j++)
  {
    L.data[j] = L.data[j + 1];
  }
  L.len--;
  return true;
}

//��ӡ˳���
void PrintList(const SqList& L)
{
  std::cout << "��ǰ˳������ݣ�����Ϊ" << L.len << "����";
  for(int i = 0; i < L.len; i++)
  {
    std::cout << L.data[i];
    if (i != L.len - 1)
    {
      std::cout << ", ";
    }
  }
  if (L.len == 0)
  {
    std::cout << "�ձ�";
  }
  std::cout << "\n\n";
}