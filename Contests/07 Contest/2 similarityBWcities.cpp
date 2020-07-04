#include<bits/stdc++.h>
using namespace std;

const int maxn = 1009;
int mask[maxn];   // Bitmask array

vector<int> cities(vector<vector<int> > &A) {
    
    memset(mask, 0, sizeof(mask));
    
    for (vector<int> b : A)
        mask[b[0]] = mask[b[0]] | (1 << (b[1] - 1));
        
    double maxTemp = INT_MIN;
    vector<int> ans{INT_MAX, INT_MAX};
    
    for (int i = 1; i <= 1000; ++i){
        if (mask[i] == 0)
            continue;
        for (int j = i+1; j <= 1000; ++j){
            if (mask[j] == 0)
                continue;
            
            int a = mask[i] | mask[j];   // OR - to get UNION
            int b = mask[i] & mask[j];   // AND - to get INTERSECTION (COMMON)
            
            double a1 = __builtin_popcount(a);
            double b1 = __builtin_popcount(b);
            
            double res;
            res = b1/a1;     // Siminlarity score
            cout<<i<<" "<<j<<" "<<a<<" "<<b<<" "<<a1<<" "<<b1<<" "<<res<<endl;
            if (res > maxTemp){
                maxTemp = res;
                ans = {i,j};
            }
            else if (res == maxTemp){
                
                if (i < ans[0]){
                    ans = {i, j};
                }
                else if(i == ans[0] && j < ans[1]){
                    ans = {i, j};
                }
            }
        }
    }
    
    return ans;
}


int main(){ 

    vector<vector<int> > A = {{1,1}, {1,2}, {1,3}, {1,4}, {2, 5}, {2, 6}, {2, 7}, {3, 8}, {3, 9}, {3, 10}, {4, 1}};

    vector<int> x = cities(A);
    for (int i : x)
        cout<<i<<" ";

        
    return 0;
}
