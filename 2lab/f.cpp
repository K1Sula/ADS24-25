#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

// Function to insert a new node at the given position
Node* insertNode(Node* head, int data, int position) {
    Node* newNode = new Node(data);
    
    // If inserting at the head (position 0)
    if (position == 0) {
        newNode->next = head;
        return newNode;
    }

    // Find the node at the (position - 1)
    Node* current = head;
    for (int i = 0; i < position - 1 && current != nullptr; ++i) {
        current = current->next;
    }

    // Insert the new node after the (position - 1) node
    if (current != nullptr) {
        newNode->next = current->next;
        current->next = newNode;
    }

    return head;
}

// Function to print the list (used in locked code)
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    // Initialize the linked list
    Node* head = nullptr;
    Node* tail = nullptr;

    // Read the initial list elements
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Read the data to insert and the position
    int data, position;
    cin >> data >> position;

    // Insert the new node and return the modified list
    head = insertNode(head, data, position);

    // Print the modified list
    printList(head);

    return 0;
}