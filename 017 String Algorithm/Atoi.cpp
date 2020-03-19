#include<bits/stdc++.h>
using namespace std;

int atoi(string str){

   int sign = 1, base = 0, i = 0;
    while (str[i] == ' ')
        i++; 

    if (str[i] == '-' || str[i] == '+') 
        sign = (str[i++] == '-') ? -1 : 1; 
        

    while (str[i] >= '0' && str[i] <= '9') {

        if (base >  (INT_MAX-str[i]) / 10) 
            if (sign == 1) return INT_MAX;
            else return INT_MIN;
        
        base  = 10 * base + (str[i++] - '0');
    }

    return base * sign;

    }

int main(){ 

    string s = "7 U 0 T7165 0128862 089 39 5";
    cout<<atoi(s);

    return 0;
}
