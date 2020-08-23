#include <bits/stdc++.h>
using namespace std;

vector<string> ans;
vector<vector<int> > stick { {}, {}, {1}, {7}, {4}, {2,3,5}, {0,6,9}, {8} };

void recurse(int N, string curr){
    if (N < 0)
        return;
    
    if (N == 0){
        ans.push_back(curr);
        return;
    }
    
    for (int i = 2; i <= min(N, 7); ++i){
        for (int j = 0; j < stick[i].size(); ++j){
            if (stick[i][j] == 0 && curr.size() == 0){
            }
            else{
                curr.push_back(char('0' + stick[i][j]));
                recurse(N-i, curr);
                curr.pop_back();
            }
        }
    }
}

bool myCmp(string a, string b){
    long long x = stoi(a);
    long long y = stoi(b);
    
    return x < y;
}

vector<string> solve(int A) {
    ans.clear();
    recurse(A, "");
    cout<<"executer ";
    sort(ans.begin(), ans.end(), myCmp);

    return ans;
}

int main(){

    vector<string> x = solve(9);

    for (string a: x)
        cout<<a<<endl;

    return 0;
}
