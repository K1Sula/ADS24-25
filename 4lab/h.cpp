#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    Node* root;
    int sum;

    BinarySearchTree() : root(nullptr), sum(0) {}

    Node* add(int data) {
        root = recursivelyInsert(data, root);
        return root;
    }

    Node* recursivelyInsert(int data, Node* root) {
        if (root == nullptr) {
            return new Node(data);
        }
        if (root->data >= data) {
            root->left = recursivelyInsert(data, root->left);
        } else {
            root->right = recursivelyInsert(data, root->right);
        }
        return root;
    }

    void newValuesForTree(Node* node) {
        if (node == nullptr) {
            return;
        }
        newValuesForTree(node->right);
        sum += node->data;
        node->data = sum;
        newValuesForTree(node->left);
    }

    void printValues(Node* node) {
        if (node == nullptr) {
            return;
        }
        printValues(node->right);
        cout << node->data << " ";
        printValues(node->left);
    }
};

int main() {
    int size;
    cin >> size;
    vector<int> array(size);
    
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }

    BinarySearchTree bst;
    for (int i : array) {
        bst.add(i);
    }

    bst.newValuesForTree(bst.root);
    bst.printValues(bst.root);
    
    return 0;
}
