#include <iostream>
#include <vector>
#include <map>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++; // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int>& arr, int low, int high) {
    // cout << "Calling sort fuction" << endl;
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(){
    int n;
    cin >> n;

    map<string, string> nicknames;
    for(int i = 0; i < n; i++){
        string s1, s2;
        cin >> s1 >> s2;

        bool found = false;
        for(auto i: nicknames){
            if(i.second == s1){
                nicknames[i.first] = s2;
                found = true;
            }
        }

        if(found == false){
            nicknames[s1] = s2;
        }
    }

    cout << nicknames.size() << endl;
    for(auto i : nicknames){
        cout << i.first << " " << i.second << endl;
    }
}