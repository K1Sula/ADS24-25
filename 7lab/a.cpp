#include <iostream>
using namespace std;

void Merge(int arr[], int l, int mid, int r) {
    int i = l;
    int j = mid + 1;
    int k = 0;
    int temp[r - l + 1];  // Временный массив размера (r - l + 1)

    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    // Копируем оставшиеся элементы
    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= r) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    // Копируем из temp обратно в arr
    for (int m = 0; m < k; m++) {
        arr[l + m] = temp[m];
    }
}

void MergeSort(int arr[], int l, int r) {
    if (l < r) {  // Изменено условие
        int mid = l + (r - l) / 2;
        MergeSort(arr, l, mid);
        MergeSort(arr, mid + 1, r);
        Merge(arr, l, mid, r);
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    MergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
