/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. 
No two characters may map to the same character but a character may map to itself.
*/

#include<bits/stdc++.h>
using namespace std;

// Isomorphic or not

bool isomorphic(string s, string t){

    unordered_map <char, char> m;
    unordered_set <char> x;

    if (s.size() != t.size())
        return false;

    int n = s.size();
    for (int i = 0; i < n; i++){
        if ( m.find( s[i] ) == m.end() ){
            if ( x.find( t[i] ) == x.end() ){
                m[ s[i] ] = t[i];
                x.insert( t[i] );
            }
            else{
                return false;
            }
        }
        else{
            if ( m[ s[i] ] != t[i] ){
                return false;
            }
        }
    }

    return true;
    }

int main(){ 

    string s1 = "foo";
    string s2 = "bar";
    
    cout<<"\n"<<"Result for "<<s1<< " and "<<s2<<" is "<<isomorphic(s1, s2);

    string s3 = "foo";
    string s4 = "add";
    cout<<"\n"<<"Result for "<<s3<< " and "<<s4<<" is "<<isomorphic(s3, s4);


    return 0;
}
