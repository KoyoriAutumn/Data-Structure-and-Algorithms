#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n, e;
    cout << "请输入顶点数和边数（格式: n,e）: ";
    cin >> n;
    char comma;
    cin >> comma >> e;

    vector<string> vertices(n);
    cout << "请输入每个顶点的名称（每行一个）:\n";
    for (int i = 0; i < n; ++i) {
        cin >> vertices[i];
    }

    // 初始化邻接矩阵
    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));

    cout << "请输入每条边（格式: from,to）:\n";
    for (int i = 0; i < e; ++i) {
        int from, to;
        cin >> from >> comma >> to;
        adjMatrix[from][to] = 1;
    }

    // 输出邻接矩阵
    cout << "\n邻接矩阵:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    // 输出每个顶点的入度、出度和度
    cout << "\n各顶点的度:\n";
    for (int i = 0; i < n; ++i) {
        int outDegree = 0, inDegree = 0;
        for (int j = 0; j < n; ++j) {
            outDegree += adjMatrix[i][j]; // 出度：行求和
            inDegree += adjMatrix[j][i];  // 入度：列求和
        }
        cout << vertices[i] << ": 出度 = " << outDegree << ", 入度 = " << inDegree 
             << ", 总度 = " << (inDegree + outDegree) << endl;
    }

    return 0;
}