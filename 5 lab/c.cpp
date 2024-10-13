#include <iostream>
#include <vector>

using namespace std;

// Helper functions to maintain the max heap property
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;        // Initialize largest as root
    int left = 2 * i + 1;   // Left child index
    int right = 2 * i + 2;  // Right child index

    // If the left child is larger than the root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If the right child is larger than the largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If the largest is not the root, swap and continue heapifying
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Function to build a max-heap from an unsorted array
void buildHeap(vector<int>& arr, int n) {
    // Index of the last non-leaf node is n / 2 - 1
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

int main() {
    int n, m;  // n: number of rows, m: number of fans
    cin >> n >> m;

    vector<int> seats(n);  // Array to store the seats in each row

    // Input free seats in each row
    for (int i = 0; i < n; i++) {
        cin >> seats[i];
    }

    // Build the max-heap from the seat counts
    buildHeap(seats, n);

    long long total_money = 0;

    // Process all fans by selling tickets
    while (m--) {
        // The maximum number of seats will be at the root of the heap (index 0)
        total_money += seats[0];

        // Reduce the seat count by 1 (as we sell one ticket from this row)
        seats[0]--;

        // After reducing the seat count, heapify to maintain the max-heap property
        heapify(seats, n, 0);
    }

    // Output the total money earned
    cout << total_money << endl;

    return 0;
}