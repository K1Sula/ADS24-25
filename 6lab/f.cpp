#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <iomanip>
#include <string>

using namespace std;

map<string, double> grades = {
    {"A+", 4.00},
    {"A", 3.75},
    {"B+", 3.50},
    {"B", 3.00},
    {"C+", 2.50},
    {"C", 2.00},
    {"D+", 1.50},
    {"D", 1.00},
    {"F", 0}
};

struct Students {
    string first, last;
    double gpa;

    Students(string s1, string s2, double gpa) {
        this->last = s1;
        this->first = s2;
        this->gpa = gpa;
    }

    bool check(Students other) {
        if (this->gpa > other.gpa)
            return true;
        else if (this->gpa == other.gpa && this->last > other.last)
            return true;
        else if (this->gpa == other.gpa && this->last == other.last && this->first > other.first)
            return true;
        return false;
    }
};

void heapdown(vector <Students> &a, int n, int i) {
    int l = i * 2 + 1;
    int r = i * 2 + 2;
    int min = i;
    if (l < n && a[l].check(a[min])) {
        min = l;
    }
    if (r < n && a[r].check(a[min])) {
        min = r;
    }
    if (min != i) {
        swap(a[i], a[min]);
        heapdown(a, n, min);
    }
}

void heapS(vector <Students> &a, int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        heapdown(a, n, i);
    
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapdown(a, i, 0);
    }
}

double gpa(pair<string, int> a[], int num) {
    double sum1 = 0;
    double sum2 = 0;
    for (int i = 0; i < num; i++) {
        sum1 += grades[a[i].first] * a[i].second;
        sum2 += a[i].second;
    }
    return sum1/sum2;
}

int main() {
    int n; 
    cin >> n;
    
    vector <Students> students;
    for (int i = 0; i < n; i++) {
        int num; string s1, s2;
        cin >> s1 >> s2 >> num;
        pair <string, int> subjects[num];
        for (int j = 0; j < num; j++) {
            cin >> subjects[j].first >> subjects[j].second;
        }
        students.push_back(Students(s1, s2, gpa(subjects, num)));
    }
    heapS(students, n);
    for (int i = 0; i < n; i++) {
        cout << students[i].last << " " << students[i].first << " ";
        cout << setprecision(3) << fixed << students[i].gpa << endl;
    }
}