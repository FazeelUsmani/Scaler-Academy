/*

Obsessive String
Problem Description

Given two string A and B consisting of lowercase english letters.
You need to find how many ways are there to extract k (>=1) non-overlapping substrings from A such that each of them contains string B as a substring.

More formally, you need to calculate the number of ways to choose two sequences x1, x2, ..., xk and y1, y2, ..., yk satisfying the following requirements:

1 <= xi, yi <= |A| where (1 <= i <= k)
yi >= xi
xi+1 > yi
string B is the substring of Axi Axi+1 ... Ayi (string A is considered as 1-indexed).
As the number of ways can be rather large print it modulo 109+7.



Problem Constraints
1 <= |A| <= 100000

1 <= |B| <= 100000



Input Format
The first argument is string A.
The second argument is string B.



Output Format
Return number of ways to extract k (>=1) non-overlapping substrings from A such that each of them contains string B as a substring modulo (109+7).



Example Input
Input 1:

 A = "bcbcb" 
 B = "bc"
Input 2:

 A = "bbbc"
 B = "bbbc"


Example Output
Output 1:

 10
Output 2:

 1


Example Explanation
Explanation 1:

 Following are the 10 ways:
    ["bc"]
    ["bcb"]
    ["bcbc"]
    ["bcbcb"]
    ["cbc"]
    ["cbcb"]
    ["bc"]
    ["bcb"]
    ["bc", "bc"]
    ["bc", "bcb"]
Explanation 2:

 The only substring is "bbbc".

*/

#define ll long long
const int md = 1000000007;
const int N = 100005;
int lcp[N];
bool found[N];
ll dp[N],predp[N],prepredp[N];

void clean(int n){
for(int i=0; i<=n; ++i){
dp[i]=0;
predp[i]=0;
prepredp[i]=0;
found[i]=0;
lcp[i]=0;
}
}

int doit(string &s,string &t){
int n = s.size();
int m = t.size();
if(m>n)
return 0;
clean(n);
int j = 0;
for(int i=1;i<m;i++){
while(j>0){
if(t[j] == t[i]){
lcp[i] = ++j;
break;
}
else
j = lcp[j-1];
}
if(j==0){
if(t[i] == t[j])
lcp[i] = ++j;
else
lcp[i] = 0;
}
}
j = 0;
for(int i=0;i<n;i++){
while(j>0){
if(s[i] == t[j]){
j++;
break;
}
else
j = lcp[j-1];
}
if(j==0){
if(s[i] == t[j])
j++;
}
if(j==m){
found[i-m+1] = 1;
}
}
j = -1;
ll ans = 0;
for(int i=m-1;i<n;i++)
{
if(found[i-m+1])
j = i-m+1;
if(j==-1)
continue;
dp[i] = (prepredp[j-1]+j+1)%md;
ans = (ans + dp[i])%md;
predp[i] = (predp[i-1]+dp[i])%md;
prepredp[i] = (prepredp[i-1]+predp[i])%md;
}
return (int)(ans);
}

int Solution::solve(string A, string B) {
return doit(A,B);
}
