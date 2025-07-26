#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <iomanip>
using namespace std;

const int INF = INT_MAX; // 表示无穷大
const int N = 10;        // 景点数量

// 景点信息结构体
struct Spot
{
  int id;
  string chName;
  string enName;
};

// 景点信息初始化
Spot spots[N] = {
    {0, "行政楼", "Administration Building"},
    {1, "图文信息中心", "Library & Information Center"},
    {2, "实训楼1号楼", "Practice Building No.1"},
    {3, "实训楼2号楼", "Practice Building No.2"},
    {4, "现代交通工程中心", "Modern Transportation Engineering Center"},
    {5, "教学楼A", "Teaching Building A"},
    {6, "教学楼B", "Teaching Building B"},
    {7, "教学楼C", "Teaching Building C"},
    {8, "风雨操场", "All-weather Sports Field"},
    {9, "研究生食堂", "Graduate Student Canteen"}};

// 修正后的邻接矩阵（单位：米）
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

// DFS遍历
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

    // 按编号逆序入栈保证遍历顺序
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

// BFS遍历
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

// Dijkstra最短路径算法
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

  // 重建路径
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
    cout << "--- 上海工程技术大学校园导游系统 ---\n";
    cout << "1. 浏览所有景点信息（图结构遍历）\n";
    cout << "2. 查询两个景点之间的最短路径\n";
    cout << "0. 退出系统\n\n";
    cout << "请输入选项：";
    cin >> choice;

    if (choice == 0)
    {
      break;
    }
    else if (choice == 1)
    {
      int start, method;
      cout << "请输入起始景点编号（0-9）：";
      cin >> start;
      cout << "请选择遍历方式：1，DFS  2，BFS\n输入：";
      cin >> method;

      vector<int> traversal;
      if (method == 1)
      {
        traversal = dfsTraversal(start);
        cout << "DFS遍历顺序：\n";
      }
      else
      {
        traversal = bfsTraversal(start);
        cout << "BFS遍历顺序：\n";
      }

      // 输出遍历结果
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
      cout << "请输入起点景点编号（0-9）：";
      cin >> start;
      cout << "请输入终点景点编号（0-9）：";
      cin >> end;

      auto result = dijkstra(start, end);
      vector<int> path = result.first;
      int distance = result.second;

      // 输出最短路径
      cout << "最短路径：";
      for (int i = 0; i < path.size(); i++)
      {
        cout << spots[path[i]].chName;
        if (i < path.size() - 1)
        {
          cout << " -> ";
        }
      }
      cout << " 总距离：" << distance << "米\n\n";
    }
  }
  return 0;
}