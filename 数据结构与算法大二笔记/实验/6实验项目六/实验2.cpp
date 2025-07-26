#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MAX_VERTICES = 100;

vector<int> adj[MAX_VERTICES]; // 邻接表
vector<bool> visited(MAX_VERTICES, false); // 访问标记
vector<string> vertexNames; // 顶点名称

// 深度优先搜索函数
void DFS(int v) {
    visited[v] = true;
    cout << vertexNames[v] << " ";
    for (int neighbor : adj[v]) {
        if (!visited[neighbor]) {
            DFS(neighbor);
        }
    }
}

int main() {
    int vertexCount, edgeCount;
    char comma;

    cout << "请输入顶点数和边数：" << endl;
    cin >> vertexCount >> comma >> edgeCount;

    vertexNames.resize(vertexCount);

    cout << "请输入顶点信息：" << endl;
    for (int i = 0; i < vertexCount; ++i) {
        cin >> vertexNames[i];
    }

    cout << "请输入边的信息(格式为：i,j):" << endl;
    for (int i = 0; i < edgeCount; ++i) {
        int u, v;
        cin >> u >> comma >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // 因为是无向图
    }

    cout << "DFS 遍历结果：" << endl;
    for (int i = 0; i < vertexCount; ++i) {
        if (!visited[i]) {
            DFS(i); // 处理非连通图
        }
    }

    cout << endl;
    return 0;
}
