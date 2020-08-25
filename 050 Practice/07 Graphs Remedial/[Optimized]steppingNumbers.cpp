#include<bits/stdc++.h>
using namespace std;

vector<int> ans;
void bfs(int n, int m, int num){
    queue<int> q;
    q.push(num);

    while (!q.empty()){
        int stepNum = q.front();
        q.pop();

        if (stepNum >= n && stepNum <= m)
            ans.push_back(stepNum);

        if (num == 0 || stepNum > m)
            continue;
        
        int lastDigit = stepNum%10;
        int stepNumA = stepNum*10 + (lastDigit-1);
        int stepNumB = stepNum*10 + (lastDigit+1);

        if (lastDigit==0)
            q.push(stepNumA);
        else if (lastDigit==9)
            q.push(stepNumB);
        else{
            q.push(stepNumA);
            q.push(stepNumB);
        }
    }
}


int main(){   

    ans.clear();
    int n = 20, m = 300;
    for (int i = n; i < m; ++i)
        bfs(n, m, i);

    sort(ans.begin(), ans.end());

    for (int &x: ans)
        cout<<x<<" ";

    return 0;
}
