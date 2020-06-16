/*

HINT:

Suppose there are n distinct elements to be used in Max heap. Now it is for sure that the maximum element among this n 
distinct element will surely be placed on the root of the heap.

Now there will be remaining (n-1) elements to be arranged.

Now point to be remembered here is that the structure of the heap will remain the same. 
That is only the values within the node will change however the overall structure remaining the same.

As structure of the heap remains the same, the number of elements that are present in the left sub-tree of the root (L) will be fixed. 
And similarly the number of the elements on the right sub-tree (R) of the root. And also following equality holds .

 L + R = (n-1) 
Now as all the remaining (n-1) elements are less than the element present at the root(The Max Element), 
whichever L elements among ‘n-1` elements we put in the left sub-tree,
it doesn’t matter because it will satisfy the Max Heap property.

So now there are (n-1)CL ways to pickup L elements from (n-1) elements. And then recurse the solution.

So final equation will be as follows :

 (n-1)CL * getNumberOfMaxHeaps(L) * getNumberOfMaxHeaps(R) 
So now the question remains only of finding L for given n. It can be found as follows:

Find the height of the heap h = log2(n)

Find the max number of elements that can be present in the hth level of any heap . Lets call it m. m = 2h

Find the number of elements that are actually present in last level(hth level) in heap of size n. Lets call it p. p = n - (2h - 1)

Now if the last level of the heap is more than or equal to exactly half filled, then L would be 2h - 1

However if it is half filled then it will reduced by the number of elements in last level left to fill exactly half of the last level.

So final equation for L will be as follows :

 L = 2h - 1 if p >= m/2
                    = 2h - 1 - (m/2 - p) if p<(m/2) 

*/
