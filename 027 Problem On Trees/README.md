# Convert Binary Tree to DLL:

__Naive:__
1) preorder and create a singly LL
2) Mark all the previous pointers by visiting each and every node
3) head->left = tail
4) tail->right = head
Extra space for array

__Recursive_Solution:__ Inplace converting binary tree
1) Convert Left sub tree to a DLL
2) Attach the last node of DLL to root
3) Convert Right sub tree to a DLL
4) concatenate left list and root then to right list


![image](https://github.com/FazeelUsmani/Scaler-Academy/blob/master/027%20Problem%20On%20Trees/img/BT2DLL%20(1).jpg)
![rough work](https://github.com/FazeelUsmani/Scaler-Academy/blob/master/027%20Problem%20On%20Trees/img/BT2DLL%20(2).jpg)
