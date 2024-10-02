#include <iostream>
#include <unordered_map>
using namespace std;

// Node structure for doubly linked list
struct Node {
    char data;
    Node *prev, *next;
    Node(char x) : data(x), prev(nullptr), next(nullptr) {}
};

// Doubly linked list to maintain the order of non-repeating characters
class LinkedList {
public:
    Node *head, *tail;
    LinkedList() : head(nullptr), tail(nullptr) {}

    // Add a node to the end of the list
    void append(char ch) {
        Node *newNode = new Node(ch);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Remove a node from the list
    void remove(Node *node) {
        if (!node) return;
        if (node->prev) node->prev->next = node->next;
        else head = node->next;
        if (node->next) node->next->prev = node->prev;
        else tail = node->prev;
        delete node;
    }

    // Get the first non-repeating character
    string getFirstNonRepeating() {
        return head ? string(1, head->data) : "-1";
    }
};

// Function to process the stream of characters for each test case
void processStream(int n, string stream) {
    unordered_map<char, int> freq; // Frequency map for characters
    unordered_map<char, Node*> nodeMap; // Map to track nodes in the linked list
    LinkedList list;

    // Traverse each character in the stream
    for (int i = 0; i < n; i++) {
        char ch = stream[i];
        freq[ch]++; // Increment frequency

        if (freq[ch] == 1) {
            // If it's the first occurrence, add to linked list
            list.append(ch);
            nodeMap[ch] = list.tail;
        } else if (freq[ch] == 2) {
            // If it's repeating now, remove it from the linked list
            list.remove(nodeMap[ch]);
            nodeMap[ch] = nullptr;
        }

        // Output the first non-repeating character
        cout << list.getFirstNonRepeating() << " ";
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T; // Number of test cases

    while (T--) {
        int N;
        cin >> N; // Number of characters in the stream
        string stream;

        for (int i = 0; i < N; i++) {
            char ch;
            cin >> ch;
            stream += ch;
        }

        processStream(N, stream); // Process the stream for each test case
    }

    return 0;
}