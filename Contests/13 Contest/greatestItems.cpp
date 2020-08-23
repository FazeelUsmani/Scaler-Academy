#include<bits/stdc++.h>
using namespace std;

string whatChar(int i){
    switch (i)
    {
    case 0:
        return "a";
        break;
    case 1:
        return "b";
        break;
    case 2:
        return "c";
        break;
    case 3:
        return "d";
        break;
    case 4:
        return "e";
        break;
    case 5:
        return "f";
        break;
    case 6:
        return "g";
        break;
    case 7:
        return "h";
        break;
    case 8:
        return "i";
        break;
    case 9:
        return "j";
        break;
    case 10:
        return "k";
        break;
    case 11:
        return "k";
        break;
    case 12:
        return "l";
        break;
    case 13:
        return "m";
        break;
    case 14:
        return "n";
        break;
    case 15:
        return "0";
        break;
    case 16:
        return "p";
        break;
    case 17:
        return "q";
        break;
    case 18:
        return "r";
        break;
    case 19:
        return "s";
        break;
    case 20:
        return "t";
        break;
    case 21:
        return "u";
        break;
    case 22:
        return "v";
        break;
    case 23:
        return "w";
        break;
    case 24:
        return "x";
        break;
    case 25:
        return "y";
        break;
    case 26:
        return "z";
        break;   

    default:
        break;
    }

}

string solve(vector<int> &A, int B) {

    int m1 = INT_MIN;
    for (int x: A)
        m1 = max(m1, x);
    string dp[m1] = "";
    int cnt[B+1][26] = {0};
    string maxEle[B+1][26] = {""};

    // for (int i = 0; i <= B; ++i){
    //     for (int j = 0; j < 26; ++j){
    //         cout<<cnt[i][j]<<" ";
    //         cout<<maxEle[i][j]<<" | ";
    //     }
    //     cout<<endl;
    // }
        
    string maxString;
    for (int i = 0; i < 3; ++i){
        cout<<i<<" "<<whatChar(i)<<endl;
        dp[A[i]] = whatChar(i);
    }
    
    for (string x: dp)
        cout<<x<<" ";
    cout<<endl;

    int i, j;
    for (i = 0; i <= B; ++i){
        for (j = 0; j < i; ++j){
            int x= i-cnt[i][j];
            
        }        
    }

    // int i, j;
    // for (i = 0; i <= B; ++i){
    //     int maxLen = INT_MIN;
    //     for (j = 0; j < i; ++j){
    //         int currLen = dp[j].size();
    //         if (currLen >= maxLen){
    //             //cout<<"inside";
    //             maxLen = currLen;
    //             maxString = dp[j]+dp[i];
    //         }
    //     }
    //     dp[i] = maxString;
    // }

    // for (int i = 0; i <= B; ++i)
    //     cout<<dp[i]<<", ";
    // cout<<endl;

    return "Fazeel";
}

int main(){
    
    vector<int> A{2,2,3};
    int B = 10;
    cout<<solve(A, B);

    
    
    return 0;
}