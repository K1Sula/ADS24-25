#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        deque<int> d;
        vector<int> v;
        d.push_back(num);
        for(int i=num-1;i>=1;i--){
            v.push_back(i);
        }
        int x = num-1;
        while(x>0){
            d.push_front(x);
            for(int i=0;i<x;i++){
                d.push_front(d.back());
                d.pop_back();
            }
            x--;
        }
        while(!d.empty()){
            cout<<d.front()<<" ";
            d.pop_front();
        }
        cout<<endl;
    }
}