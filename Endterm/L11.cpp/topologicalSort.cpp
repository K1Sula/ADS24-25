#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int v, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& Stack) {
    visited[v] = true;

    for (int i : adj[v]) {
        if (!visited[i]) {
            dfs(i, adj, visited, Stack);
        }
    }

    Stack.push(v);
}

vector<int> topologicalSort(int V, vector<vector<int>>& adj) {
    stack<int> Stack;
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, Stack);
        }
    }

    vector<int> result;
    while (!Stack.empty()) {
        result.push_back(Stack.top());
        Stack.pop();
    }

    return result;
}

int main() {
    int V = 6; // Количество вершин
    vector<vector<int>> adj(V);

    // Пример графа
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    vector<int> result = topologicalSort(V, adj);

    cout << "Топологическая сортировка графа:\n";
    for (int i : result) {
        cout << i << " ";
    }

    return 0;
}
