## MIN HEAP: minimum ele at top

Insert: arr[size - 1] = x and upheapify  O(log(size))

Min Heapify:Similar to down heapify  TC: O(log N)

Extract Min: O(1) time but to maintain the heap O(log N) for Min Heapify

decrease key/update key: O(log (h))    go on swapping with largest parents till oth index

Delete: We can do this in 2 steps: DecreaseKey (3, INT_MIN) and extract Min   TC: O(log N)

Build Heap: Insert ele and then Min Heapify for all





This folder contains all the solutions taught in Heap class

