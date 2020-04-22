Open minimum shops
Problem Description
There are A shops numbered 1 to A and B items numbered 1 to B. Shop contains different items denoted by 2-D array C of size N x 2 
where C[i][0] denotes shop number and C[i][1] denotes item number. There are D people number 1 to D which wants to buy item.

Need of the people is denoted by a 2-D array E of size M x 2 where E[i][0] denotes person number and E[i][1] denotes item number.
Find the minimum number of shops that needs to be opened such that demand of each and every person is fulfilled.
Return -1 if not possible. 
NOTE: The shopkeeper has an infinte number of supplies for the item number he contains.      


Problem Constraints
1 <= A, B, D <= 20
1 <= N, M <= 400


Input Format
First argument is an integer A denoting number of shops.
Second argument is an integer B denoting number of items.
Third argument is a 2-D array C of size N x 2 denoting the items shop contains.
Fourth argument is an integer D denoting the number of people.
Fifth argument is a 2-D array E of size M x 2 denoting the items people need.


Output Format
Return an integer denoting the minimum number of shops needs to be opened such that demand of each and every person is fulfilled. 
Return -1 if not possible.


Example Input
Input 1:
 A = 4
 B = 5
 C = [ [1, 2],
       [1, 3],
       [2, 1],
       [2, 2],
       [3, 4] ]
 D = 4
 E = [ [1, 3],
       [1, 2],
       [2, 3],
       [2, 1],
       [4, 1] ]
Input 2:
 A = 2
 B = 3
 C = [ [1, 2], 
       [2, 1] ]
 D = 2
 E = [ [1, 2],
       [2, 3],
       [2, 1] ]


Example Output
Output 1:
 2
Output 2:
 -1
     


Example Explanation
Explanation 1:
 Each shopkeeper has the following items: 
 Shop 1 : [2, 3]
 Shop 2 : [1, 2]
 Shop 3 : [4]
 Shop 4 : [] (has nothing)
 Items we need = [1, 2, 3]
 We need 2 shops i.e Shop 1 and 2, to be kept open so that demands of all people is satisfied.
Explanation 2:
 Items we need = [1, 2, 3]. 
 No shop has item 3. So will return -1.

def subsets(seq):
    z = [[]]
    for x in seq:
        z += [y + [x] for y in z]
    return z
    
    
class Solution:
    def solve(self, A, B, C, D, E):
        
        shops = {}
        for i in range(len(C)):
            X = shops.get(C[i][0], [])
            X.append(C[i][1])
            shops[C[i][0]] = X
        
        demand = set()
        for i in range(len(E)):
            demand.add(E[i][1])
        
        Z = [int(i) for i in shops]
        
        for i in shops:
          flag = True
          for j in range(len(shops[i])):
            if shops[i][j] in demand:
              flag = False
          if (flag):
            Z.remove(i)
            
        Z = subsets(Z)
        Z.pop(0)
        
        minSize = 9999
        for i in Z:
          l = []
          for j in i:
            for k in shops[j]:
              l.append(k)
          
          flag = True
          for k in demand:
            if k not in l:
              flag = False
              break
          
          if (flag):
            minSize = min(minSize, len(i))
            
          
        if minSize == 9999:
            return -1
        return minSize

        
        
