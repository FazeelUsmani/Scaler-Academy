/*

Edge in MST
Problem Description

Given a undirected weighted graph with A nodes labelled from 1 to A with M edges given in a form of 2D-matrix B of size M * 3 where B[i][0] and B[i][1] denotes the two nodes connected by an edge of weight B[i][2].

For each edge check whether it belongs to any of the possible minimum spanning tree or not , return 1 if it belongs else return 0.

Return an one-dimensional binary array of size M denoting answer for each edge.

NOTE:

The graph may be disconnected in that case consider mst for each component.
No self-loops and no multiple edges present.
Answers in output array must be in order with the input array B output[i] must denote the answer of edge B[i][0] to B[i][1].


Problem Constraints
1 <= A, M <= 3*105

1 <= B[i][0], B[i][1] <= A

1 <= B[i][1] <= 103



Input Format
The first argument given is an integer A representing the number of nodes in the graph.

The second argument given is an matrix B of size M x 3 which represents the M edges such that there is a edge between node B[i][0] 
and node B[i][1] with weight B[i][2].



Output Format
Return an one-dimensional binary array of size M denoting answer for each edge.



Example Input
Input 1:

 A = 3
 B = [ [1, 2, 2]
       [1, 3, 2]
       [2, 3, 3]
     ]


Example Output
Output 1:

 [1, 1, 0]


Example Explanation
Explanation 1:

 Edge (1, 2) with weight 2 is included in the MST           1
                                                          /   \
                                                         2     3
 Edge (1, 3) with weight 2 is included in the same MST mentioned above.
 Edge (2,3) with weight 3 cannot be included in any of the mst possible.
 So we will return [1, 1, 0]

*/


#define ff first
#define ss second
#define pi pair<int,int>
#define pb push_back
const int maxn=300009;
int arr[maxn];
int sz[maxn];
vector<pair<pi,pi> >edges;


void ini()
{
  edges.clear();
 for(int i=0;i<maxn;i++)
  {
    arr[i]=i;
    sz[i]=1;
  }
}

int root(int a)
{
  while(arr[a]!=a){
    arr[a]=arr[arr[a]];
    a=arr[a];
  }
  return a;
}
void un(int a,int b)
{
  int ra=root(a);
  int rb=root(b);
  if(sz[ra]<=sz[rb])
  {
    arr[ra]=rb;
    sz[rb]+=sz[ra];
  }
  else
  {
    arr[rb]=ra;
    sz[ra]+=sz[rb];
  }
}
bool cmp(pair<pi,pi>& a,pair<pi,pi>& b)
{
  return a.ff.ff<b.ff.ff;
}
vector<int> Solution::solve(int A, vector<vector<int> > &B) {
    
    ini();
    for(int i=0;i<B.size();i++)
    {
        int u=B[i][0];
        int v=B[i][1];
        int w=B[i][2];
        edges.pb({{w,i},{u,v}});
    }
    vector<int>ans;
    ans.resize(B.size());
    sort(edges.begin(),edges.end(),cmp);
    int i=0;
    int m=B.size();
    while(i<m){
      int j=i;
      while(j<m && edges[j].ff.ff==edges[i].ff.ff)
      {
        if(root(edges[j].ss.ff)!=root(edges[j].ss.ss))ans[edges[j].ff.ss]=1;
        j++;
      }
      j=i;
      while(j<m && edges[j].ff.ff==edges[i].ff.ff)
      {
        if(root(edges[j].ss.ff)!=root(edges[j].ss.ss))un(edges[j].ss.ff,edges[j].ss.ss);
        j++;
      }
      i=j;
    }
    return ans;
}
