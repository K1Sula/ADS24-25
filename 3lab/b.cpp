#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool can_partition(const vector<int>& ghouls, long long max_sum, int k) {
    long long current_sum = 0;
    int count = 1;
    for (size_t i = 0; i < ghouls.size(); ++i) {
        if (current_sum + ghouls[i] > max_sum) {
            count++;
            current_sum = ghouls[i];
            if (count > k) return false;
        } else {
            current_sum += ghouls[i];
        }
    }
    return true;
}

long long min_max_ghouls(const vector<int>& ghouls, int n, int k) {
    long long left = *max_element(ghouls.begin(), ghouls.end());
    long long right = accumulate(ghouls.begin(), ghouls.end(), 0LL);

    while (left < right) {
        long long mid = (left + right) / 2;
        if (can_partition(ghouls, mid, k)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> ghouls(n);
    for (int i = 0; i < n; ++i) {
        cin >> ghouls[i];
    }
    cout << min_max_ghouls(ghouls, n, k) << endl;
    return 0;
}