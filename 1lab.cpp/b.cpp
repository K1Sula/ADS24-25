#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n, ai;
    cin >> n;
    queue<int> q;
    stack<int> s;
    vector<int> result(n, -1); // Вектор для хранения результатов

    for (int i = 0; i < n; i++) {
        cin >> ai;
        q.push(ai);
    }

    s.push(q.front());
    q.pop();
    cout << "-1" << " ";

    while (!q.empty()) {
        int num = q.front();
        while (!s.empty() && s.top() > num) {
            s.pop();
        }
        if (!s.empty()) {
            cout << s.top() << " ";
        } else {
            cout << "-1" << " ";
        }
        s.push(num);
        q.pop();
    }

    return 0;
}
