#include <iostream>
#include <vector>
using namespace std;

// Node structure for a doubly linked list
struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int x) : data(x), next(nullptr), prev(nullptr) {}
};

// Doubly linked list class
class LinkedList
{
public:
    Node *head, *tail;
    LinkedList() : head(nullptr), tail(nullptr) {}

    // Add a node with value x at position p
    void insert(int x, int p)
    {
        Node *newNode = new Node(x);
        if (p == 0)
        {
            newNode->next = head;
            if (head)
                head->prev = newNode;
            head = newNode;
            if (!tail)
                tail = newNode;
        }
        else
        {
            Node *current = head;
            for (int i = 0; i < p - 1; ++i)
                current = current->next;
            newNode->next = current->next;
            if (current->next)
                current->next->prev = newNode;
            current->next = newNode;
            newNode->prev = current;
            if (!newNode->next)
                tail = newNode;
        }
    }

    // Remove a node from position p
    void remove(int p)
    {
        if (!head)
            return;
        Node *current = head;
        if (p == 0)
        {
            head = head->next;
            if (head)
                head->prev = nullptr;
            else
                tail = nullptr;
            delete current;
        }
        else
        {
            for (int i = 0; i < p; ++i)
                current = current->next;
            current->prev->next = current->next;
            if (current->next)
                current->next->prev = current->prev;
            else
                tail = current->prev;
            delete current;
        }
    }

    // Print all values in the list
    void print()
    {
        if (!head)
        {
            cout << "-1\n"; // No extra spaces and exactly one newline
            return;
        }
        Node *current = head;
        bool first = true;
        while (current)
        {
            if (!first)
                cout << " "; // Add space only between elements
            cout << current->data;
            first = false;
            current = current->next;
        }
        cout << endl; // Ensure the output ends with exactly one newline
    }

    // Move a node from position p1 to position p2
    void replace(int p1, int p2)
    {
        if (p1 == p2)
            return;
        Node *current = head;
        for (int i = 0; i < p1; ++i)
            current = current->next;

        // Disconnect the node at p1
        if (current->prev)
            current->prev->next = current->next;
        else
            head = current->next;
        if (current->next)
            current->next->prev = current->prev;
        else
            tail = current->prev;

        // Insert node at p2
        if (p2 == 0)
        {
            current->next = head;
            current->prev = nullptr;
            if (head)
                head->prev = current;
            head = current;
            if (!tail)
                tail = current;
        }
        else
        {
            Node *temp = head;
            for (int i = 0; i < p2 - 1; ++i)
                temp = temp->next;
            current->next = temp->next;
            if (temp->next)
                temp->next->prev = current;
            temp->next = current;
            current->prev = temp;
            if (!current->next)
                tail = current;
        }
    }

    // Reverse the entire list
    void reverse()
    {
        Node *current = head, *prevNode = nullptr;
        tail = head;
        while (current)
        {
            prevNode = current->prev;
            current->prev = current->next;
            current->next = prevNode;
            current = current->prev;
        }
        if (prevNode)
            head = prevNode->prev;
    }

    // Left cyclic shift x times
    void cyclic_left(int x)
    {
        if (!head || x == 0)
            return;
        while (x--)
        {
            Node *temp = head;
            head = head->next;
            head->prev = nullptr;
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
            tail->next = nullptr;
        }
    }

    // Right cyclic shift x times
    void cyclic_right(int x)
    {
        if (!head || x == 0)
            return;
        while (x--)
        {
            Node *temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            temp->next = head;
            head->prev = temp;
            head = temp;
            head->prev = nullptr;
        }
    }
};

int main()
{
    LinkedList list;
    int command;
    while (cin >> command)
    {
        if (command == 0)
        {
            break; // Exit the program
        }
        else if (command == 1)
        {
            int x, p;
            cin >> x >> p;
            list.insert(x, p);
        }
        else if (command == 2)
        {
            int p;
            cin >> p;
            list.remove(p);
        }
        else if (command == 3)
        {
            list.print();
        }
        else if (command == 4)
        {
            int p1, p2;
            cin >> p1 >> p2;
            list.replace(p1, p2);
        }
        else if (command == 5)
        {
            list.reverse();
        }
        else if (command == 6)
        {
            int x;
            cin >> x;
            list.cyclic_left(x);
        }
        else if (command == 7)
        {
            int x;
            cin >> x;
            list.cyclic_right(x);
        }
    }

    return 0;
}