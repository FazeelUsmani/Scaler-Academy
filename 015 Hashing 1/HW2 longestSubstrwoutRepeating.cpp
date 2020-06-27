#include<bits/stdc++.h>
using namespace std;

// This function is used in bruteforce solution [TC: O(N)]
bool areDistinct (string s, int startIndex, int endIndex){
    // TC: O(N) for checking
    vector<bool> visited(26);   // By default all values are false
    for (int i = startIndex; i <= endIndex; ++i){
        if ( visited[s[i]-'a'] == true)
            return false;
        visited[s[i]-'a'] = true;
    }

    return true;
}

// TC: O(N^3)
int bruteforce (string s, int n){

    int maxLength = INT_MIN;
    for (int i = 0; i < n-1; ++i){
        for (int j = i+1; j < n; ++j){
            if (areDistinct(s, i, j) == true)        
                maxLength = max (maxLength, j-i+1);
        }
    }
    return maxLength;    
}

// TC: O(N^2)
int bitOptimized (string s, int n){

    bool vis[26] = {false};
    int currIndex = 0, startIndex = 0, ans = 0;;

    
    for (int i = 0; i < n; ++i){
        bool vis[26] = {false};

        for (int j = i; j < n; ++j){
            if (vis[s[j] - 'a'] == true)
                break;
            else{
                ans = max(ans, j-i+1);
                vis[s[j] - 'a'] = true;
            }
        }
        vis[s[i] - 'a'] = false;
    }
    
    return ans;
}

// TC: O(N)
int optimalSol (string s, int n){

    bool vis[256] = {false};
    int ans = 0;        
    int currIndex = 0, startIndex = 0;

    while (currIndex < n){

        if ( vis[s[currIndex]] == true ){
            
            while (s[startIndex] != s[currIndex]){
                vis[s[startIndex]] = false;
                ++startIndex;                
            }
            ++startIndex;
        }

        else{
            ans = max (ans, currIndex - startIndex + 1);
            vis[s[currIndex]] = true;            
        }        
        ++currIndex;
    }    

    return ans;
}

// TC: O(N)
int optimalSolution2 (string s, int n){

    int ans = 0;
    vector<int> lastIndex(256, -1);
    int i = 0;

    for (int j = 0; j < n; ++j){
        i = max(i, lastIndex[s[j]] + 1);
        ans = max (ans, j-i+1);
        lastIndex[s[j]] = j;
    }

    return ans;
}

int main(){ 

    string s = "abcbe";
    cout<<"Brute force soln is "<<bruteforce(s, s.size())<<endl;
    cout<<"A bit optimized soln is "<<bitOptimized(s, s.size())<<endl;
    cout<<"Optimal soln is "<<optimalSol(s, s.size())<<endl;
    cout<<"2nd Optimal soln is "<<optimalSolution2(s, s.size())<<endl;
    // The Big O time complexity of optimal and 2nd optimal solution is same but the coding style matters in itnerviews

    return 0;
}
