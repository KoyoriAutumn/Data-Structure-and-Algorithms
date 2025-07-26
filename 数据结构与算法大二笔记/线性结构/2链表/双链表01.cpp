#include <iostream>

//实现双链表。

//结构体定义指针。
struct Node
{
    int data;
    Node* next;
    Node* prev; //指向前一个节点的指针。
};

//功能实现。
Node* CreateNode(int x); //创建节点。
void InsertAtHead(Node*& head, int x); //头插入节点。
void InsertAtTail(Node*& head, int x); //尾插入节点。
void Print(Node* head); //打印链表。
void ReversePrint(Node* head); //反转打印链表。
void Reverse(Node*& head); //反转链表。
void Delete(Node*& head, int n); //删除特定位置节点。

int main(void)
{
    Node* head = nullptr; //创建头指针。

    printf("一、头插入节点\n");
    InsertAtHead(head, 3);
    InsertAtHead(head, 2);
    InsertAtHead(head, 1);
    Print(head); //1 2 3

    printf("\n\n二、尾插入节点\n");
    InsertAtTail(head, 4);
    InsertAtTail(head, 5);
    InsertAtTail(head, 6);
    Print(head); //1 2 3 4 5 6

    printf("\n\n三、反转打印\n");
    ReversePrint(head); //6 5 4 3 2 1

    printf("\n\n四、链表反转\n");
    Reverse(head);
    Print(head); //6 5 4 3 2 1
    printf("\n");
    ReversePrint(head); //1 2 3 4 5 6

    printf("\n\n五、删除节点\n");
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
    if(head == nullptr) //链表不存在。
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
    if(head == nullptr) //链表不存在。
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
    printf("顺序打印：");
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
    printf("逆序打印：");
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
        
        //交换前后指针。
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
    
    //单节点情况。
    if(temp->next == nullptr && temp->prev == nullptr)
    {
        head = nullptr;
        free(temp);
        return;
    }

    //删除第一个节点。
    if(n == 1)
    {
        head = temp->next;
        head->prev = nullptr;
        free(temp);
        return;
    }

    //删除之后的节点。

    //遍历之后temp是要删除的节点。
    for(int i = 0;i < n - 1;i++)
    {
        if(temp == nullptr)
        {
            return;
        }
        temp = temp->next;
    }

    //最后一个节点的情况。
    if(temp->next == nullptr)
    {
        temp->prev->next = nullptr;
        free(temp);
        return;
    }

    //通常情况。
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    return;
}