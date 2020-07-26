#include<bits/stdc++.h>
using namespace std;

vector<string> solve(vector<string> &A, string B, vector<vector<int> > &C) {

    unordered_map<int, vector<string> > umap;
    int currMax;
    unordered_set<int> s1;
    
    for (string x : A){
        currMax = 0;
        for (int i = 1; i < x.size(); ++i){
            if (x[i] == x[i-1] + 1){
                currMax++;
                if (i == 1)
                    currMax++;
            }
            else{
                currMax = 0;
            }
        }
        s1.insert(currMax);
        umap[currMax].push_back(x);
    }

    for (auto it = umap.begin(); it != umap.end(); ++it){
        int key = it.first;
        

    }

    vector<string> ans;
    
    for (int i = 0; i < C.size(); ++i){
        int cnt = C[i][0];
        char x = C[i][1];
        
        bool flag = false;
        int p = 0;
        
        for (auto t: umap[cnt]){
            
            if (!flag){
                for (int i = 0; i < t.size(); ++i){
                    if (t[i] == x){
                        p++;
                    }
                }
                if (p == cnt){
                    ans.push_back(t);
                    flag = true;
                    break;
                }
            }
        }
        if (!flag)
            ans.push_back("NULL");
    }
    
    return ans;

}


int main(){

    vector<string> A {"abaclmn", "abdwx", "aabc", "oxyps", "ercd"};
    string B = "a";
    vector<vector<int> > C = { {3, 2}, {4, 2} };

    vector<string> ans = solve(A, B, C);

    for (string x : ans)
        cout<<x<<endl;

    return 0;
}