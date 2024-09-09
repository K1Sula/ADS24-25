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
    int index = 2;
    cin >> N;
    vector<int> v;
    vector<int> SuperPrime;
    while(1000 > v.size()) {
        bool prime = IsPrimeCheck(num); 
        if (prime == true) {
            v.push_back(num);
        }
        num++;
    }

    while(N > SuperPrime.size() ) {
        bool prime = IsPrimeCheck(index);
        int vari = v[index - 1];
        if (prime == true) {
            SuperPrime.push_back(vari);
        }
        index++;
        
    }
    cout << SuperPrime[SuperPrime.size()-1];
    
    

}