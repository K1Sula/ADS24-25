#include <iostream>
#include <string>
#include <vector>

using namespace std;

//written by n-n06;

int hash_rolling(string s, int p) {
    int h = 0;
    int pow = 1;
    for (int i = s.length() - 1; i >= 0; i--) {
        h = (h + (int)s.at(i) * pow) % p;
        pow = (pow * p) % p;
    }
    return h;
}

vector<int> rabin_karp(string text, string pattern, int p) {
    int n = text.length();
    int m = pattern.length();

    vector<int> positions;

    int target_hash = hash_rolling(pattern, p);

    int hash_i = 0;
    int pow = 1;
    int pow_store;

    for (int i = m - 1; i >= 0; i--) {
        pow_store = pow;
        hash_i = (hash_i + (int)text.at(i) * pow) % p;
        pow = (pow * p) % p;
    }
    
    if (hash_i == target_hash && text.substr(0, m) == pattern) {
        positions.push_back(0);
    }

    for (int i = 1; i <= n - m; i++) {
        hash_i = (((hash_i - ((int)text.at(i - 1)%p)) * pow_store) * 128 % p + text.at(i + m - 1)) % p;
        if (hash_i == target_hash) {
            if (text.substr(i, m) == pattern)
                positions.push_back(i);
        }
    }

    return positions;
}



int main() {
    int p = 5003;
    string s = "this is a large string";
    string pattern = "string";

    vector<int> v1 = rabin_karp(s, pattern, p);
    for (int x : v1) {
        cout << x << " "; // Correct : 16
    }
    cout << endl;
    vector<int> v2 = rabin_karp(s, "larg", p);
    for (int x : v2) {
        cout << x << " "; // Correct : 10
    }
}