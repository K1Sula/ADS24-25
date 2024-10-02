#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Structure for a node in the BST
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to insert a value into the BST
TreeNode* insertIntoBST(TreeNode* root, int val, int& level) {
    if (root == nullptr) {
        return new TreeNode(val);
    }
    if (val < root->val) {
        level++;
        root->left = insertIntoBST(root->left, val, level);
    } else {
        level++;
        root->right = insertIntoBST(root->right, val, level);
    }
    return root;
}

// Function to calculate the level sums using BFS
vector<int> calculateLevelSums(TreeNode* root, int& maxLevel) {
    vector<int> levelSums;
    queue<pair<TreeNode*, int>> q; // Queue of (node, level)

    q.push({root, 0});

    while (!q.empty()) {
        TreeNode* node = q.front().first;
        int level = q.front().second;
        q.pop();

        // Ensure the levelSums vector has space for the current level
        if (level >= levelSums.size()) {
            levelSums.push_back(0);
        }

        // Add the node's value to the sum for this level
        levelSums[level] += node->val;
        maxLevel = max(maxLevel, level);

        // Add the children to the queue
        if (node->left != nullptr) {
            q.push({node->left, level + 1});
        }
        if (node->right != nullptr) {
            q.push({node->right, level + 1});
        }
    }

    return levelSums;
}

int main() {
    int n;
    cin >> n;

    vector<int> permutation(n);
    for (int i = 0; i < n; ++i) {
        cin >> permutation[i];
    }

    TreeNode* root = nullptr;
    int maxLevel = 0;

    // Insert the nodes into the BST
    for (int i = 0; i < n; ++i) {
        int level = 0;
        root = insertIntoBST(root, permutation[i], level);
        maxLevel = max(maxLevel, level);
    }

    // Calculate the sum of values for each level
    maxLevel = 0; // Reset maxLevel for the calculation
    vector<int> levelSums = calculateLevelSums(root, maxLevel);

    // Output the results
    cout << maxLevel + 1 << endl; // Maximum level is zero-based, so add 1 for total levels
    for (int sum : levelSums) {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}