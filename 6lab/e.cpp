#include <iostream>
#include <vector>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // pivot
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

void quickSort(vector<int>& arr, int low, int high) {
    // cout << "Calling sort fuction" << endl;
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

vector<vector<int>> transposeVector(const vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<int>> transposed(cols, vector<int>(rows));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }

    return transposed;
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int temp;
            cin >> temp;
            a[i].push_back(temp);
        }
    }

    // for(int i = 0; i < m; i++){
    //     for(int j = 0; j < n; j++){
    //         a[j][i] = a[i][j];
    //     }
    // }

    //check for transpose:

    vector<vector<int>> b;
    b = transposeVector(a);

    // cout << "printting after transpose" << endl;
    // for(int i = 0; i < m; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << b[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    //sort
    for(int i = 0; i < m; i++){
        // cout << "Sorting line: " << i << endl;
        quickSort(b[i], 0, n - 1);
    }

    vector<vector<int>> c;
    c = transposeVector(b);

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         a[j][i] = a[i][j];
    //     }
    // }

    //output

    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j < m; j++){
            cout << c[i][j] << " ";
        }
        cout << endl;
    }

    // for(int i = n - 1; i >= 0; i--){
    //     for(int j = 0; j < m; j++){
    //         cout << a[j][i] << " ";
    //     }
    //     cout << endl;
    // }
}