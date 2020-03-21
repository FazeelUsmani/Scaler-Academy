#include <bits/stdc++.h>
using namespace std;

string reverse(string s){
    int n = s.size();

    for (int i = 0; i < n/2; i++)
        swap(s[i], s[n-i-1]);

    return s;
}

int main(){

    string x = "the sky is blue";
    stringstream s(x);
    string word;
    string res;
      
    while (s >> word){
        res.append(reverse(word)+" ");
    }
    

    cout<<reverse(res).substr(1);
    
    return 0;
}
