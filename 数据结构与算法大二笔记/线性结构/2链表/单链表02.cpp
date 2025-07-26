#include <iostream>

//��C++��ʵ��������ӡ���ܣ��ݹ鷨������ת���ܣ��ݹ鷨����

//�ṹ�嶨��ڵ㡣
struct Node
{
    int data;
    Node* next;
};

//����Ҫʵ�ֵĹ��ܣ���ӡ���ܣ��ݹ鷨������ת���ܣ��ݹ鷨����
void Print(Node* p);
void RevPrint(Node* p); //��ӡ����ת����
void Reverse(Node*& head);

//�Ѿ�ʵ�ֵĹ��ܡ�
void Insert(Node* &head, int data);

int main(void)
{
    //����ͷָ�롣��Ϊ�ֲ�����������Ϊʵ�ʹ����н�������ģ�黯���˼�롣
    Node* head = nullptr;

    Insert(head, 2);
    Insert(head, 4);
    Insert(head, 6);
    Insert(head, 7);
    Insert(head, 8);
    printf("��ӡ����");
    Print(head);
    printf("\n��ӡ��ת����");
    RevPrint(head);
    printf("\n��ת���ӡ����");
    Reverse(head);
    Print(head);

    return 0;
}

//��ӡ���ܵ�ʵ�֣��ݹ鷨����
void Print(Node* p) //��ӡ��ַp�����ݣ�Ȼ����Ծ��p->next�����ظ���
{
    //�˳���������ֹ���޵ݹ顣
    if(p == nullptr)
    {
        return;
    }

    //�ȴ�ӡ�ٵݹ���á�
    printf("%d ", p->data);
    Print(p->next);
    return;
}

void RevPrint(Node* p)
{
    //�˳���������ֹ���޵ݹ顣
    if(p == nullptr)
    {
        return;
    }

    //�ȵݹ�����ٴ�ӡ�������������ȵ������һ���ڵ㣬�����������ӡ��
    RevPrint(p->next);
    printf("%d ", p->data);
    return;
}

//��ת���ܵ�ʵ�֣��ݹ鷨����
void Reverse(Node*& head)
{
    //�˳��������������ڻ��Ѿ��ݹ���õ����һ���ڵ㡣
    if(head == nullptr || head->next == nullptr)
    {
        return;
    }

    //newhead�����µ�ͷָ�롣
    //һ��ʼ����ԭͷָ��һ����
    //���ŵݹ���ã������ϸ��µ����һ���ڵ㣬Ȼ��Ͳ��ٸı䡣
    Node* newhead = head->next;

    //������newhead��������head->next��ԭ��
    //Ҫȷ���ݹ��ж�������ͷָ����޸��ܴ��ݵ���㡣
    //�ݹ������newhead��ָ��ת�����ͷ�ڵ㣬��head->next��������һ�㡣
    //ԭ����ʹ��newhead��ֱ�����ã������޸���Ӱ�쵽��硣
    //��head->next�Ǳ��ʽ���Ǳ������޸�head->next����Ӱ�쵽��硣
    //��������ú�õ�*head��next��Ա�����㣩����������ʱ�����У�Ȼ��������ʱ������
    //�ܽ᣺���ʽ�޷�ֱ�����á�ֻ�б�������ֱ�����á�
    Reverse(newhead);

    //��ת��
    head->next->next = head;
    head->next = nullptr;
    head = newhead;
    return;
}

//���ʹ��Node* head������ֻ�ܶ�headָ��ĵ�һ���ڵ���в�����
//����������Ҫ�ܹ���headָ���Ķ�����Ҳ���Ƕ�head������в���������Ҫ��Node*& head��
void Insert(Node*& head, int data)
{
    Node* temp1 = new Node();
    temp1->data = data;
    temp1->next = nullptr;
    if(head == nullptr)
    {
        head = temp1;
        return;
    }

    Node* temp2 = head;
    while(temp2->next != nullptr)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp1;
    return;
}