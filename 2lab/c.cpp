#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a;
    cin >> a; 

    vector<int> c(a);

    for (int i = 0; i < a; i++) {
        cin >> c[i];
    }

    for (int i = 0; i < a; i++) {
      if(i % 2 == 0){
        cout << c[i] << " ";
    }
    }
    cout << endl; 

    return 0;
}