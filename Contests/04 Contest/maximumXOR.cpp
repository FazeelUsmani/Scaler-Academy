#include <bits/stdc++.h>
using namespace std; 
/*
Efficient approach: Since the XOR of two bits is 1 if and only if they are complementary to each other,
 we need X to have complementary bits to that of N to have the maximum value.
We will iterate from the largest bit (log2(R)th bit) to the lowest (0th bit). 

The following two cases can arise for each bit:

If the bit is not set, i.e. 0, we will try to set it in X. 
If setting this bit to 1 results in X exceeding R, then we will not set it.

If the bit is set, i.e. 1, then we will try to unset it in X.
If the current value of X is already greater than or equal to L, then we can safely unset the bit. 
In the other case, we will check if setting all of the next bits is enough to keep X >= L. 
If not, then we are required to set the current bit. 
Observe that setting all of the next bits is equivalent to adding (1 << b) – 1, where b is the current bit.

The time complexity of this approach is O(log2(R)).
*/

int maximumXOR(int A, int B, int C) 
{ 
    cout<<log2(10)<<" "<<ceil(log2(10))<<" "<<int(3.95415);
	int x = 0; 
	for (int i = ceil(log2(C)); i > -1; i--) { 
		if (A & (1 << i)) { 
			if ((x > C) || (x + (1 << i) - 1 < B)) 
				x ^= (1 << i); 
		} 
		else { 
			if ((x ^ (1 << i)) <= C) 
				x ^= (1 << i); 
		} 
	} 
	return A ^ x; 
} 


int main() 
{ 
	int n = 7, l = 2, r = 23; 
    //int A = 56922971, B = 8452501, C = 48581613;
    int A = 79, B = 59, C = 63;
	cout << "The output is " << maximumXOR(A, B, C); 
	return 0; 
} 


import math

class Solution:
    # @param A : integer
    # @param B : integer
    # @param C : integer
    # @return an integer
    def solve(self, A, B, C):
        
        x = 0;
        
        for i in range(int(math.log2(C)), -1, -1):
            if ( A & ( 1 << i)):
                if (x > C) or (x + (1 << i)-1 < B):
                    x ^= ( 1 << i )
            else:
                if (( x ^ ( 1 << i)) <= C):
                    x ^= ( 1 << i )
                    
                    
        return A ^ x
