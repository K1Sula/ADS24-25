#include <iostream>
#include <vector>

using namespace std;

bool IsPrimeCheck(int number) {
    for (int i = 2 ; i * i  <= number ; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int N, num = 2 ;
    cin >> N;
    vector<int> v;
    while(N > v.size()) {
        bool prime = IsPrimeCheck(num); 
        if (prime == true) {
            v.push_back(num);
        }
        num++;
    }
    int size = v.size();
    cout << v[size-1];

}