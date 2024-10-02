#include <iostream>
using namespace std;

// Structure of a BST node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to insert a node in the BST
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

// Function to count nodes with both left and right children (mini-triangles)
int countMiniTriangles(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    int count = 0;
    if (root->left != nullptr && root->right != nullptr) {
        count = 1; // This node forms a mini-triangle
    }
    return count + countMiniTriangles(root->left) + countMiniTriangles(root->right);
}

int main() {
    int n;
    cin >> n;
    Node* root = nullptr;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        root = insert(root, val);
    }
    
    // Count and output the number of mini-triangles
    cout << countMiniTriangles(root) << endl;
    
    return 0;
}
