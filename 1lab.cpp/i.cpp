#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    queue<int> S;
    queue<int> K;
    for(int i=0;i<s.length();i++){
        if(s[i]=='S'){
            S.push(i);
        }
        else{
            K.push(i);
        }
    }
    while(!S.empty() and !K.empty()){
        if(S.front()<K.front()){
            S.push(S.front()+n); //send new index
            S.pop();
            K.pop();
        }
        else if(K.front()<S.front()){
            K.push(K.front()+n); // send new index
            K.pop();
            S.pop();
        }
    }
    if(S.empty()){
        cout<<"KATSURAGI";
    }
    else{
        cout<<"SAKAYANAGI";
    }
}