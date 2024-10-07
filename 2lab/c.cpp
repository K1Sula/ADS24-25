#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};

void print(Node *&tail)
{
    int k = 1;
    while (tail != nullptr)
    {
        if (k % 2 == 0)
        {
            cout << tail->data << " ";
        }
        tail = tail->next;
        k++;
    }
}

int main()
{
    int n;
    cin >> n;
    Node *head = nullptr;
    Node* tail = nullptr;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        Node *current = new Node(t);

        if (head == nullptr)
        {
            // First node case
            head = current;
            tail = head;
        }
        else
        {
            // Subsequent nodes
            tail->next = current;
            tail = tail->next;
        }
    }
    print(head);
}
