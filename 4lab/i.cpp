#include <iostream>
#include <map>
using namespace std;

// Binary Search Tree class to handle multiplicities
class BSTWithMultiplicity {
public:
    // Map to store the multiplicity of each key
    map<int, int> bst;

    // Insert a key, if it exists increase its multiplicity
    void insert(int x) {
        bst[x]++;
    }

    // Delete a key, decrease its multiplicity by 1
    void delete_key(int x) {
        if (bst.count(x) > 0) {
            bst[x]--;
            if (bst[x] == 0) {
                bst.erase(x);  // Remove the key when multiplicity becomes 0
            }
        }
    }

    // Return the multiplicity of a key
    int cnt(int x) {
        if (bst.count(x) > 0) {
            return bst[x];
        }
        return 0;
    }
};

int main() {
    int q;
    cin >> q;

    BSTWithMultiplicity bst;
    string command;
    int x;

    for (int i = 0; i < q; ++i) {
        cin >> command >> x;
        if (command == "insert") {
            bst.insert(x);
        } else if (command == "delete") {
            bst.delete_key(x);
        } else if (command == "cnt") {
            cout << bst.cnt(x) << endl;
        }
    }

    return 0;
}
