string v;
bool ok;
int memo[1002][1002];

int dp(int i,int j,int s){
    if(ok)return 1;
    if(s==2){
        ok=true;
        return 1;
    }
    if(i==v.size()||j==v.size())return -(1<<30);
    if(memo[i][j])return memo[i][j];
    for(int k=j;k<v.size();k++){
        if(v[k]==v[i]&&k>i)return memo[i][j]=max(dp(i+1,k+1,s+1),dp(i+1,j,s));
    }
    return memo[i][j]=dp(i+1,j,s);
}


int Solution::anytwo(string A) {
    ok=false;
    memset(memo,0,sizeof(memo));
    v=A;
    int uso=dp(0,0,0);
    return ok;
}
