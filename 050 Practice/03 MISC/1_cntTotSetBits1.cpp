#include<bits/stdc++.h>
using namespace std;

// Function to return the sum of the count
// of set bits in the integers from 1 to n
const int mod=1e9+7;
int countSetBits(int n)
{
    // Ignore 0 as all the bits are unset
    n++;

    // To store the powers of 2
    int powerOf2 = 2;

    // To store the result, it is initialized
    // with n/2 because the count of set
    // least significant bits in the integers
    // from 1 to n is n/2
    int cnt = n / 2;

    // Loop for every bit required to represent n
    while (powerOf2 <= n) {

        // Total count of pairs of 0s and 1s
        int totalPairs = n / powerOf2;

        // totalPairs/2 gives the complete
        // count of the pairs of 1s
        // Multiplying it with the current power
        // of 2 will give the count of
        // 1s in the current bit
        cnt += (totalPairs / 2) * powerOf2;
        cnt%=mod;
        cout<<"first "<<cnt<<endl;

        // If the count of pairs was odd then
        // add the remaining 1s which could
        // not be grouped together
        cnt += (totalPairs & 1) ? (n % powerOf2) : 0;
        cnt%=mod;
        cout<<"second "<<cnt<<endl;
        // Next power of 2
        powerOf2 <<= 1;
    }

    // Return the result
    return cnt;
}
int solve(int A) {
    return countSetBits(A);
}

// int solve(int A) {

//     int setBits[A+1] = {0};
//     setBits[0] = 0;
//     setBits[1] = 1;
//     cout<<"before loop";
    
//     for (int i = 2; i <= A; ++i){
//         cout<<i<<"\n";
//         int index = (i>>1);
//         setBits[i] = setBits[index] + (i&1);        
//     }
    
//     int totalSetBits = 0;
//     for (int x: setBits){
//         cout<<x<<" ";
//         totalSetBits += x;
//     }
    
//     return totalSetBits;
// }


int main(){   

    
    cout<<(solve(18));

    return 0;
}