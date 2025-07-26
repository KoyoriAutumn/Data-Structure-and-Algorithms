#include <iostream>

//ʵ��˫����

//�ṹ�嶨��ָ�롣
struct Node
{
    int data;
    Node* next;
    Node* prev; //ָ��ǰһ���ڵ��ָ�롣
};

//����ʵ�֡�
Node* CreateNode(int x); //�����ڵ㡣
void InsertAtHead(Node*& head, int x); //ͷ����ڵ㡣
void InsertAtTail(Node*& head, int x); //β����ڵ㡣
void Print(Node* head); //��ӡ����
void ReversePrint(Node* head); //��ת��ӡ����
void Reverse(Node*& head); //��ת����
void Delete(Node*& head, int n); //ɾ���ض�λ�ýڵ㡣

int main(void)
{
    Node* head = nullptr; //����ͷָ�롣

    printf("һ��ͷ����ڵ�\n");
    InsertAtHead(head, 3);
    InsertAtHead(head, 2);
    InsertAtHead(head, 1);
    Print(head); //1 2 3

    printf("\n\n����β����ڵ�\n");
    InsertAtTail(head, 4);
    InsertAtTail(head, 5);
    InsertAtTail(head, 6);
    Print(head); //1 2 3 4 5 6

    printf("\n\n������ת��ӡ\n");
    ReversePrint(head); //6 5 4 3 2 1

    printf("\n\n�ġ�����ת\n");
    Reverse(head);
    Print(head); //6 5 4 3 2 1
    printf("\n");
    ReversePrint(head); //1 2 3 4 5 6

    printf("\n\n�塢ɾ���ڵ�\n");
    Delete(head, 1);
    Print(head); //5 4 3 2 1
    printf("\n");
    Delete(head, 5);
    Print(head); //5 4 3 2

    return 0;
}

Node* CreateNode(int x)
{
    Node* temp = new Node();
    temp->data = x;
    temp->next = nullptr;
    temp->prev = nullptr;
    return temp;
}

void InsertAtHead(Node*& head, int x)
{
    if(head == nullptr) //�������ڡ�
    {
        head = CreateNode(x);
        return;
    }
    Node* temp = CreateNode(x);
    temp->next = head;
    head->prev = temp;
    head = temp;
    return;
}

void InsertAtTail(Node*& head, int x)
{
    if(head == nullptr) //�������ڡ�
    {
        head = CreateNode(x);
        return;
    }
    Node* temp1 = head;
    while(temp1->next != nullptr)
    {
        temp1 = temp1->next;
    }
    Node* temp2 = CreateNode(x);
    temp2->prev = temp1;
    temp1->next = temp2;
    return;
}

void Print(Node* head)
{
    printf("˳���ӡ��");
    Node* temp = head;
    while(temp != nullptr)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    return;
}

void ReversePrint(Node* head)
{
    printf("�����ӡ��");
    Node* temp = head;
    while(temp->next != nullptr)
    {
        temp = temp->next;
    }
    while(temp != nullptr)
    {
        printf("%d ",temp->data);
        temp = temp->prev;
    }
    return;
}

void Reverse(Node*& head)
{
    Node* temp1 = head;
    if(temp1->next == nullptr)
    {
        return;
    }
    while(temp1 != nullptr)
    {
        Node* temp2;
        
        //����ǰ��ָ�롣
        temp2 = temp1->next;
        temp1->next = temp1->prev;
        temp1->prev = temp2;

        head = temp1;
        temp1 = temp1->prev;
    }
    return;
}

void Delete(Node*& head, int n)
{
    Node* temp = head;
    
    //���ڵ������
    if(temp->next == nullptr && temp->prev == nullptr)
    {
        head = nullptr;
        free(temp);
        return;
    }

    //ɾ����һ���ڵ㡣
    if(n == 1)
    {
        head = temp->next;
        head->prev = nullptr;
        free(temp);
        return;
    }

    //ɾ��֮��Ľڵ㡣

    //����֮��temp��Ҫɾ���Ľڵ㡣
    for(int i = 0;i < n - 1;i++)
    {
        if(temp == nullptr)
        {
            return;
        }
        temp = temp->next;
    }

    //���һ���ڵ�������
    if(temp->next == nullptr)
    {
        temp->prev->next = nullptr;
        free(temp);
        return;
    }

    //ͨ�������
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    return;
}