#include <iostream>
#include <vector>
#define REMOVE_FIRST(v) v.erase(v.begin())  // Макрос для удаления первого элемента

using namespace std;

int main() {
    vector<int> B(5);// for vector we use simple brackets
    vector<int> N(5);
    int again = 0;
    int moves = 0;
    for (int i = 0 ; i < 5; i++) {
        cin >> B[i];
    }
    for (int i =0 ; i < 5; i++) {
        cin >> N[i];
    }
    while((!B.empty() && !N.empty()) && again < 100000) {
        if(B[0] == N[0]) {
            B.push_back(B[0]);
            N.push_back(N[0]);
            REMOVE_FIRST(B);
            REMOVE_FIRST(N);
        } else if (B[0] == 0 && N[0] == 9) {
            B.push_back(B[0]);
            B.push_back(N[0]);
            REMOVE_FIRST(B);
            REMOVE_FIRST(N);
        } else if (N[0] == 0 && B[0] == 9) {
            N.push_back(B[0]);
            N.push_back(N[0]);
            REMOVE_FIRST(B);
            REMOVE_FIRST(N);
        } else if(B[0] > N[0]) {
            B.push_back(B[0]);
            B.push_back(N[0]);
            REMOVE_FIRST(B);
            REMOVE_FIRST(N);
        } else if (B[0] < N[0]) {
            N.push_back(B[0]);
            N.push_back(N[0]);
            REMOVE_FIRST(B);
            REMOVE_FIRST(N);
        }
        moves++;
        again++;
    }
    if (N.empty()) {
        cout << "Boris " << moves;
    } else if(B.empty()) {
        cout << "Nursik " << moves;
    }

    return 0;
}