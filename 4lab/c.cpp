#include <iostream>
using namespace std;

// Structure for a node in the BST
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

// Function to find a node with the value target in the BST
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

// Function to perform pre-order traversal of the subtree
void preorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {
    int n;
    cin >> n;
    
    TreeNode* root = nullptr;
    
    // Insert all gifts into the BST
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        root = insertIntoBST(root, value);
    }
    
    int target;
    cin >> target;
    
    // Find the node with value target
    TreeNode* targetNode = findNode(root, target);
    
    // Perform pre-order traversal starting from the target node
    preorderTraversal(targetNode);
    cout << endl;
    
    return 0;
}