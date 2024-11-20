#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int hash_roly_poly(string s,int p){
    int hash = 0;
    int pow = 1;
    for (int i = s.length()-1; i>=0; i--)
    {
        hash = (hash+s.at(i)*pow)%p;
        pow = (pow*128)%p;
    }
    return hash;
}

vector<int> rabin_karp(string text, string pat, int p){
    vector<int> v;
    int hash_i = 0;
    int pow = 1;
    int pow_stored;

    int looking_for = hash_roly_poly(pat,p);

    string s = text.substr(0,pat.length());
    for (int i = s.length()-1; i>=0; i--)
    {
        pow_stored = pow;
        hash_i = (hash_i+s.at(i)*pow)%p;
        pow = (pow*128)%p;
    }

    cout<<s<<"=>"<<hash_i<<endl;

    for (int i = 1; i < text.length()-pat.length()+1; i++)
    {
        
        hash_i = (((((hash_i % p - (text.at(i-1)*pow_stored) % p)) % p)*128) % p 
        + text.at(i+pat.length()-1)) % p;
        hash_i = (hash_i + p)%p;
        cout<<text.at(i-1)<<"|"<<text.at(i+pat.length()-1)<<"|"<<
        text.substr(i,pat.length())<<"|"<<hash_i<<endl;
        if(looking_for == hash_i)
            if(text.substr(i,pat.length()) == pat){
                v.push_back(i);
            }
    }
    

    return v;
}



int main()
{   
    int p = 5003;

    string text = "this is a stringy string";

    string pat = "string";


    for (int i = 0; i < text.length()-pat.length()+1; i++)
    {
        cout<<text.substr(i,pat.length())<<"::"<<hash_roly_poly(text.substr(i,pat.length()),p)<<endl;
    }
    

    
    vector<int> v = rabin_karp(text,pat,p);

    for (int i = 0; i < v.size(); i++)
    {
        cout<<v.at(i)<<" ";
    }
    
    
    return 0;
}