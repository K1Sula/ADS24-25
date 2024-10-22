#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n, k; // n: number of commands, k: number of boxes allowed
    cin >> n >> k;

    priority_queue<int, vector<int>, greater<int>> minHeap; // Min-heap
    long long totalSum = 0; // To keep track of the sum of the largest k cookies

    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;

        if (command == "insert") {
            int cookieCount;
            cin >> cookieCount;

            if (minHeap.size() < k) {
                minHeap.push(cookieCount); // Insert into the min-heap if it hasn't reached size k
                totalSum += cookieCount; // Update the total sum
            } else if (minHeap.size() == k && cookieCount > minHeap.top()) {
                // Only add to the heap if the new cookieCount is larger than the smallest in the heap
                totalSum += cookieCount - minHeap.top(); // Update the total sum
                minHeap.pop(); // Remove the smallest element
                minHeap.push(cookieCount); // Add the new cookieCount
            }
        } else if (command == "print") {
            cout << totalSum << endl; // Print the current total sum of the largest k cookies
        }
    }

    return 0;
}