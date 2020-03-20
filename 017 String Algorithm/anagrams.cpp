/* An anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
   typically using all the original letters exactly once. For example, the word anagram can be rearranged into nag a ram, 
   or the word binary into brainy or the word adobe into abode. Wikipedia
*/

#include <bits/stdc++.h>
using namespace std;

bool anagram(string s1, string s2){

    map<char, int> m1;
    map<char, int> m2;

    int n = s1.size(), m = s2.size();
    
    if (n != m)
        return false;

    for (int i = 0; i < n; i++){
        m1[ s1[i] ]++;
        m2[ s2[i] ]++; 
    }

    if (m1 == m2)
        return true;
    else
        return false;    
}

int main(){
    string s1 = "abgcde";
    string s2 = "gabdce";

    cout<<s1<<" and "<<s2<<" are ";
    printf(anagram(s1,s2) ? "Anagrams" : "not anagrams");

}
