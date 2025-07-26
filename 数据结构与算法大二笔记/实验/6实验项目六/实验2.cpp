#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MAX_VERTICES = 100;

vector<int> adj[MAX_VERTICES]; // �ڽӱ�
vector<bool> visited(MAX_VERTICES, false); // ���ʱ��
vector<string> vertexNames; // ��������

// ���������������
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

    cout << "�����붥�����ͱ�����" << endl;
    cin >> vertexCount >> comma >> edgeCount;

    vertexNames.resize(vertexCount);

    cout << "�����붥����Ϣ��" << endl;
    for (int i = 0; i < vertexCount; ++i) {
        cin >> vertexNames[i];
    }

    cout << "������ߵ���Ϣ(��ʽΪ��i,j):" << endl;
    for (int i = 0; i < edgeCount; ++i) {
        int u, v;
        cin >> u >> comma >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // ��Ϊ������ͼ
    }

    cout << "DFS ���������" << endl;
    for (int i = 0; i < vertexCount; ++i) {
        if (!visited[i]) {
            DFS(i); // �������ͨͼ
        }
    }

    cout << endl;
    return 0;
}
