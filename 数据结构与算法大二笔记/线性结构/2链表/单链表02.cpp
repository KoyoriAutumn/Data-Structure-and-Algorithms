#include <iostream>

//在C++中实现链表：打印功能（递归法）、反转功能（递归法）。

//结构体定义节点。
struct Node
{
    int data;
    Node* next;
};

//链表要实现的功能：打印功能（递归法）、反转功能（递归法）。
void Print(Node* p);
void RevPrint(Node* p); //打印出反转链表。
void Reverse(Node*& head);

//已经实现的功能。
void Insert(Node* &head, int data);

int main(void)
{
    //创建头指针。设为局部变量，是因为实际工作中讲究的是模块化编程思想。
    Node* head = nullptr;

    Insert(head, 2);
    Insert(head, 4);
    Insert(head, 6);
    Insert(head, 7);
    Insert(head, 8);
    printf("打印链表：");
    Print(head);
    printf("\n打印反转链表：");
    RevPrint(head);
    printf("\n反转后打印链表：");
    Reverse(head);
    Print(head);

    return 0;
}

//打印功能的实现（递归法）。
void Print(Node* p) //打印地址p的数据，然后跳跃到p->next，再重复。
{
    //退出条件，防止无限递归。
    if(p == nullptr)
    {
        return;
    }

    //先打印再递归调用。
    printf("%d ", p->data);
    Print(p->next);
    return;
}

void RevPrint(Node* p)
{
    //退出条件，防止无限递归。
    if(p == nullptr)
    {
        return;
    }

    //先递归调用再打印。这样函数会先到达最后一个节点，再往回逐个打印。
    RevPrint(p->next);
    printf("%d ", p->data);
    return;
}

//反转功能的实现（递归法）。
void Reverse(Node*& head)
{
    //退出条件：链表不存在或已经递归调用到最后一个节点。
    if(head == nullptr || head->next == nullptr)
    {
        return;
    }

    //newhead储存新的头指针。
    //一开始它和原头指针一样。
    //随着递归调用，它不断更新到最后一个节点，然后就不再改变。
    Node* newhead = head->next;

    //这里用newhead而不能用head->next的原因：
    //要确保递归中对子链表头指针的修改能传递到外层。
    //递归结束后，newhead会指向反转后的新头节点，而head->next做不到这一点。
    //原因是使用newhead能直接引用，所以修改能影响到外界。
    //而head->next是表达式而非变量。修改head->next不能影响到外界。
    //它会解引用后得到*head的next成员（运算），保存在临时变量中，然后引用临时变量。
    //总结：表达式无法直接引用。只有变量才能直接引用。
    Reverse(newhead);

    //反转。
    head->next->next = head;
    head->next = nullptr;
    head = newhead;
    return;
}

//如果使用Node* head，我们只能对head指向的第一个节点进行操作。
//而这里我们要能够让head指向别的东西，也就是对head本身进行操作，所以要用Node*& head。
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