#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findBlock(const vector<int>& endLines, int mistakeLine) {
    int left = 0, right = endLines.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (endLines[mid] >= mistakeLine) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    int b, m;
    cin >> b >> m;
    vector<int> lines(b);
    for (int i = 0; i < b; i++) {
        cin >> lines[i];
    }
    vector<int> endLines(b);
    endLines[0] = lines[0];
    for (int i = 1; i < b; i++) {
        endLines[i] = endLines[i - 1] + lines[i];
    }
    for (int i = 0; i < m; i++) {
        int mistakeLine;
        cin >> mistakeLine;
        int blockIndex = findBlock(endLines, mistakeLine);
        cout << blockIndex + 1 << endl;
    }
    return 0;
}