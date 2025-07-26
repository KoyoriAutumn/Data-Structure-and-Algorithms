#include <iostream>

//��C++��ʵ�������ṹ�嶨��ڵ㡢���빦�ܡ���ӡ���ܣ�����������ɾ�����ܡ���ת���ܣ�����������

//�ڵ��ʵ�֡�һ�����ǰ��½ڵ�����Ϊtemp��
//�ڵ�����Ҫ�أ�
//һ�ǽڵ㱾��ĵ�ַ��temp��;�����������Ҫ������������������ߡ���
//���ǽڵ㱣������ݣ�temp->data��;
//���ǽڵ�ָ�����һ���ڵ�ĵ�ַ��temp->next����
//Node* next˵�Ľ��֣���һ����next���ڵ㣨Node���ĵ�ַ��*����
struct Node
{
  int data;
  Node* next;
};

//����ͷָ�롣ͷָ��洢ͷ�ڵ�ĵ�ַ��
//ȫ�ֱ���������������ط����á�
Node* pointer_to_head;

//����Ҫʵ�ֵĹ��ܡ�
//���빦�ܣ�
void Insert(int data, int n);
void Insert(int data);
//��ӡ���ܣ�
void Print();
//ɾ������:
void Delete(int n);
//��ת���ܣ�
void Reverse();

int main(void)
{
  //����һ���½ڵ㡣
  //������Ҫ���½ڵ�����ڴ�ռ䡣
  //�����ڴ�ռ䣬����̸��ġ������Ϊʲô����дNode* temp������Node temp��
  //Node* temp�������������ڴ���������ڵ�ĵ�ַ��
  //��Node temp���Ƿ�������֪����
  Node* temp = new Node();

  //һ���򵥵Ĳ��ԡ�
  int a;
  printf("һ�������½ڵ�\n���������֣�");
  scanf("%d", &a);
  temp->data = a;
  temp->next = nullptr;
  printf("����ڵ㱣���������%d\n\n", temp->data);

  //ʵ�ֲ��빦�ܡ�
  //ͷָ��һ��ʼ���洢�κε�ַ����ʹ��nullptr����Ч��ַ����
  printf("������������ʹ�ӡ����\n");
  pointer_to_head = nullptr; //����ͷָ�롣�����в����ڣ�����ͷָ��ָ��nullptr��
  Insert(4); //����4
  Insert(9,2); //����4, 9
  Insert(7,3); //����4, 9, 7
  Insert(5,2); //����4, 5, 9, 7
  Insert(0,1); //����0, 4, 5, 9, 7
  Insert(11); //����0, 4, 5, 9, 7, 11

  //ʵ�ִ�ӡ���ܡ�
  Print();

  //ʵ��ɾ�����ܡ�
  printf("\n����ɾ������\n");
  Delete(5); //����0, 4, 5, 9, 11
  Print();
  Delete(1); //����4, 5, 9, 11
  Print();

  //ʵ�ַ�ת���ܡ�
  printf("\n�ġ���ת����");
  Reverse(); //����11, 9, 5, 4
  Print();

  return 0;
}

//���빦�ܵ�ʵ�֣���һ���½ڵ���������С�
//���������������������һ����Ҫ��������ݣ��ڶ�����Ҫ�����λ�á�
//Ҫ���ǵ�����������磺������������ڣ�Ҫ�����λ�ò����ڣ�����̫�̣�������
void Insert(int data, int n)
{
  //�����½ڵ㡣
  Node* temp1 = new Node();
  temp1->data = data;
  temp1->next = nullptr;

  //ʵ�ִ��������� or ͷ����������
  if(n == 1)
  {
    //����дtemp1->next = nullptr�������������Ѿ����ڵ�����£���ʧȥ����������֡�
    //������д�ȿ��ǵ������������п��ǵ��ǿ�����������
    //����ǿ�������ôpointer_to_head == nullptr��
    //����Ƿǿ�������ôpointer_to_head == ��һ���ڵ�ĵ�ַ������ʵ����ͷ����������Ĺ��ܡ�
    //��֮������ĺ��ľ���ͷָ��pointer_to_head����ͳ��ȫ�֡�
    temp1->next = pointer_to_head;
    pointer_to_head = temp1;
    return;
  }

  //ʵ���ں����λ�ò�������
  //�������ڱ����Ľڵ�(����Ҫ����Ľڵ㣩��������ָ���һ���ڵ㡣
  //��������һ��������������ڵ�Ҫͨ��forѭ�����ӵ�һ���ڵ㿪ʼ���ܵ���Ҫ�����λ�á�
  //ʵ�������ǿ��Դ���������ַ���ֱ𴢴���һ���ڵ����һ���ڵ�ĵ�ַ��������ʵ����˫���������Ǻ��ˡ�
  //ֵ��ע����ǣ�������˵�ġ������n���ڵ㡱����˼�����½ڵ��Ϊ��n���ڵ㣬��ԭ�ȵ��������ƶ���
  //Ҳ����˵�����յ�����ǣ��½ڵ�ָ���n���ڵ㣬��n-1���ڵ�ָ���½ڵ㡣
  //�½ڵ�һ��ʼ����ĵ�ַ�ǵ�һ���ڵ�ĵ�ַ����ָ���2���ڵ㣬��ôforѭ��n�κ�ָ���n+2���ڵ㡣
  //�����Ϊʲôforѭ����д����i < n - 2������Ҫ���½ڵ�ָ���n���ڵ㡣
  Node* temp2 = pointer_to_head;
  for(int i = 0; i < n - 2; i++)
  {
    temp2 = temp2->next;
  }
  //forѭ����������ʱtemp2���ǵ�n-1���ڵ㣨���ǵ�����˵����temp�Ǹ�������forѭ����һֱ��������temp����ָ���n���ڵ㡣
  //����temp2��ָ����������temp1ֱ��ָ���n���ڵ㡣
  //���жϡ���n-1���ڵ�͵�n���ڵ㣬�õ�n-1���ڵ�ָ���½ڵ㡣
  temp1->next = temp2->next;
  temp2->next = temp1;
  return;
}

//Ҳ����ֻ��һ��������Ĭ��β�����롣
void Insert(int data)
{
  Node* temp1 = new Node();
  temp1->data = data;
  temp1->next = nullptr;

  //��������в����ڣ�
  if(pointer_to_head == nullptr)
  {
    pointer_to_head = temp1;
    return;
  }

  Node* temp2 = pointer_to_head;
  while(temp2->next != nullptr)
  {
    temp2 = temp2->next;
  }
  temp2->next = temp1;
  return;
}

//��ӡ���ܵ�ʵ�֣�������������ӡ����������
void Print()
{
  Node* temp3 = pointer_to_head;
  printf("����");
  while(temp3->next != nullptr)
  {
    printf("%d, ",temp3->data);
    temp3 = temp3->next;
  }
  printf("%d",temp3->data);
  printf("\n");
  return;
}

//ɾ�����ܵ�ʵ�֣�ɾ��������ض��ڵ㡣
void Delete(int n)
{
  Node* temp1 = pointer_to_head;

  //ɾ����һ���ڵ㡣
  if(n == 1)
  {
    pointer_to_head = temp1->next;
    free(temp1);
    return;
  }

  //ɾ��֮��Ľڵ㡣
  for(int i = 0; i < n - 2; i++)
  {
    temp1 = temp1->next;
  }
  //��ʱtemp1�ǵ�n-1���ڵ㡣
  //temp2��Ϊ��n���ڵ㡣
  //Ҫ�õ�n-1���ڵ����ӵ���n+1���ڵ㣬���ͷŵ���n���ڵ���ڴ档
  Node* temp2 = temp1->next;
  temp1->next = temp2->next;
  free(temp2);
  return;
}

//��ת���ܵ�ʵ�֣������������������б��˳��ת������
void Reverse()
{
  //���ǿ���������һ��temp֮��������֮�����ƶ�����������
  //�����ɴ��������ɵģ�temp1��temp2��ǰһ���ڵ㣬temp3��temp2�ĺ�һ���ڵ㡣
  //temp1��ʼ��Ϊnullptr������Ϊ��ת��Ϻ����λ�þ������һ���ڵ�ġ���һ���ڵ㡱��
  Node* temp1 = nullptr;
  Node* temp2 = pointer_to_head;
  Node* temp3; //�Ȳ���ֵ��
  while(temp2 != nullptr) //ȷ��temp2ʼ���������С�
  {
    temp3 = temp2->next; //temp3��temp2����һ���ڵ㡣��temp2�������һ���ڵ�ʱ��temp3����nullptr��
    temp2->next = temp1; //��ת��
    temp1 = temp2; //temp1�����ƶ�һ���ڵ㡣
    temp2 = temp3; //temp2�����ƶ�һ���ڵ㡣���֮ǰtemp2�Ѿ����������һ���ڵ㣬������tmep2�ͻ���nullptr��
  }

  //�����굽���һ���ڵ㣨��temp1��temp2�Ѿ����nullptr�ˣ�����ͷָ��ָ������
  pointer_to_head = temp1;
  return;
}