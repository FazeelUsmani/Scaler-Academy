#include<bits/stdc++.h>
using namespace std;

int atoi(string str){

    int sign = 1, base = 0, i = 0;
    while (str[i] == ' ') { i++; }
    
    if (str[i] == '-' || str[i] == '+') {
        sign = (str[i++] == '-') ? -1 : 1; 
    }
    
    while (str[i] >= '0' && str[i] <= '9') {
        cout<<base<<endl;
        if (base >  INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
            if (sign == 1) return INT_MAX;
            else return INT_MIN;
        }
        base  = 10 * base + (str[i++] - '0');
    }
    return base * sign;
    }

int main(){ 

    string s = "2147483646";
    cout<<atoi(s);

    return 0;
}
