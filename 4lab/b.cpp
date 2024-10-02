#include <iostream>
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

// Function to find a node in the BST
TreeNode* findNode(TreeNode* root, int target) {
    if (root == nullptr || root->val == target) {
        return root;
    }
    if (target < root->val) {
        return findNode(root->left, target);
    } else {
        return findNode(root->right, target);
    }
}

// Function to calculate the size of the subtree rooted at a given node
int calculateSubtreeSize(TreeNode* node) {
    if (node == nullptr) return 0;
    // Count the current node + size of left subtree + size of right subtree
    return 1 + calculateSubtreeSize(node->left) + calculateSubtreeSize(node->right);
}

int main() {
    int n;
    cin >> n;
    
    TreeNode* root = nullptr;
    
    // Insert nodes into the BST
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        root = insertIntoBST(root, value);
    }
    
    int target;
    cin >> target;
    
    // Find the node in the BST with the value target
    TreeNode* targetNode = findNode(root, target);
    
    // Calculate the size of the subtree rooted at the target node
    int subtreeSize = calculateSubtreeSize(targetNode);
    
    // Output the result
    cout << subtreeSize << endl;
    
    return 0;
}