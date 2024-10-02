#include <iostream>
using namespace std;

struct Node
{
    string data;
    Node *p_link;
    Node *link;
};

class LinkList
{
private:
    Node *head;
    Node *tail;

public:
    LinkList() : head(NULL), tail(NULL) {}

    ~LinkList()
    {
        clear(); // Free memory when the list is destroyed
    }

    bool is_empty() const
    {
        return head == NULL;
    }

    void add_front(string d)
    {
        Node *ptr = new Node();
        ptr->data = d;
        ptr->p_link = NULL;

        if (head == NULL)
        {
            ptr->link = NULL;
            head = ptr;
            tail = ptr;
        }
        else
        {
            ptr->link = head;
            head->p_link = ptr;
            head = ptr;
        }
        cout << "ok" << endl;
    }

    void add_back(string d)
    {
        Node *ptr = new Node();
        ptr->data = d;
        ptr->link = NULL;

        if (head == NULL)
        {
            ptr->p_link = NULL;
            head = ptr;
            tail = ptr;
        }
        else
        {
            tail->link = ptr;
            ptr->p_link = tail;
            tail = ptr;
        }
        cout << "ok" << endl;
    }

    void erase_front()
    {
        if (is_empty())
        {
            cout << "error" << endl;
        }
        else if (head->link == NULL)
        { // One element
            cout << head->data << endl;
            delete head;
            head = NULL;
            tail = NULL;
        }
        else
        {
            cout << head->data << endl;
            Node *temp = head->link;
            delete head;
            temp->p_link = NULL;
            head = temp;
        }
    }

    void erase_back()
    {
        if (is_empty())
        {
            cout << "error" << endl;
        }
        else if (head->link == NULL)
        { // One element
            cout << head->data << endl;
            delete head;
            head = NULL;
            tail = NULL;
        }
        else
        {
            cout << tail->data << endl;
            Node *temp = tail->p_link;
            delete tail;
            temp->link = NULL;
            tail = temp;
        }
    }

    void front() const
    {
        if (!is_empty())
        {
            cout << head->data << endl;
        }
        else
        {
            cout << "error" << endl;
        }
    }

    void back() const
    {
        if (!is_empty())
        {
            cout << tail->data << endl;
        }
        else
        {
            cout << "error" << endl;
        }
    }

    void clear()
    {
        while (head != NULL)
        {
            Node *temp = head->link;
            delete head;
            head = temp;
        }
        tail = NULL;
    }
};

int main()
{
    LinkList L;
    string s;

    while (cin >> s)
    {
        if (s == "exit")
        {
            cout << "goodbye" << endl;
            break;
        }
        else if (s == "add_front")
        {
            string temp;
            cin >> temp;
            L.add_front(temp);
        }
        else if (s == "add_back")
        {
            string temp;
            cin >> temp;
            L.add_back(temp);
        }
        else if (s == "erase_front")
        {
            L.erase_front();
        }
        else if (s == "erase_back")
        {
            L.erase_back();
        }
        else if (s == "front")
        {
            L.front();
        }
        else if (s == "back")
        {
            L.back();
        }
        else if (s == "clear")
        {
            L.clear();
            cout << "ok" << endl;
        }
    }

    return 0;
}