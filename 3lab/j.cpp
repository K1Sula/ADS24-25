#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canStealAllGold(int K, const vector<int>& bags, int H) {
    int hours_needed = 0;
    for (int i = 0; i < bags.size(); ++i) {
        hours_needed += (bags[i] + K - 1) / K;
        if (hours_needed > H) {
            return false;
        }
    }
    return hours_needed <= H;
}

int minimumK(int N, int H, const vector<int>& bags) {
    int low = 1;
    int high = *max_element(bags.begin(), bags.end());
    int result = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canStealAllGold(mid, bags, H)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}

int main() {
    int N, H;
    cin >> N >> H;
    vector<int> bags(N);
    for (int i = 0; i < N; ++i) {
        cin >> bags[i];
    }
    cout << minimumK(N, H, bags) << endl;
    return 0;
}