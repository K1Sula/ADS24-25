#include <bits/stdc++.h> 
using namespace std; 
int main(){ 
    string s; 
    cin>>s; 
    stack<char> st; 
    for(char elem: s){ 
    if(!st.empty() and elem==st.top()){ 
        st.pop(); 
    } 
    else{ 
        st.push(elem); 
    } 
    } 
    if(st.empty()){ 
        cout<<"YES"; 
    } 
    else{ 
        cout<<"NO"; 
    } 
}