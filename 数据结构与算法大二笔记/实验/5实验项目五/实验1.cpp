#include <iostream>
#include <string>
#include <stack>

class BTNode
{
private:
  char data;
  BTNode *left, *right;

public:
  BTNode() : left(nullptr), right(nullptr) {}
  BTNode(char val) : data(val), left(nullptr), right(nullptr) {}
  ~BTNode();
  void InOrder();
  void PostOrder();
  void Insert(std::string str);
};

int main()
{
  std::string preorder;
  std::cout << "请输入先序遍历序列（空节点用 '#' 表示，输入 exit 退出）：\n输入：";
  std::cin >> preorder;
  if (preorder == "exit" || preorder == "EXIT")
  {
    std::cout << "程序已退出。" << std::endl;
    return 0;
  }

  BTNode *root = new BTNode();
  root->Insert(preorder);

  std::cout << "中序遍历序列：";
  root->InOrder();
  std::cout << "\n后序遍历序列：";
  root->PostOrder();
  std::cout << std::endl;
  return 0;
}

BTNode::~BTNode()
{
  delete left;
  delete right;
}

void BTNode::Insert(std::string str)
{
  bool LR = true;         // left or right? true为left，false为right
  bool begin = true;      // 判断是否是第一个字符
  std::stack<BTNode *> Q; // 记录待处理的各个子树

  for (char s : str)
  {
    if (begin)
    {
      this->data = s;
      begin = !begin;
      Q.push(this);
      continue;
    }
    if (s != '#')
    {
      if (LR)
      {
        Q.top()->left = new BTNode(s);
        Q.push(Q.top()->left);
      }
      else if (!LR)
      {
        Q.top()->right = new BTNode(s);
        Q.push(Q.top()->right);
        LR = !LR;
      }
    }
    else if (s == '#')
    {
      if (LR)
      {
        LR = !LR;
      }
      else if (!LR)
      {
        Q.pop();
        /*
        这里不需要切换LR的状态，
        是因为LR为false，s为空，
        意味着栈顶节点的左右子树都已经构造完毕，
        那么就要弹出。
        弹出后，接着构造新栈顶节点。
        有两种可能，构造新栈顶节点的右子树，
        或者右子树也构造完了，那么就再次弹栈。
        不可能去构造一个左子树，因为先序构造总是优先选择构造左子树。
        构造右子树，只是选择剩下的。
        */
      }
    }
  }
}

void BTNode::InOrder()
{
  if (left)
  {
    left->InOrder();
  }
  std::cout << data << ' ';
  if (right)
  {
    right->InOrder();
  }
  return;
}

void BTNode::PostOrder()
{
  if (left)
  {
    left->PostOrder();
  }
  if (right)
  {
    right->PostOrder();
  }
  std::cout << data << ' ';
  return;
}