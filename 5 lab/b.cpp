#include <iostream>
#include <vector>

using namespace std;

// Helper function to maintain the max-heap property
void heapify(vector<int>& stones, int n, int i) {
    int largest = i;        // Initialize largest as root
    int left = 2 * i + 1;   // Left child
    int right = 2 * i + 2;  // Right child

    // If left child is larger than root
    if (left < n && stones[left] > stones[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && stones[right] > stones[largest])
        largest = right;

    // If largest is not root, swap and continue heapifying
    if (largest != i) {
        swap(stones[i], stones[largest]);
        heapify(stones, n, largest);
    }
}

// Function to build a max-heap
void buildMaxHeap(vector<int>& stones, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(stones, n, i);
    }
}

// Function to remove the largest element from the heap
int extractMax(vector<int>& stones, int& n) {
    if (n <= 0) return 0;  // Edge case: no stones left

    int maxStone = stones[0];
    stones[0] = stones[n - 1];  // Move last element to root
    n--;                        // Reduce heap size
    heapify(stones, n, 0);      // Restore heap property
    return maxStone;
}

int lastStoneWeight(vector<int>& stones) {
    int n = stones.size();
    buildMaxHeap(stones, n);  // Build the max-heap

    // Process the stones until we have one or none left
    while (n > 1) {
        int stone1 = extractMax(stones, n);  // Heaviest stone
        int stone2 = extractMax(stones, n);  // Second heaviest stone

        if (stone1 != stone2) {
            stones[n] = abs(stone1 - stone2);  // Insert the absolute difference back
            n++;                               // Increase the heap size
            heapify(stones, n, 0);             // Restore heap property
        }
    }

    // If one stone remains, return its weight, otherwise return 0
    return (n == 1) ? stones[0] : 0;
}

int main() {
    int n;
    cin >> n;  // Number of stones
    vector<int> stones(n);

    // Input the weights of the stones
    for (int i = 0; i < n; i++) {
        cin >> stones[i];
    }

    // Calculate the last stone weight
    cout << lastStoneWeight(stones) << endl;

    return 0;
}