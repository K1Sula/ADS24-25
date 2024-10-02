#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> competitors(n);
    for (int i = 0; i < n; ++i) {
        cin >> competitors[i];
    }

    sort(competitors.begin(), competitors.end());

    vector<long long> prefixSum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefixSum[i + 1] = prefixSum[i] + competitors[i];
    }

    int q;
    cin >> q;
    while (q--) {
        int markPower;
        cin >> markPower;

        int count = upper_bound(competitors.begin(), competitors.end(), markPower) - competitors.begin();
        long long sumPower = prefixSum[count];

        cout << count << " " << sumPower << endl;
    }

    return 0;
}