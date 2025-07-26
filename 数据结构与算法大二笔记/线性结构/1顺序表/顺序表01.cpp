#include <iostream>

#define MAXSIZE 100 //顺序表容量

// 顺序表结构体定义。
struct SqList
{
  int data[MAXSIZE]; //存放顺序表的元素
  int len; //当前长度
};
 
//要实现的功能：
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
    
  //测试1：初始化测试
  InitList(L);
  std::cout << "===== 测试1：初始化后 =====" << std::endl;
  std::cout << "初始长度: " << ListLength(L) << std::endl; //初始长度为0
  PrintList(L);

  //测试2：插入操作测试
  std::cout << "===== 测试2：插入操作 =====" << std::endl;
    
  //正常插入
  ListInsert(L, 1, 10); //10
  ListInsert(L, 2, 30); //10, 30
  ListInsert(L, 2, 20); //10, 20, 30
  std::cout << "插入3个元素后：" << std::endl;
  PrintList(L); //应显示10, 20, 30

  //头插入
  ListInsert(L, 1, 5); //5, 10, 20, 30
  //尾插入
  ListInsert(L, 5, 40); //5, 10, 20, 30, 40
  std::cout << "添加头尾元素后：" << std::endl;
  PrintList(L); //应显示5, 10, 20, 30, 40

  //错误插入测试
  std::cout << "错误插入测试：" << std::endl;
  bool ret = ListInsert(L, 0, 100); //位置过小
  ret = ListInsert(L, 7, 100); //位置过大
  PrintList(L);

  //测试3：查找操作测试
  std::cout << "===== 测试3：查找操作 =====" << std::endl;
    
  //按位置查找
  try
  {
    std::cout << "位置3的元素: " << GetElem(L, 3) << std::endl; //应输出20
    std::cout << "位置5的元素: " << GetElem(L, 5) << std::endl; //应输出40
        
    //错误位置测试
    std::cout << "尝试获取位置0: ";
    std::cout << GetElem(L, 0) << std::endl;
  } 
  catch (const std::exception& e)
  {
    std::cerr << "!! 捕获异常: " << e.what() << std::endl;
  }

  //按值查找
  std::cout << "\n查找元素20的位置: " << LocateElem(L, 20) << std::endl; //应返回3
  std::cout << "查找不存在的99: " << LocateElem(L, 99) << std::endl; //应返回0

  //测试4：删除操作测试
  std::cout << "\n===== 测试4：删除操作 =====" << std::endl;
    
  // 正常删除中间元素
  ListDelete(L, 3); //删除20
  std::cout << "删除位置3后：" << std::endl;
  PrintList(L); //5, 10, 30, 40

  // 删除头部元素
  ListDelete(L, 1); //删除5
  std::cout << "删除头部后：" << std::endl;
  PrintList(L); //10, 30, 40

  // 删除尾部元素
  ListDelete(L, 3);      //删除40
  std::cout << "删除尾部后：" << std::endl;
  PrintList(L); //10, 30

  // 错误删除测试
  std::cout << "===== 错误删除测试 =====" << std::endl;
  ret = ListDelete(L, 0); //位置过小
  ret = ListDelete(L, 4); //位置过大
  PrintList(L); //10, 30

  //测试5：清空操作测试
  std::cout << "===== 测试5：清空操作 =====" << std::endl;
  while (L.len > 0)
  {
    ListDelete(L, 1); //循环删除首元素
  }
  PrintList(L); //应显示空表
    
  // 空表删除测试
  ret = ListDelete(L, 1);

  return 0;
}

//初始化顺序表。
void InitList(SqList &L)
{
  //不需要操作data数组本身。
  //后续插入时会覆盖原有位置的值。
  L.len = 0;
}

//获取顺序表当前长度。
int ListLength(const SqList &L) //用const因为不需要修改顺序表；用&L不会拷贝临时数组，这样优化性能。
{
  return L.len;
}

//按位置查找元素。
int GetElem(const SqList &L, int i)
{
  if(i < 1 || i > L.len)
  {
    std::cerr << "[ERROR] 位置" << i << "无效，选择的位置不在表内！\n"; //输出异常信息
    throw std::out_of_range("位置" + std::to_string(i) + "无效"); //抛出异常，跳出函数
  }
  return L.data[i - 1];
}

//按值查找元素。
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

//插入元素。
//在列表L的第i个位置插入元素e。
bool ListInsert(SqList &L, int i, int e)
{
  //选择的位置不在表内。
  if(i < 1 || i > L.len + 1) //要写L.len+1，不然无法在表尾插入
  {
    std::cerr << "[ERROR] 位置" << i << "无效，选择的位置不在表内！\n";
    return false;
  }
    
  //顺序表已满。
  if(L.len == MAXSIZE)
  {
    std::cerr << "[ERROR] 顺序表已满！";
    return false;
  }

  //排除所有异常情况，开始插入。
  for(int j = L.len - 1; j >= i - 1; j--)
  {
    L.data[j + 1] = L.data[j];
  }
  L.len++;
  L.data[i - 1] = e;
  return true;
}

//删除元素。
//删除列表L的第i个位置的元素。
bool ListDelete(SqList &L, int i)
{
  //空表情况。
  if (L.len == 0)
  {
    std::cerr << "[ERROR] 顺序表为空，无法删除！\n";
    return false;
  }

  //选择的位置不在表内。
  if(i < 1 || i > L.len)
  {
    std::cerr << "[ERROR] 位置" << i << "无效，选择的位置不在表内！\n";
    return false;
  }

  //排除所有异常情况，开始删除。
  for(int j = i - 1; j < L.len - 1; j++)
  {
    L.data[j] = L.data[j + 1];
  }
  L.len--;
  return true;
}

//打印顺序表。
void PrintList(const SqList& L)
{
  std::cout << "当前顺序表内容（长度为" << L.len << "）：";
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
    std::cout << "空表";
  }
  std::cout << "\n\n";
}