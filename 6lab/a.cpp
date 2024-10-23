#include <bits/stdc++.h>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<char>& arr, int low, int high) {
    char pivot = arr[high]; 
    int i = (low - 1); 

    for (int j = low; j <= high - 1; j++) {

        if (arr[j] < pivot) {
            i++; 
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<char>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(){
    int n;
    cin >> n;

    vector<char> vowels;
    vector<char> consonants;

    for(int i = 0; i < n; i++){
        char c;
        cin >> c;
        if(c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u'){
            vowels.push_back(c);
        }
        else{
            consonants.push_back(c);
        }
    }

    quickSort(vowels, 0, vowels.size() - 1);
    quickSort(consonants, 0, consonants.size() - 1);
    for(auto i: vowels){
        cout << i;
    }
    for(auto i: consonants){
        cout << i;
    }
}