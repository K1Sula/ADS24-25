#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int graph_size; // Размер графа
vector<int> color;
vector<int> discovery;
vector<int> finish;
vector<int> predecessor;
int dfs_time;

void dfs_visit(int u, const vector<vector<int>>& adj) {
    color[u] = 1; // Серый цвет
    discovery[u] = ++dfs_time;
    for (int v : adj[u]) {
        if (color[v] == 0) {
            predecessor[v] = u;
            dfs_visit(v, adj);
        }
    }
    color[u] = 2; // Черный цвет
    finish[u] = ++dfs_time;
}

vector<int> dfs(const vector<vector<int>>& adj) {
    // Инициализация
    color.resize(graph_size, 0); // Белый цвет
    discovery.resize(graph_size, INT_MAX);
    finish.resize(graph_size, INT_MAX);
    predecessor.resize(graph_size, -1);
    dfs_time = 0;

    for (int i = 0; i < graph_size; i++) {
        if (color[i] == 0) {
            dfs_visit(i, adj);
        }
    }

    return finish;
}

int main() {
    graph_size = 6;
    vector<vector<int>> adj = {
        {1, 2},    // Соседи вершины 0
        {0, 3, 4}, // Соседи вершины 1
        {0, 4},    // Соседи вершины 2
        {1, 5},    // Соседи вершины 3
        {1, 2, 5}, // Соседи вершины 4
        {3, 4}     // Соседи вершины 5
    };

    vector<int> finish_times = dfs(adj);

    cout << "Время завершения для каждой вершины:\n";
    for (int i = 0; i < graph_size; ++i) {
        cout << "Вершина " << i << ": " << finish_times[i] << "\n";
    }

    return 0;
}
