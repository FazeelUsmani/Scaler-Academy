#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100007;
bool prime[MAXN];

void sieve(int n){
    memset(prime, true, sizeof(prime));
    
    for (int p = 2; p*p <= n; ++p){
        if (prime[p] == true){
            for (int j = p*p; j <= n; ++j){
                prime[j] = false;
            }
        }
    }
}

int gcd(int a, int b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}


int getDiff(int A) {
    cout<<"woohoo ";
        
    int minAns = INT_MAX;
    int start = (A/2)+1;
    for (int i = 1; i < start; ++i){
        int next = A - i;
        if (gcd(i, next) == 1){
            minAns = min(minAns, next-i);
        }
    }
        
    return minAns;
}


int main(){

    cout<<"Ans is "<<getDiff(24); 
    

    return 0;
}
    