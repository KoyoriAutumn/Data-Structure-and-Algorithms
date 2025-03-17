#include <iostream>
using namespace std;

//在C++中实现链表。

//节点的实现。一般我们把新节点命名为temp。
//节点有三要素：
//一是节点本身的地址（temp）;（对这个操作要谨慎——它决定后二者。）
//二是节点保存的数据（temp->data）;
//三是节点指向的下一个节点的地址（temp->next）。
//Node* next说文解字：下一个（next）节点（Node）的地址（*）。
struct Node
{
    int data;
    Node* next;
};

//创建头指针。头指针存储头节点的地址。
//全局变量，可以在任意地方引用。
Node* pointer_to_head;

//链表要实现的两个功能：插入链表和打印链表。
void Insert(int data, int n);
void Print();

int main(void)
{
    //创建一个新节点。
    //首先需要给新节点分配内存空间。
    //先有内存空间，才能谈别的。这就是为什么我们写Node* temp而不是Node temp。
    //Node* temp是我们现在正在创建的这个节点的地址。
    //用Node temp我们反而不能知道。
    Node* temp = new Node();

    //一个简单的测试。
    int a;
    printf("一、创建新节点\n请输入数字：");
    scanf("%d", &a);
    temp->data = a;
    temp->next = NULL;
    printf("数字是%d\n\n", temp->data);

    //实现插入链表。
    //核心是Insert函数。这个函数有两个参数，第一个是要插入的数据，第二个是要插入的位置。
    //要考虑到各种情况，如：这个链表还不存在，要插入的位置不存在（链表还太短），……
    //头指针一开始不存储任何地址，故使用NULL（无效地址）。
    printf("二、插入链表和打印链表\n");
    pointer_to_head = NULL; //创建头指针。链表尚不存在，所以头指针指向NULL。
    Insert(4,1); //链表：4
    Insert(9,2); //链表：4, 9
    Insert(7,3); //链表：4, 9, 7
    Insert(5,2); //链表：4, 5, 9, 7
    Insert(0,1); //链表：0, 4, 5, 9, 7
    Print();

    return 0;
}

void Insert(int data, int n)
{
    //创建新节点。
    Node* temp1 = new Node();
    temp1->data = data;
    temp1->next = NULL;

    //实现创建新链表 or 头部插入链表。
    if(n == 1)
    {
        //不能写temp1->next = NULL，这样在链表已经存在的情况下，会失去后面的链表部分。
        //而这样写既考虑到空链表的情况有考虑到非空链表的情况。
        //如果是空链表，那么pointer_to_head == NULL。
        //如果是非空链表，那么pointer_to_head == 下一个节点的地址。这样实现了头部插入链表的功能。
        //总之，链表的核心就是头指针pointer_to_head。它统摄全局。
        temp1->next = pointer_to_head;
        pointer_to_head = temp1;
        return;
    }

    //实现在后面的位置插入链表。
    //创建用于遍历的节点(不是要插入的节点），先让它指向第一个节点。
    //由于这是一个单向链表，这个节点要通过for循环，从第一个节点开始才能到达要插入的位置。
    //实际上我们可以储存两个地址，分别储存下一个节点和上一个节点的地址。这样就实现了双向链表。这是后话了。
    //值得注意的是，我们所说的“插入第n个节点”，意思是让新节点成为第n个节点，而原先的则往后移动。
    //也就是说，最终的情况是，新节点指向第n个节点，第n-1个节点指向新节点。
    //新节点一开始本身的地址是第一个节点的地址，即指向第2个节点，那么for循环n次后指向第n+2个节点。
    //这就是为什么for循环里写的是i < n - 2。我们要让新节点指向第n个节点。
    Node* temp2 = pointer_to_head;
    for(int i = 0; i < n - 2; i++)
    {
        temp2 = temp2->next;
    }
    //for循环结束。此时temp2就是第n-1个节点（还记得上面说的吗？temp是根本，而for循环里一直操作的是temp），指向第n个节点。
    //有了temp2的指引，可以让temp1直接指向第n个节点。
    //“切断”第n-1个节点和第n个节点，让第n-1个节点指向新节点。
    temp1->next = temp2->next;
    temp2->next = temp1;
    return;
}

void Print()
{
    //实现打印链表。
    Node* temp3 = pointer_to_head;
    printf("链表：");
    while(temp3->next != NULL)
    {
        printf("%d,",temp3->data);
        temp3 = temp3->next;
    }
    printf("%d",temp3->data);
    printf("\n");
    return;
}