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
  void Insert(std::string str);
  int Count();
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

  std::cout << "该二叉树中叶子结点的个数为：" << root->Count() << std::endl;
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
      }
    }
  }
}

int BTNode::Count()
{
  int num = 0;
  if (left)
  {
    num += left->Count();
  }
  if (right)
  {
    num += right->Count();
  }
  if (!left && !right)
  {
    return num + 1;
  }
  return num;
}