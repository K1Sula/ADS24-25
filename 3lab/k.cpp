#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int minLength = numeric_limits<int>::max();
    int currentSum = 0;
    int start = 0;

    for (int end = 0; end < n; end++) {
        currentSum += arr[end];

        while (currentSum >= k) {
            minLength = min(minLength, end - start + 1);
            currentSum -= arr[start++];
        }
    }

    cout << minLength << endl;

    return 0;
}