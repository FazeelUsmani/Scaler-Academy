#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// int shortest_path(vector<int> edges[100], int u, int v, int n)
// {
//     vector<bool> visited(n, 0);
//     vector<int> distance(n, 0);
//     queue<int> queue1;
//     distance[u] = 0;
//     queue1.push(u);
//     visited[u] = true;

//     while (!queue1.empty())
//     {
//         int x = queue1.front();
//         queue1.pop();

//         for (int i = 0; i < edges[x].size(); i++)
//         {
//             if (visited[edges[x][i]])
//                 continue;

//             distance[edges[x][i]] = distance[x] + 1;
//             queue1.push(edges[x][i]);
//             visited[edges[x][i]] = 1;
//         }
//     }

//     return distance[v];
// }

vector<int> solve(vector<int> &A, vector<vector<int>> &B, vector<vector<int>> &C)
{
    A.push_back(9);
    for (int i = A.size() - 1; i > 0; i--)
    {
        A[i] = A[i - 1];
    }
    A[0] = -1; // for simplicity

    vector<int> g[A.size()];

    for (int i = 0; i < B.size(); ++i)
    {
        int first = B[i][0];
        int second = B[i][1];

        g[first].push_back(second);
        g[second].push_back(first);
    }

    for (int x = 0; x < A.size(); ++x)
    {
        cout << x << ": ";
        for (int y = 0; y < g[x].size(); ++y)
        {
            cout << g[x][y] << " ";
        }
        cout << endl;
    }

    cout << "end of graph\n";
    cout << "shortest path between 4 & 2 is ";
    // vector<int> path = shortest_path(g, 4, 2, 6);
    int n = A.size();

    for (int i = 0; i < 1; ++i)
    {
        int u = C[i][1];
        int v = C[i][2];
        vector<bool> visited(n, 0);
        vector<int> distance(n, 0);
        queue<int> queue1;
        distance[u] = 0;
        queue1.push(u);
        visited[u] = true;

        while (!queue1.empty())
        {
            int x = queue1.front();
            queue1.pop();

            for (int i = 0; i < g[x].size(); i++)
            {
                if (visited[g[x][i]])
                    continue;

                distance[g[x][i]] = distance[x] + 1;
                queue1.push(g[x][i]);
                visited[g[x][i]] = 1;
            }
        }

        for (int i = 0; i < distance[v].size(); ++i)
        {
            cout << distance[v][i] << " ->  ";
        }
        cout << endl;
    }

    for (int x : A)
        cout << x << " ";

    return {786};
}

int main()
{
    vector<int> A{7, 8, 8, 2, 5};
    vector<vector<int>> B{{1, 3}, {1, 4}, {2, 3}, {4, 5}};
    vector<vector<int>> C{{1, 4, 2, 0},
                          {2, 5, 1, 6},
                          {2, 5, 5, 10},
                          {1, 4, 1, 0},
                          {2, 2, 2, 2}};

    vector<int> ans = solve(A, B, C);
    cout << "\nAns is ";
    for (int x : ans)
        cout << x << " ";

    return 0;
}