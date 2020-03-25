/*Maximum Rectangle

Given a 2D binary matrix of integers A containing 0's and 1's of size N x M. 
Find the largest rectangle containing only 1's and return its area. 

Note: Rows are numbered from top to bottom and columns are numbered from left to right. 

Input Format
The only argument given is the integer matrix A.

Output Format
Return the area of the largest rectangle containing only 1's.

Constraints
1 <= N, M <= 1000
0 <= A[i] <= 1

For Example
Input 1:
    A = [   [0, 0, 1]
            [0, 1, 1]
            [1, 1, 1]   ]
Output 1:
    4

Input 2:
    A = [   [0, 1, 0, 1]
            [1, 0, 1, 0]    ]
Output 2:
    1
    
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



int maxRectangle (vector<int> arr){

    vector<int> right = nextSmallerElementRight(arr);
    vector<int> left = nextSmallerElementLeft(arr);

    int maxArea = INT_MIN;

    for (int i = 0; i < arr.size(); i++){
        int width = (right[i]-1) - (left[i]+1) + 1;
        maxArea = max(maxArea, width*arr[i]);
    }
    
    return maxArea;
}

int maxRectangle2 (vector<int> arr){
    
    int _max = INT_MIN;
    int cnt = arr[0]; 
    int n = arr.size();
    
    for (int i = 1; i < n; i++){
        if (arr[i] == arr[i-1]){
            cnt += arr[i];
            _max = max(cnt, _max);
        }
        else{
            _max = max(cnt, _max);
            cnt = arr[i];
        }
    }
    
    return _max;
}

int Solution::solve(vector<vector<int> > &arr) {
    
    int m = arr.size();
    int n = arr[0].size();

    vector<vector<int>> temp;
    temp.resize(m*n);

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if ( arr[i][j] == 1 && i-1 >= 0 ){
                temp[i].push_back( arr[i][j] + temp[i-1][j] );
            }
            else{
                temp[i].push_back(arr[i][j]);
            }
        }
    }

    int _max = INT_MIN;

    for (int x = 0; x < m; x++)
        _max = max( maxRectangle(temp[x]), _max );


    return _max;
}
