#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    priority_queue<int,vector<int>,greater<int>>Min_heap;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        Min_heap.push(x);
    }
    int oper=0;
    while(Min_heap.top()<k){
        if (Min_heap.size()<2){
            cout<<-1<<endl;
            return 0;

        }
        int a=Min_heap.top();
        Min_heap.pop();
        int b=Min_heap.top();
        Min_heap.pop();
        int new_den=a+2*b;
        Min_heap.push(new_den);
        oper++;

    }
    cout<<oper<<endl;
}