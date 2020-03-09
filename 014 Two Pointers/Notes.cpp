This file contains all the codes for the problems explained in the class:


1) Given a sorted array, return i,j for any pair of A[i]+A[j] = k

// T.C: O(n)
    
#include<bits/stdc++.h>
using namespace std;

int main(){
    
    vector<int> A{1,3,5,10,20,23,30};
    int n = A.size();
    int k = 15, i = 0, j = n-1;

    while (i < n && j >= 0){
        int sum = A[i]+A[j];
        if (sum == k){
            cout<<"indices are "<<i<<" & "<<j<<" The numbers are "<<A[i]<<" + "<<A[j]<<" = " <<k;
            break;
        }

        else if (sum > k)
            j--;

        else
            i++;  
    }  
    return 0;
}




2) Given a sorted array, return i,j for any pair of A[j]-A[i] = k

#include<bits/stdc++.h>

using namespace std;


int main(){
    
    vector<int> A{1,3,5,10,20,23,30};
    int n = A.size();
    int k = 15, i = 0, j = 1;

    while (j!=n){
        int diff = A[j]-A[i];
        
        if (diff == k){
            cout<<"indexes are "<<i<<" & "<<j<<" The numbers are "<<A[j]<<" - "<<A[i]<<" = " <<k;
            break;
        }

        else if (diff > k)
            i++;

        else
            j++;  
    }       

    return 0;
}




3) Given a sorted array, return i,j,k for which A[i+A[j]+A[k] = x    
    
#include<bits/stdc++.h>
using namespace std;

int main(){
    
    vector<int> A{1,3,5,10,20,23,30};
    int n = A.size();
    int x = 38;

    for (int i = 0; i < n; i++){

        int ans =  x - A[i];
        int j = 0, k = n-1;

        while (j<n && k>=0){
            int sum = A[j]+A[k];

            if (sum == ans){
                cout<<" Indices are "<<i<<" "<<j<<" "<<k<<" having values "<<A[i]<<" + "<<A[j]<<" + "<<A[k]<<" = "<<x<<endl;
                break;
            }

            else if (sum > ans)
                k--;

            else
                j++;
        }       
    }
    
    return 0;
}

                                                  
                                                  
 
                                                 \
                                                 
4) Given an unsorted array find a pair i, j such that the subarray sum is equal to k  

A = [1,3,15,10,20,23,3]
k = 48
                                                  
Output: 
   i,j = 1,4  because 3+15+10+20 = 48                                                  
                                                  
How to do?
i) prefix sum of the given array will be sorted as the array contains only +ve elements
ii) Then find P[j] - P[i] = k

Prefix sum calculation in new array takes space O(n)
Instead you can prefix sum in the given array itself which takes O(1) space

But what if we calculate the sum of subarray on the fly?
I mean just include an end element of subarray if sum < k else exclude starting element of subarray
Take care of the stopping condition as well. 
                                                  
                                                  
                                                  
                                                  
#include<bits/stdc++.h>
using namespace std;

int main(){
    
    
    int A[10] = {1,3,15,10,20,23,3};
    int j = -1, i = 0, sum = 0;
    int k = 48;

    while (j != sizeof(A)/sizeof(int)){
        
        if (sum < k){
            j++;
            sum += A[j];
        }
        else if (sum > k){
            sum -= A[i];
            i++;
        }
        else{
            cout<<"Subset is from "<< i <<" to "<< j;
            break;
        }
        
    }

    return 0;
}

                                                  
                                                  
                                                  
                                                  
5) Given an unsorted array, elements can ve negative check if there exists a sub array with given sum or not?

Prefix array won't work because the elements are negative. Adding a -ve element to the sum decreases the value.
Hence the array will not be sorted. So,  we can't implement 2 pointers if we use this approach.
                                                  So, what to do?
                                                  
                                                
What if we sort the prefix sum array? And find the sum P[j] - P[i] == k. This works because we just need to 
check there exists a pair i, j or not.
                                                  
                                                  
                                                  T.C: O(nlogn)
                                                  
                                                  
                                                  
                                                  
