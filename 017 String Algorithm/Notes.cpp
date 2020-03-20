// Given a string, find first non-repeating character

#include<bits/stdc++.h>
using namespace std;

// Finding first non-repeating char

char non(string str){
    map<char, int> m;

    for (int i = 0; i < str.size(); i++)
        m[ str[i] ]++;

    for (int i = 0; i < str.size(); i++)
        if ( m[str[i]] == 1)
            return str[i];
    
    }

int main(){ 

    string s = "interviewbit";

    cout<<"\n"<<"Result is "<<non(s);

    return 0;
}
