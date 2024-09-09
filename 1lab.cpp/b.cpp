#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;


void checking(vector<int> v, int ai ) {
    int min = INT_MAX;
    for (int i = 0; i < v.size(); i++) {
        if(v[i] < min ) {
            min = v[i];
        }
    }
    if ( min <= ai ) {
        cout << min << " ";
    } else {
        cout << "-1" << " ";
    }
}

int main() {
    int N, min = 0;

    cin >> N;
    queue<int> q;
    vector<int> v;
    for (int i = 0; i < N ; i ++) {
        int ai;
        cin >> ai;
        q.push(ai);
    }
    cout << "-1" << " ";
    while (q.empty() == false) {
        v.push_back(q.front());
        q.pop();
        checking(v,q.front());
    }
    return 0;
}