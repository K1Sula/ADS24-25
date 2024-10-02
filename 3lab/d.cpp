#include <iostream>
#include <algorithm> // For sort, lower_bound, upper_bound
using namespace std;

const int MAXN = 100005;
int a[MAXN];

int countInRange(int l, int r, int n) {
    // Count number of elements in [l, r] using binary search
    return upper_bound(a, a + n, r) - lower_bound(a, a + n, l);
}

int main() {
    int n, q;
    cin >> n >> q;
    
    // Input the array
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Sort the array to perform binary search for ranges
    sort(a, a + n);
    
    // Process each query
    for (int i = 0; i < q; ++i) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        
        // Calculate number of elements in both ranges
        int count1 = countInRange(l1, r1, n);
        int count2 = countInRange(l2, r2, n);
        
        // To avoid counting elements that are common in both ranges twice,
        // we subtract the intersection count
        if (l2 <= r1 && l1 <= r2) { // If the ranges overlap
            int overlapL = max(l1, l2);
            int overlapR = min(r1, r2);
            int overlapCount = countInRange(overlapL, overlapR, n);
            cout << (count1 + count2 - overlapCount) << endl;
        } else {
            cout << (count1 + count2) << endl;
        }
    }
    
    return 0;
}