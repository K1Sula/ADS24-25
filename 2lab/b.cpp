#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string word;
    Node *next;

    Node(string word) {
        this->word = word;
        next = nullptr;
    }
};

void insertLL(Node*& head, Node*& tail, string s) {
    Node *newNode = new Node(s);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void changeLL(Node*& head, int target) {
    Node *current = head;
    int index = 0;

    // Печатаем слова начиная с позиции target
    while (current != nullptr) {
        if (index >= target) {
            cout << current->word << " ";
        }
        current = current->next;
        index++;
    }
    // Печатаем слова от начала до позиции target
    current = head;
    index = 0;
    while (current != nullptr && index < target) {
        cout << current->word << " ";
        current = current->next;
        index++;
    }
}

int main() {
    int n, target;
    cin >> n >> target;

    Node *head = nullptr;
    Node *tail = nullptr;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        insertLL(head, tail, s);
    }

    changeLL(head, target);

    return 0;
}
