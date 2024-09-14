#include <iostream>
#include <deque>
using namespace std;

int main() {
    char c;
    int n;
    deque<int> n1;
    
    while (cin >> c) {
        if (c == '!') {
            break;  
        } else if (c == '+') {
            cin >> n; 
            n1.push_front(n);
        } else if (c == '-') {
            cin >> n;  
            n1.push_back(n);
        } else if (c == '*') {
            if (!n1.empty()) {
                cout << n1.front() + n1.back() << endl;
                n1.pop_front();
                if (!n1.empty()) {
                    n1.pop_back();
                }
            } else {
                cout << "error" << endl;
            }
        }
    }
    
    return 0;
}
