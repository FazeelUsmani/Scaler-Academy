Merge Two Sorted Lists
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists, and should also be sorted. For example, given following linked lists :
  5 -> 8 -> 20 
  4 -> 11 -> 15
The merged list should be :
4 -> 5 -> 8 -> 11 -> 15 -> 20



# Definition for singly-linked list.
# class ListNode:
#	def __init__(self, x):
#		self.val = x
#		self.next = None
import sys
class Solution:
	# @param A : head node of linked list
	# @param B : head node of linked list
	# @return the head node in the linked list
	sys.setrecursionlimit(10**6)
	def mergeTwoLists(self, A, B):
	    
        # Recursive SOlution
        
        if (A==None):
            return B
        
        if (B==None):
            return A
            
        if A.val < B.val:
            A.next = self.mergeTwoLists(A.next, B)
            return A
            
        else:
            B.next = self.mergeTwoLists(A, B.next)
            return B
        
        
        
        



       # Iterative Solution:
       
	   # if A.val < B.val:
	   #     out = ListNode(A.val)
	   #     A = A.next
	   # else:
	   #     out = ListNode(B.val)
	   #     B = B.next
	        
	   # temp = out
	    
	   # while A is not None and B is not None:
	   #     if A.val < B.val:
	   #         temp.next = A
	   #         A = A.next
	   #     else:
	   #         temp.next = B
	   #         B = B.next
	   #     temp = temp.next
	        
	   # if A is not None:
	   #     temp.next = A
	        
	   # if B is not None:
	   #     temp.next = B
	        
	   # return out
	    
	    
	    
	    
	    

