#include <iostream>
#include <string>
using namespace std;

string processString(const string &s) {
    string result;
    for (char c : s) {
        if (c == '#') {
            if (!result.empty()) {
                result.pop_back();  
            }
        } else {
            result.push_back(c); 
        }
    }
    return result;
}

int main() {
    string s1, s2;

    
    cin >> s1 >> s2;
    if (processString(s1) == processString(s2)) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}
