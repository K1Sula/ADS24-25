#include <iostream>
using namespace std;

bool BinarySearch(int arr[] , int n , int l, int r) {
    while (l <=r) {
        int mid = l + (r -l ) /2;
        if (arr[mid] == n) return true;
        else if(arr[mid] < n) l = mid + 1;
        else r = mid - 1;
    }
    return false;
}

int main() {
    int n,j;
    cin >> n;
    int arr[n];
    for (int i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }
    cin >> j;
    for (int it : arr) {
        if (BinarySearch(arr, j , 0 , n - 1)) {
            cout << "Yes";
            return 0;
        } 
    }
    cout << "No";
}