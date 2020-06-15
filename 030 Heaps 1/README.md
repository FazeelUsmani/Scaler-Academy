## MIN HEAP: minimum ele at top

__Insert:__ arr[size - 1] = x and upheapify  O(log(size))

__Min Heapify:__ Similar to down heapify  TC: O(log N)

__Extract Min:__ O(1) time but to maintain the heap O(log N) for Min Heapify

__decrease key/update key:__ O(log (h))    go on swapping with largest parents till oth index

__Delete:__ We can do this in 2 steps: DecreaseKey (3, INT_MIN) and extract Min   TC: O(log N)

__Build Heap:__ Insert ele and then Min Heapify for all. TC: O(n)

![Build Heap Proof](https://github.com/FazeelUsmani/Scaler-Academy/blob/master/030%20Heaps%201/img/IMG_20200525_224809.jpg)





This folder contains all the solutions taught in Heap class

