#include <iostream> 
#include <set> 
using namespace std; 
//WTF
struct Node{ 
    int val; 
    Node * right; 
    Node * left; 
    Node (int val){ 
        this->val = val; 
        right = nullptr; 
        left = nullptr; 
    } 
}; 
 
class BST{ 
public: 
    BST(){ 
        root = nullptr; 
    } 
    Node * root; 
 
    Node * push(Node * cur, int val){ 
        if(cur == nullptr){ 
            return new Node(val); 
        } 
        if(val != cur->val) cur -> right = push(cur->right, val); 
        if(val == cur->val) cur->left = push(cur->left, val); 
        return cur; 
    } 
    void push(int val){ 
        root = push(root, val); 
    } 
    int height(Node * cur){ 
        if(cur == nullptr){ 
            return 0; 
        } 
        return height(cur->left) + 1; 
    } 
 
     
    void solution(set<int> seet){ 
        Node*cur = root; 
        int max = -1; 
        while(cur){ 
             
            if(height(cur) == max) seet.insert(cur->val); 
 
            if(height(cur) > max){ 
                max = height(cur); 
                seet.clear(); 
                seet.insert(cur->val); 
            } 
 
            cur = cur->right; 
        } 
        set<int>::reverse_iterator i;   
        for(i = seet.rbegin(); i != seet.rend(); ++i){ 
            cout<<*i<<" "; 
        } 
        
    } 
}; 
 
int main(){ 
    BST tree; 
    set <int> seet; 
    int n; 
    cin>>n; 
    while(n--){ 
        int k; 
        cin>>k; 
        tree.push(k); 
    } 
 
    tree.solution(seet); 
     
}