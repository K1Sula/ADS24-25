#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pasture {
    int x1, y1, x2, y2;
};


bool canFitK(const vector<Pasture>& pastures, int n, int K, int L) {
    int count = 0;
    for (int i = 0; i < n; i++) {
    
        if (pastures[i].x2 <= L && pastures[i].y2 <= L) {
            count++;
        }
    }
    return count >= K;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<Pasture> pastures(N);
    for (int i = 0; i < N; i++) {
        cin >> pastures[i].x1 >> pastures[i].y1 >> pastures[i].x2 >> pastures[i].y2;
    }

    int left = 1, right = 1000000000;
    int result = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;

    
        if (canFitK(pastures, N, K, mid)) {
            result = mid;   
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << result << endl;

    return 0;
}