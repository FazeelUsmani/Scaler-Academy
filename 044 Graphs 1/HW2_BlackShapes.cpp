/*
Black Shapes
Problem Description

Given character matrix A of O's and X's, where O = white, X = black.

Return the number of black shapes. A black shape consists of one or 
more adjacent X's (diagonals not included)



Problem Constraints
1 <= |A|,|A[0]| <= 1000

A[i][j] = 'X' or 'O'



Input Format
The First and only argument is character matrix A.



Output Format
Return a single integer denoting number of black shapes.



Example Input
Input 1:

 A = [ [X, X, X], [X, X, X], [X, X, X] ]
Input 2:

 A = [ [X, O], [O, X] ]


Example Output
Output 1:

 1
Output 2:

 2


Example Explanation
Explanation 1:

 All X's belong to single shapes
Explanation 2:

 Both X's belong to different shapes

 */



void dfs(vector<string> &A, vector<vector<int> > &visited, int i, int j){
    
    vector<pair<int, int> > directions{ {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
    
    auto inside = [&](int x, int y){
        return 0 <= x && x < A.size() && 0 <= y && y < A[0].size();
    };
    
    
    queue<pair<int, int> > q;
    q.push({i, j});
    visited[i][j] = 1;
    
    while (!q.empty()){
        pair<int, int> front = q.front();
        q.pop();
        
        for (pair<int, int> dir : directions){
            int new_row = front.first + dir.first;
            int new_col = front.second + dir.second;
            
            if (inside(new_row, new_col) && !visited[new_row][new_col] && A[new_row][new_col] == 'X'){
                q.push({new_row, new_col});
                visited[new_row][new_col] = 1;
            }
        }
    }
}


int Solution::black(vector<string> &A) {
    
    if (A.size() == 0 || A[0].size() == 0)
        return 0;
        
    vector<vector<int> > visited(A.size(), vector<int> (A[0].size(), 0));
    int cnt = 0;
    
    for (int i = 0; i < A.size(); ++i){
        for (int j = 0; j <A[i].size(); ++j){
            if (!visited[i][j] && A[i][j] == 'X'){
                dfs(A, visited, i, j);
                cnt++;
            }
        }
    }
    
    return cnt;
}
