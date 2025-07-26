#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class Contact
{
public:
  string phone;
  string name;
  string address;

  Contact() : phone(""), name(""), address("") {}
  Contact(string p, string n, string a) : phone(p), name(n), address(a) {}
};

class HashTable
{
private:
  vector<Contact> table;
  int size;
  int count;

public:
  HashTable(int tableSize) : size(tableSize), count(0)
  {
    table.resize(size);
  }

  // 修正后的哈希函数：h(x) = (2*x + 3) % size
  int hash_function(string phone)
  {
    long long num = stoll(phone);
    return (2 * num + 3) % size;
  }

  // 插入联系人
  bool insert(Contact contact)
  {
    if (count == size)
    {
      cout << "哈希表已满，无法插入新联系人！" << endl;
      return false;
    }

    int index = hash_function(contact.phone);
    int original_index = index;
    vector<int> probe_sequence;

    // 线性探测
    while (!table[index].phone.empty())
    {
      probe_sequence.push_back(index);
      index = (index + 1) % size;
      if (index == original_index)
      {
        cout << "哈希表已满，无法插入新联系人！" << endl;
        return false;
      }
    }

    probe_sequence.push_back(index);
    table[index] = contact;
    count++;

    // 输出插入过程
    cout << "【插入过程】";
    for (int i = 0; i < probe_sequence.size(); i++)
    {
      cout << probe_sequence[i];
      if (i < probe_sequence.size() - 1)
        cout << "~";
    }
    cout << " (空)" << endl;
    cout << "联系人已插入到槽 " << index << "!" << endl;
    return true;
  }

  // 查找联系人
  Contact *search(string phone)
  {
    int index = hash_function(phone);
    int original_index = index;
    vector<int> probe_sequence;

    // 线性探测
    while (!table[index].phone.empty())
    {
      probe_sequence.push_back(index);
      if (table[index].phone == phone)
      {
        cout << "【查找过程】";
        for (int i = 0; i < probe_sequence.size(); i++)
        {
          cout << probe_sequence[i];
          if (i < probe_sequence.size() - 1)
            cout << "~";
        }
        cout << "（命中）" << endl;
        return &table[index];
      }

      index = (index + 1) % size;
      if (index == original_index)
      {
        break;
      }
    }

    // 未找到
    probe_sequence.push_back(index);
    cout << "【查找过程】";
    for (int i = 0; i < probe_sequence.size(); i++)
    {
      cout << probe_sequence[i];
      if (i < probe_sequence.size() - 1)
        cout << "~";
    }
    cout << "（未找到）" << endl;
    return nullptr;
  }

  // 显示所有联系人
  void display_all()
  {
    cout << "\n===== 整张哈希表 =====" << endl;
    for (int i = 0; i < size; i++)
    {
      cout << "[" << setw(2) << i << "] ";
      if (table[i].phone.empty())
      {
        cout << "(空)" << endl;
      }
      else
      {
        cout << table[i].phone << ", "
             << table[i].name << ", "
             << table[i].address << endl;
      }
    }
  }
};

// 打印系统标题
void print_title()
{
  cout << "\n===== 通讯录哈希表查找系统 =====" << endl;
  cout << "1. 插入联系人" << endl;
  cout << "2. 查找联系人" << endl;
  cout << "3. 显示全部联系人" << endl;
  cout << "0. 退出系统" << endl;
}

int main()
{
  // 学号末尾数字为3，哈希表大小为3 + 10 = 13
  HashTable contacts(13);

  // 初始化通讯录（使用题目中前5个联系人）
  contacts.insert(Contact("13812345678", "Li Wei", "Beijing"));
  contacts.insert(Contact("13987654321", "Wang Fang", "Shanghai"));
  contacts.insert(Contact("13623456789", "Zhang Lei", "Guangdong"));
  contacts.insert(Contact("13798765432", "Liu Yang", "Sichuan"));
  contacts.insert(Contact("13534567890", "Chen Hao", "Zhejiang"));

  // 插入剩余联系人
  contacts.insert(Contact("13876543210", "Yang Jing", "Jiangsu"));
  contacts.insert(Contact("13965432109", "Zhao Qiang", "Shandong"));
  contacts.insert(Contact("13654321098", "Sun Yue", "Hunan"));
  contacts.insert(Contact("13743210987", "Zhou Min", "Hubei"));
  contacts.insert(Contact("13532109876", "Hu Xia", "Anhui"));

  int choice;
  string phone, name, address;

  do
  {
    print_title();
    cout << "请输入操作编号：";
    cin >> choice;

    switch (choice)
    {
    case 1: // 插入联系人
      cout << "请输入联系人姓名：";
      cin.ignore(); // 清除输入缓冲区
      getline(cin, name);

      cout << "请输入联系人手机号：";
      cin >> phone;

      cout << "请输入联系人地址：";
      cin.ignore(); // 清除输入缓冲区
      getline(cin, address);

      contacts.insert(Contact(phone, name, address));
      break;

    case 2: // 查找联系人
      cout << "请输入要查找的手机号：";
      cin >> phone;

      if (Contact *result = contacts.search(phone))
      {
        cout << "\n--- 查找结果 ---" << endl;
        cout << "姓名：" << result->name << endl;
        cout << "手机号：" << result->phone << endl;
        cout << "地址：" << result->address << endl;
      }
      else
      {
        cout << "未找到手机号为 " << phone << " 的联系人" << endl;
      }
      break;

    case 3: // 显示所有联系人
      contacts.display_all();
      break;

    case 0: // 退出系统
      cout << "感谢使用通讯录系统，再见！" << endl;
      break;

    default:
      cout << "无效的输入，请重新选择！" << endl;
    }
  } while (choice != 0);

  return 0;
}