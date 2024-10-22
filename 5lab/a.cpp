#include <iostream>
#include <vector>
#include <queue> // for priority queue
using namespace std;

class MinHeap {
private:
    vector<long> heap;
    int n;

public:
    MinHeap(int capacity) {
        heap.resize(capacity + 1);
        n = 0;
    }

    bool isEmpty() {
        return n == 0;
    }

    int size() {
        return n;
    }

    void resize(int capacity) {
        heap.resize(capacity + 1);
    }

    void swap(int a, int b) {
        long temp = heap[a];
        heap[a] = heap[b];
        heap[b] = temp;
    }

    void insert(long val) {
        if (n == heap.size() - 1) {
            resize(2 * heap.size());
        }
        n++;
        heap[n] = val;
        swim(n);
    }

    void swim(int k) {
        while (k > 1 && heap[k / 2] > heap[k]) {
            swap(k / 2, k);
            k /= 2;
        }
    }

    long deleteMin() {
        if (isEmpty()) return 0;
        long min = heap[1];
        swap(1, n);
        n--;
        sink(1);
        heap[n + 1] = 0; // Clear the removed value
        if (n > 0 && n == (heap.size() - 1) / 4) {
            resize(heap.size() / 2);
        }
        return min;
    }

    void sink(int k) {
        while (2 * k <= n) {
            int j = 2 * k;
            if (j < n && heap[j + 1] < heap[j]) j++;
            if (heap[k] <= heap[j]) break;
            swap(k, j);
            k = j;
        }
    }

    void display() {
        for (int i = 1; i <= n; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int m;
    cin >> m;
    MinHeap pq(4); // Initialize the heap with a capacity of 4
    for (int i = 0; i < m; i++) {
        long val;
        cin >> val;
        pq.insert(val);
    }

    long sum = 0;
    while (pq.size() > 1) {
        long first = pq.deleteMin();
        long second = pq.deleteMin();
        sum += first + second;
        pq.insert(first + second);
    }

    cout << sum << endl;
    return 0;
}