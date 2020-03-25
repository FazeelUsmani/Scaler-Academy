/*
Largest Rectangle in Histogram
Given an array of integers A of size N. A represents a histogram i.e A[i] denotes height of the ith histogram's bar.
Width of each bar is 1. Largest Rectangle in Histogram: 
Example 1 Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3]. 
Largest Rectangle in Histogram: Example 2 The largest rectangle is shown in the shaded area, which has area = 10 unit. 
Find the area of largest rectangle in the histogram. 

Input Format
The only argument given is the integer array A.
Output Format
Return the area of largest rectangle in the histogram.

For Example
Input 1:
    A = [2, 1, 5, 6, 2, 3]
Output 1:
    10
    Explanation 1:
        The largest rectangle is shown in the shaded area, which has area = 10 unit.
        
    */    
     
   

vector<int> nextSmallerElementLeft(vector<int> arr){

    stack<int> s;
    int n = arr.size();

    vector<int> nextSmaller (n, -1);

    for (int i = n-1; i >= 0; i--){
        
        if (s.empty() || arr[ s.top() ] <= arr[i])
            s.push(i);
        
        else{
            while ( !s.empty() && arr[ s.top() ] > arr[i] ){
                nextSmaller[ s.top() ] = i;
                s.pop();
            }
            s.push(i);
        }
    }
    return nextSmaller;
}

vector<int> nextSmallerElementRight(vector<int> arr){

    stack<int> s;
    int n = arr.size();

    vector<int> nextSmaller (n, n);

    for (int i = 0; i < n; i++){
        
        if (s.empty() || arr[ s.top() ] <= arr[i])
            s.push(i);
        
        else{
            while ( !s.empty() && arr[ s.top() ] > arr[i] ){
                nextSmaller[ s.top() ] = i;
                s.pop();
            }
            s.push(i);
        }
    }
    return nextSmaller;
}



int Solution::largestRectangleArea(vector<int> &arr) {
    
    int n = arr.size();
    
    if (n == 1)
        return arr[0];
    
    vector<int> right = nextSmallerElementRight(arr);
    vector<int> left = nextSmallerElementLeft(arr);

    int maxArea = INT_MIN;

    for (int i = 0; i < n; i++){
        int width = (right[i]-1) - (left[i]+1) + 1;
        
        maxArea = max( maxArea, width*arr[i] );
    }

    return maxArea;
    
}
