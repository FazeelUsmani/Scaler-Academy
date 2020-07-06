#include<bits/stdc++.h>
using namespace std;

int rottenOranges(vector<vector<int> > &A){
    
    vector<vector<int> > visited(A.size(), vector<int> (A[0].size(), 0));
    queue<pair<int, int> > q;
    
    for (int i = 0; i < A.size(); ++i){
        for (int j = 0; j < A[0].size(); ++j){
            if (A[i][j] == 2){
                q.push({i, j});
                visited[i][j] = 1;
            }
            else if (A[i][j] == 0)
                visited[i][j] = 1;
        }
    }
    
    auto inside = [&](int x, int y){
        return 0 <= x && x < A.size() && 0 <= y && y < A[0].size();
    };
    
    int days = 0;
    vector<pair<int, int> > directions = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
    while (!q.empty()){
        
        int size = q.size();
        bool flag = false;
        for (int i = 0; i < size; ++i){
            pair<int, int> p = q.front();
            q.pop();
            
            for (pair<int, int> dir : directions){
                int new_row = dir.first + p.first;
                int new_col = dir.second + p.second;
                
                if (inside(new_row, new_col) && !visited[new_row][new_col] && A[new_row][new_col] == 1){
                    visited[new_row][new_col] = 1;
                    q.push({new_row, new_col});
                    flag = true;
                }
            }
        }
        if (flag)
            days++;
    }
    
    for (int i = 0; i < A.size(); ++i){
        for (int j = 0; j < A[0].size(); ++j){
            if (visited[i][j] == 0){
                return -1;
            }
        }
    }
    
    return days;
}

int main(){

    vector<vector<int> > A{
        {2, 0, 2, 2, 2, 0, 2, 1, 1, 0},
        {0, 1, 2, 0, 2, 0, 0, 1, 0, 1},
        {0, 1, 1, 1, 2, 0, 1, 1, 2, 1},
        {2, 0, 2, 0, 1, 1, 2, 1, 0, 1},
        {1, 0, 1, 1, 0, 1, 2, 0, 2, 2},
        {0, 2, 1, 1, 2, 2, 0, 2, 1, 2},
        {2, 1, 0, 2, 0, 0, 0, 0, 1, 1},
        {2, 2, 0, 2, 2, 1, 1, 1, 2, 2}

    };

    cout<<"Ans is "<<rottenOranges(A);

    return 0;
}
