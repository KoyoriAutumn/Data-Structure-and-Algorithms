#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <iomanip>
using namespace std;

const int INF = INT_MAX; // ��ʾ�����
const int N = 10;        // ��������

// ������Ϣ�ṹ��
struct Spot
{
  int id;
  string chName;
  string enName;
};

// ������Ϣ��ʼ��
Spot spots[N] = {
    {0, "����¥", "Administration Building"},
    {1, "ͼ����Ϣ����", "Library & Information Center"},
    {2, "ʵѵ¥1��¥", "Practice Building No.1"},
    {3, "ʵѵ¥2��¥", "Practice Building No.2"},
    {4, "�ִ���ͨ��������", "Modern Transportation Engineering Center"},
    {5, "��ѧ¥A", "Teaching Building A"},
    {6, "��ѧ¥B", "Teaching Building B"},
    {7, "��ѧ¥C", "Teaching Building C"},
    {8, "����ٳ�", "All-weather Sports Field"},
    {9, "�о���ʳ��", "Graduate Student Canteen"}};

// ��������ڽӾ��󣨵�λ���ף�
int graph[N][N] = {
    {0, 80, INF, INF, 60, INF, INF, INF, INF, INF},
    {80, 0, 50, INF, 70, 90, INF, INF, INF, 100},
    {INF, 50, 0, 40, 75, INF, INF, INF, INF, INF},
    {INF, INF, 40, 0, INF,INF, 90, 60, INF, INF},
    {60, 70, 75, INF, 0, 85, INF, INF, INF, INF},
    {INF, 90, INF, INF, 85, 0, 20, 25, 50, INF},
    {INF, INF, INF, 90, INF, 20, 0, 25, INF, INF},
    {INF, INF, INF, 60, INF, 25, 25, 0, 30, INF},
    {INF, INF, INF, INF, INF, 50, INF, 30, 0, 50},
    {INF, 100, INF, INF, INF, INF, INF, INF, 50, 0}};

// DFS����
vector<int> dfsTraversal(int start)
{
  vector<int> result;
  vector<bool> visited(N, false);
  stack<int> stk;

  stk.push(start);
  visited[start] = true;

  while (!stk.empty())
  {
    int current = stk.top();
    stk.pop();
    result.push_back(current);

    // �����������ջ��֤����˳��
    for (int i = N - 1; i >= 0; i--)
    {
      if (!visited[i] && graph[current][i] != INF && graph[current][i] > 0)
      {
        visited[i] = true;
        stk.push(i);
      }
    }
  }
  return result;
}

// BFS����
vector<int> bfsTraversal(int start)
{
  vector<int> result;
  vector<bool> visited(N, false);
  queue<int> q;

  q.push(start);
  visited[start] = true;

  while (!q.empty())
  {
    int current = q.front();
    q.pop();
    result.push_back(current);

    for (int i = 0; i < N; i++)
    {
      if (!visited[i] && graph[current][i] != INF && graph[current][i] > 0)
      {
        visited[i] = true;
        q.push(i);
      }
    }
  }
  return result;
}

// Dijkstra���·���㷨
pair<vector<int>, int> dijkstra(int start, int end)
{
  vector<int> dist(N, INF);
  vector<int> prev(N, -1);
  vector<bool> visited(N, false);

  dist[start] = 0;

  for (int i = 0; i < N; i++)
  {
    int u = -1;
    for (int j = 0; j < N; j++)
    {
      if (!visited[j] && (u == -1 || dist[j] < dist[u]))
      {
        u = j;
      }
    }

    if (dist[u] == INF)
      break;
    visited[u] = true;

    for (int v = 0; v < N; v++)
    {
      if (graph[u][v] != INF && dist[u] + graph[u][v] < dist[v])
      {
        dist[v] = dist[u] + graph[u][v];
        prev[v] = u;
      }
    }
  }

  // �ؽ�·��
  vector<int> path;
  for (int at = end; at != -1; at = prev[at])
  {
    path.push_back(at);
  }
  reverse(path.begin(), path.end());

  return make_pair(path, dist[end]);
}

int main()
{
  int choice;
  while (true)
  {
    cout << "--- �Ϻ����̼�����ѧУ԰����ϵͳ ---\n";
    cout << "1. ������о�����Ϣ��ͼ�ṹ������\n";
    cout << "2. ��ѯ��������֮������·��\n";
    cout << "0. �˳�ϵͳ\n\n";
    cout << "������ѡ�";
    cin >> choice;

    if (choice == 0)
    {
      break;
    }
    else if (choice == 1)
    {
      int start, method;
      cout << "��������ʼ�����ţ�0-9����";
      cin >> start;
      cout << "��ѡ�������ʽ��1��DFS  2��BFS\n���룺";
      cin >> method;

      vector<int> traversal;
      if (method == 1)
      {
        traversal = dfsTraversal(start);
        cout << "DFS����˳��\n";
      }
      else
      {
        traversal = bfsTraversal(start);
        cout << "BFS����˳��\n";
      }

      // ����������
      for (int i = 0; i < traversal.size(); i++)
      {
        cout << spots[traversal[i]].chName;
        if (i < traversal.size() - 1)
        {
          cout << " -> ";
        }
      }
      cout << "\n\n";
    }
    else if (choice == 2)
    {
      int start, end;
      cout << "��������㾰���ţ�0-9����";
      cin >> start;
      cout << "�������յ㾰���ţ�0-9����";
      cin >> end;

      auto result = dijkstra(start, end);
      vector<int> path = result.first;
      int distance = result.second;

      // ������·��
      cout << "���·����";
      for (int i = 0; i < path.size(); i++)
      {
        cout << spots[path[i]].chName;
        if (i < path.size() - 1)
        {
          cout << " -> ";
        }
      }
      cout << " �ܾ��룺" << distance << "��\n\n";
    }
  }
  return 0;
}