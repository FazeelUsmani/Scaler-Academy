/*

Number of islands
Problem Description

Given a matrix of integers A of size N x M consisting of 0 and 1. A group of connected 1's forms an island. 
From a cell (i, j) such that A[i][j] = 1 you can visit any cell that shares a corner with (i, j) and value in that cell is 1.

More formally, from any cell (i, j) if A[i][j] = 1 you can visit:

(i-1, j) if (i-1, j) is inside the matrix and A[i-1][j] = 1.
(i, j-1) if (i, j-1) is inside the matrix and A[i][j-1] = 1.
(i+1, j) if (i+1, j) is inside the matrix and A[i+1][j] = 1.
(i, j+1) if (i, j+1) is inside the matrix and A[i][j+1] = 1.
(i-1, j-1) if (i-1, j-1) is inside the matrix and A[i-1][j-1] = 1.
(i+1, j+1) if (i+1, j+1) is inside the matrix and A[i+1][j+1] = 1.
(i-1, j+1) if (i-1, j+1) is inside the matrix and A[i-1][j+1] = 1.
(i+1, j-1) if (i+1, j-1) is inside the matrix and A[i+1][j-1] = 1.
Return the number of islands.

NOTE: Rows are numbered from top to bottom and columns are numbered from left to right.



Problem Constraints
1 <= N, M <= 100

0 <= A[i] <= 1



Input Format
The only argument given is the integer matrix A.



Output Format
Return the number of islands.



Example Input
Input 1:

 A = [ 
       [0, 1, 0]
       [0, 0, 1]
       [1, 0, 0]
     ]
Input 2:

 A = [   
       [1, 1, 0, 0, 0]
       [0, 1, 0, 0, 0]
       [1, 0, 0, 1, 1]
       [0, 0, 0, 0, 0]
       [1, 0, 1, 0, 1]    
     ]


Example Output
Output 1:

 2
Output 2:

 5


Example Explanation
Explanation 1:

 The 1's at position A[0][1] and A[1][2] forms one island.
 Other is formed by A[2][0].
Explanation 2:

 There 5 island in total.

*/

int Solution::solve(vector<vector<int> > &A) {
    
    int row = A.size(), col = A[0].size();
    
    if (row == 0 || col == 0)
        return 0;
        
    auto inside = [&](int x, int y){
        return 0 <= x && x < row && 0 <= y && y < col;
    };
    
    vector<pair<int, int> > directions {{-1,-1}, {-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}};
    
    vector<vector<bool> > visited (row, vector<bool>(col));
    int noOfIslands = 0;
    
    for (int i = 0; i < row; ++i){
        for (int j = 0; j < col; ++j){
            if (!visited[i][j] && A[i][j] == 1){
                noOfIslands++;
                
                queue<pair<int, int> > q;
                q.push({i, j});
                visited[i][j] = true;
                
                while (!q.empty()){
                    pair<int, int> temp = q.front();
                    q.pop();
                    
                    for (pair<int, int> dir : directions){
                        int new_row = temp.first + dir.first;
                        int new_col = temp.second + dir.second;
                        
                        if (inside(new_row, new_col) && !visited[new_row][new_col] && A[new_row][new_col] == 1){
                            q.push({new_row, new_col});
                            visited[new_row][new_col] = true;
                        }
                    }
                }
            }
        }
    }
    
    return noOfIslands;
}
