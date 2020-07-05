/*
Clone Graph
Problem Description

Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.



Problem Constraints
1 <= Number of nodes <= 105



Input Format
First and only argument is a node A denoting the root of the undirected graph.



Output Format
Return the node denoting the root of the new clone graph.



Example Input
Input 1:

      1
    / | \
   3  2  4
        / \
       5   6
Input 2:

      1
     / \
    3   4
   /   /|\
  2   5 7 6


Example Output
Output 1:

 Output will the same graph but with new pointers:
      1
    / | \
   3  2  4
        / \
       5   6
Output 2:

      1
     / \
    3   4
   /   /|\
  2   5 7 6


Example Explanation
Explanation 1:

 We need to return the same graph, but the pointers to the node should be different.

*/

#include<bits/stdc++.h>
using namespace std;

// Definition for undirected graph.
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

 
unordered_map <UndirectedGraphNode *, UndirectedGraphNode *> copies;

UndirectedGraphNode cloneGraph(UndirectedGraphNode *node) {
    if (!node)
        return node;
        
    if (copies.find(node) == copies.end() ){
        copies[node] = new UndirectedGraphNode(node->label);
        for (UndirectedGraphNode *n : node->neighbors)
            copies[node]->neighbors.push_back(cloneGraph(n));
    }
    
    return copies[node];
}
