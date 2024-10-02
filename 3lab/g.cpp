#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canDeliverWithCapacity(const vector<int>& children, int capacity, long long flights) {
    long long totalFlights = 0;
    for (int c : children) {
        totalFlights += (c + capacity - 1) / capacity;
    }
    return totalFlights <= flights;
}

int minBagCapacity(int islands, long long flights, const vector<int>& children) {
    int left = 1, right = *max_element(children.begin(), children.end());
    
    while (left < right) {
        int mid = (left + right) / 2;
        if (canDeliverWithCapacity(children, mid, flights)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    int n;
    long long m;
    cin >> n >> m;
    vector<int> children(n);
    for (int i = 0; i < n; ++i) {
        cin >> children[i];
    }
    cout << minBagCapacity(n, m, children) << endl;
    return 0;
}