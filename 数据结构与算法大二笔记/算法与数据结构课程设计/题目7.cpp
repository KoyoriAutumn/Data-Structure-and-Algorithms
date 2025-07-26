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

  // ������Ĺ�ϣ������h(x) = (2*x + 3) % size
  int hash_function(string phone)
  {
    long long num = stoll(phone);
    return (2 * num + 3) % size;
  }

  // ������ϵ��
  bool insert(Contact contact)
  {
    if (count == size)
    {
      cout << "��ϣ���������޷���������ϵ�ˣ�" << endl;
      return false;
    }

    int index = hash_function(contact.phone);
    int original_index = index;
    vector<int> probe_sequence;

    // ����̽��
    while (!table[index].phone.empty())
    {
      probe_sequence.push_back(index);
      index = (index + 1) % size;
      if (index == original_index)
      {
        cout << "��ϣ���������޷���������ϵ�ˣ�" << endl;
        return false;
      }
    }

    probe_sequence.push_back(index);
    table[index] = contact;
    count++;

    // ����������
    cout << "��������̡�";
    for (int i = 0; i < probe_sequence.size(); i++)
    {
      cout << probe_sequence[i];
      if (i < probe_sequence.size() - 1)
        cout << "~";
    }
    cout << " (��)" << endl;
    cout << "��ϵ���Ѳ��뵽�� " << index << "!" << endl;
    return true;
  }

  // ������ϵ��
  Contact *search(string phone)
  {
    int index = hash_function(phone);
    int original_index = index;
    vector<int> probe_sequence;

    // ����̽��
    while (!table[index].phone.empty())
    {
      probe_sequence.push_back(index);
      if (table[index].phone == phone)
      {
        cout << "�����ҹ��̡�";
        for (int i = 0; i < probe_sequence.size(); i++)
        {
          cout << probe_sequence[i];
          if (i < probe_sequence.size() - 1)
            cout << "~";
        }
        cout << "�����У�" << endl;
        return &table[index];
      }

      index = (index + 1) % size;
      if (index == original_index)
      {
        break;
      }
    }

    // δ�ҵ�
    probe_sequence.push_back(index);
    cout << "�����ҹ��̡�";
    for (int i = 0; i < probe_sequence.size(); i++)
    {
      cout << probe_sequence[i];
      if (i < probe_sequence.size() - 1)
        cout << "~";
    }
    cout << "��δ�ҵ���" << endl;
    return nullptr;
  }

  // ��ʾ������ϵ��
  void display_all()
  {
    cout << "\n===== ���Ź�ϣ�� =====" << endl;
    for (int i = 0; i < size; i++)
    {
      cout << "[" << setw(2) << i << "] ";
      if (table[i].phone.empty())
      {
        cout << "(��)" << endl;
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

// ��ӡϵͳ����
void print_title()
{
  cout << "\n===== ͨѶ¼��ϣ�����ϵͳ =====" << endl;
  cout << "1. ������ϵ��" << endl;
  cout << "2. ������ϵ��" << endl;
  cout << "3. ��ʾȫ����ϵ��" << endl;
  cout << "0. �˳�ϵͳ" << endl;
}

int main()
{
  // ѧ��ĩβ����Ϊ3����ϣ���СΪ3 + 10 = 13
  HashTable contacts(13);

  // ��ʼ��ͨѶ¼��ʹ����Ŀ��ǰ5����ϵ�ˣ�
  contacts.insert(Contact("13812345678", "Li Wei", "Beijing"));
  contacts.insert(Contact("13987654321", "Wang Fang", "Shanghai"));
  contacts.insert(Contact("13623456789", "Zhang Lei", "Guangdong"));
  contacts.insert(Contact("13798765432", "Liu Yang", "Sichuan"));
  contacts.insert(Contact("13534567890", "Chen Hao", "Zhejiang"));

  // ����ʣ����ϵ��
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
    cout << "�����������ţ�";
    cin >> choice;

    switch (choice)
    {
    case 1: // ������ϵ��
      cout << "��������ϵ��������";
      cin.ignore(); // ������뻺����
      getline(cin, name);

      cout << "��������ϵ���ֻ��ţ�";
      cin >> phone;

      cout << "��������ϵ�˵�ַ��";
      cin.ignore(); // ������뻺����
      getline(cin, address);

      contacts.insert(Contact(phone, name, address));
      break;

    case 2: // ������ϵ��
      cout << "������Ҫ���ҵ��ֻ��ţ�";
      cin >> phone;

      if (Contact *result = contacts.search(phone))
      {
        cout << "\n--- ���ҽ�� ---" << endl;
        cout << "������" << result->name << endl;
        cout << "�ֻ��ţ�" << result->phone << endl;
        cout << "��ַ��" << result->address << endl;
      }
      else
      {
        cout << "δ�ҵ��ֻ���Ϊ " << phone << " ����ϵ��" << endl;
      }
      break;

    case 3: // ��ʾ������ϵ��
      contacts.display_all();
      break;

    case 0: // �˳�ϵͳ
      cout << "��лʹ��ͨѶ¼ϵͳ���ټ���" << endl;
      break;

    default:
      cout << "��Ч�����룬������ѡ��" << endl;
    }
  } while (choice != 0);

  return 0;
}