#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> a, vector<int> b) {
    if (a[2] == b[2]) {
        if (a[1] == b[1]) {
            return a[0] < b[0];
        }
        else
            return a[1] < b[1];
    }
    else
        return a[2] < b[2];
}

int partition(vector<vector<int>>& a, int left, int right) {
    int pivot = right;
    int i = left - 1;
    for (int j = left; j <= right - 1; j++) {
        if (check(a[j], a[pivot])) {
            i++;
            swap(a[j], a[i]);
        }
    }
    swap(a[i + 1], a[pivot]);
    return i + 1;
}

void quickSort(vector<vector<int>>& a, int left, int right) {
    if (left >= right) {
        return;
    }
    
    int index = partition(a, left, right);
    quickSort(a, left, index - 1);
    quickSort(a, index + 1, right);
}

int main() {
    int n; 
    cin >> n;
    vector<vector<int>> dates(n);
    for (int i = 0; i < n; i++) {
        string s; 
        cin >> s;
        
        int d = stoi(s.substr(0, 2));
        int m = stoi(s.substr(3, 2));
        int y = stoi(s.substr(6, 4));
        dates[i].push_back(d);
        dates[i].push_back(m);
        dates[i].push_back(y);
    }
    quickSort(dates, 0, n - 1);
    for (int i = 0; i < n; i++) {
        if (dates[i][0] < 10)
            cout << "0";
        cout << dates[i][0] << "-";

        if (dates[i][1] < 10)
            cout << "0";
        cout << dates[i][1] << "-" << dates[i][2] << endl;
    }

}