/*
N integers containing only 1,2 and 3

Given an integer A. Find and Return first positive A integers in ascending order containing only digits 1,2 and 3. 

NOTE: all the A integers will fit in 32 bit integer. 

Input Format
The only argument given is integer A.
Output Format
Find and Return first positive A integers in ascending order containing only digits 1,2 and 3.
Constraints
1 <= A <= 29500
For Example
Input 1:
    A = 3
Output 1:
    [1, 2, 3]

Input 2:
    A = 7
Output 2:
    [1, 2, 3, 11, 12, 13, 21]
    
    */
    

vector<int> Solution::solve(int A) {
    
    queue <int> q;

    vector<int> ans;
    
    q.push(1);
    q.push(2);
    q.push(3);

    for (int i=0; i < A; i++){

        int x = q.front();
        ans.push_back(x);
        q.pop();
        q.push(x*10+1);
        q.push(x*10+2);
        q.push(x*10+3);
    }

    return ans;
}
