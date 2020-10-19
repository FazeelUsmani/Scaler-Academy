/*

Tree coloring with three colors
Problem Description

Given a string A specifying a tree. A tree consists of a node and some (zero, one or two) subtrees connected to it. These subtrees are called children. A specification of the tree is a sequence of digits.

If the number of children in the tree is:

zero, then the specification is a sequence with only one element '0'.

one, the specification begins with '1' followed by the specification of the child.

two, the specification begins with '2' followed by the specification of the first child, and then by the specification of the second child.

You have to color the nodes of the tree. Each of the nodes in the tree must be painted either red or green or blue.

Following are some rules while painting the nodes:

The vertex and its child cannot have the same color.

If a vertex has two children, then they must have different colors.

return an array of integer C of size 2 where

C[0] = maximum number of nodes that can be painted green

C[1] = minimum number of nodes that can be painted green



Problem Constraints
1 <= length of the string <= 100000

A[i] = { '0', '1', '2'}



Input Format
The only argument given is string A.



Output Format
Return an array of integer C.



Example Input
Input 1:

 
A = 1122002010
Input 2:

A = 22000


Example Output
Output 1:

C = [5, 2]
Output 2:

 
C = [2, 1]


Example Explanation
Explanation 1:

A maximum of 5 and a minimum of 2 nodes can be green.
Explanation 2:

A maximum of 2 and a minimum of 1 nodes can be green.

*/
