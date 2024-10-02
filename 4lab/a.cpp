#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Define the structure of a node in the BST
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to insert a value into the BST
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }
    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    } else {
        root->right = insertIntoBST(root->right, val);
    }
    return root;
}

// Function to check if the path exists in the BST
bool checkPath(TreeNode* root, const string& path) {
    TreeNode* current = root;
    for (char dir : path) {
        if (current == nullptr) return false;
        if (dir == 'L') {
            current = current->left;
        } else if (dir == 'R') {
            current = current->right;
        }
    }
    return current != nullptr;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> bstValues(n);
    for (int i = 0; i < n; ++i) {
        cin >> bstValues[i];
    }
    
    // Create the BST by inserting values
    TreeNode* root = nullptr;
    for (int val : bstValues) {
        root = insertIntoBST(root, val);
    }
    
    // Process each path and check if it exists in the BST
    for (int i = 0; i < m; ++i) {
        string path;
        cin >> path;
        
        // Check if the path is valid in the BST
        if (checkPath(root, path)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}