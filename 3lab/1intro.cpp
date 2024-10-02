#include <iostream>
using namespace std;

bool BinarySearch(int arr[], int n, int l, int r) {
    while (l <= r) {
        int middle = l + (r - l) / 2;  // Правильное вычисление среднего индекса
        if (arr[middle] == n) return true;
        else if (arr[middle] < n) l = middle + 1;
        else r = middle - 1;
    }
    return false;
}

int main() {
    int n, target;
    cin >> n;
    int arr[n];  // Ввод массива

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the number: ";
    cin >> target;

    int l = 0, r = n - 1;
    bool result = BinarySearch(arr, target, l, r);  // Вызов бинарного поиска с исправленными аргументами

    if (result) {
        cout << "Yes we find~~";
    } else {
        cout << "No";
    }

    return 0;
}
