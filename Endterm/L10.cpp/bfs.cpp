#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<int> bfs(int start, const vector<vector<int>>& adj, int size) {
    vector<int> color(size, 0); // 0 -- white, 1 -- gray, 2 -- black
    vector<int> discovery(size, INT_MAX);
    vector<int> predecessor(size, -1);

    queue<int> Q;
    color[start] = 1;
    discovery[start] = 0;

    Q.push(start);

    while (!Q.empty()) {
        int curr = Q.front();
        Q.pop();

        for (int neighbor : adj[curr]) {
            if (color[neighbor] == 0) {
                color[neighbor] = 1;
                discovery[neighbor] = discovery[curr] + 1;
                predecessor[neighbor] = curr;
                Q.push(neighbor);
            }
        }
        color[curr] = 2;
    }

    return discovery;
}

int main() {
    int size = 6;
    vector<vector<int>> adj = {
        {1, 2},    // Соседи вершины 0
        {0, 3, 4}, // Соседи вершины 1
        {0, 4},    // Соседи вершины 2
        {1, 5},    // Соседи вершины 3
        {1, 2, 5}, // Соседи вершины 4
        {3, 4}     // Соседи вершины 5
    };

    int start = 0; // Начальная вершина
    vector<int> discovery = bfs(start, adj, size);

    cout << "Расстояния от начальной вершины " << start << " до всех остальных вершин:\n";
    for (int i = 0; i < size; ++i) {
        cout << "Вершина " << i << ": " << discovery[i] << "\n";
    }

    return 0;
}
