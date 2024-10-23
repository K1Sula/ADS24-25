#include <iostream>
#include <vector>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<char>& arr, int low, int high) {
    char pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++; // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<char>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(){
    int n;
    cin >> n;

    vector<char> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    // cout << "inputting char..."<< endl;
    char c;
    cin >> c;

    quickSort(a, 0, n - 1);

    for(int i = 0; i < n; i++){
        if(c == a[i]){
            if(i+1 < n){
                cout << a[i+1];
                return 0;
            }
        }
    }

    cout << a[0];
}