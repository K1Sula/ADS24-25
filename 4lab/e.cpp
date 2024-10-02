#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

// Structure to represent a node's children
struct Node {
    int left = -1;
    int right = -1;
};

int main() {
    int n;
    cin >> n;
    
    // Edge case: If there's only one node, the width is 1.
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    // Map to store the tree where each node points to its left and right children
    unordered_map<int, Node> tree;

    // Reading the edges and building the tree
    for (int i = 0; i < n - 1; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        if (z == 0) {
            tree[x].left = y;
        } else {
            tree[x].right = y;
        }
    }

    // BFS to calculate the width of each level
    queue<int> q;   // Queue to store the current level nodes
    q.push(1);      // Start BFS from the root (vertex 1)
    int maxWidth = 0;

    while (!q.empty()) {
        int levelSize = q.size();  // The number of nodes at the current level
        maxWidth = max(maxWidth, levelSize);  // Update the maximum width

        // Process all nodes at the current level
        for (int i = 0; i < levelSize; ++i) {
            int current = q.front();
            q.pop();

            // Push the left child if it exists
            if (tree[current].left != -1) {
                q.push(tree[current].left);
            }
            // Push the right child if it exists
            if (tree[current].right != -1) {
                q.push(tree[current].right);
            }
        }
    }

    // Output the maximum width
    cout << maxWidth << endl;

    return 0;
}