#include<bits/stdc++.h>
using namespace std;

int find(int parent[], int node){    // Path functions
    if (node == parent[node])
        return node;
    parent[node] = find(parent, parent[node]);

    return parent[node];
}

void addEdge(int x, int y, int parent[], int size[]){   // union

    int c = find(parent, x);
    int d = find(parent, y);

    if (c != d){
        if (size[c] < size[d])
            swap(c, d);
        parent[d] = c;
        size[c] += size[d];        
    }
}


int main(){

    int n = 5;
    int parent[n+1], size[n+1];

    for (int i = 0; i <= n; ++i){
        parent[i] = i;
        size[i] = 1;
    }

    addEdge(1, 2, parent, size);  // add Edge
    addEdge(2, 3, parent, size);
    addEdge(4, 6, parent, size);
    addEdge(6, 5, parent, size);

    // 2 sets containing 1 2 3   &   4 5 6
    
    return 0;
}


