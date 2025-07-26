#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n, e;
    cout << "�����붥�����ͱ�������ʽ: n,e��: ";
    cin >> n;
    char comma;
    cin >> comma >> e;

    vector<string> vertices(n);
    cout << "������ÿ����������ƣ�ÿ��һ����:\n";
    for (int i = 0; i < n; ++i) {
        cin >> vertices[i];
    }

    // ��ʼ���ڽӾ���
    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));

    cout << "������ÿ���ߣ���ʽ: from,to��:\n";
    for (int i = 0; i < e; ++i) {
        int from, to;
        cin >> from >> comma >> to;
        adjMatrix[from][to] = 1;
    }

    // ����ڽӾ���
    cout << "\n�ڽӾ���:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    // ���ÿ���������ȡ����ȺͶ�
    cout << "\n������Ķ�:\n";
    for (int i = 0; i < n; ++i) {
        int outDegree = 0, inDegree = 0;
        for (int j = 0; j < n; ++j) {
            outDegree += adjMatrix[i][j]; // ���ȣ������
            inDegree += adjMatrix[j][i];  // ��ȣ������
        }
        cout << vertices[i] << ": ���� = " << outDegree << ", ��� = " << inDegree 
             << ", �ܶ� = " << (inDegree + outDegree) << endl;
    }

    return 0;
}