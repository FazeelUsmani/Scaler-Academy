This folder contains all the assignment and homework problems

# What is sorting?
Procedure by which you can arrange certain set of objects based on a specific permutation

## How to do Sorting? 
Brute Force defination would be getting all the possible permutations of the given set and extracting the expected one. 

If A = [3,1,2]
The permutations would be as follows:

    3 1 2
    3 2 1
    2 1 3
    2 3 1
    1 2 3  --> Pick this one 
    1 3 2
    
Time Complexity for generating all the permutations is O(N! x N) --> __O(N!)__


### Main points:
1) Time and space complexity
2) Number of comparisons & no. of swaps
3) Stability (Asked in Amazon MCQ's)
4) Inplace

<br />


| __Sorting Algorithm__ |      __Time Complexity__       | __Space Complexity__ | __Inplace__ | __Stable__ |
|-----------------------|--------------------------------|----------------------|-------------|---------------|
|<p align = "center"> Insertion Sort </p>| <p align = "center"> O(N^2)</p>|<p align = "center"> O(1)</p>|<p align = "center"> Yes</p>|    <p align = "center"> Yes</p>|
|<p align = "center"> Selection Sort </p>| <p align = "center"> O(N^2)</p>|<p align = "center"> O(1)</p>|<p align = "center"> Yes</p>|    <p align = "center"> Yes</p>|
|<p align = "center"> Bubble Sort </p>| <p align = "center"> O(N^2)</p>|<p align = "center"> O(1)</p>|<p align = "center"> Yes</p>|    <p align = "center"> Yes</p>|
|<p align = "center"> Count Sort </p>| <p align = "center"> O(N + K) <br /> K = max - min</p>|<p align = "center"> O(max-min)</p>|<p align = "center"> No</p>|    <p align = "center"> Yes</p>|
|<p align = "center"> Merge Sort </p>| <p align = "center"> O(NLog N)</p>|<p align = "center"> O(N)</p>|<p align = "center"> No</p>|    <p align = "center"> No</p>|
|<p align = "center"> Quick Sort </p>| <p align = "center"> O(NLog N)</p>|<p align = "center"> O(Log N)</p>|<p align = "center"> No</p>| <p align = "center"> No </p>|

<br /> <br />

### How to maintain stability?

| __Sorting Algorithm__ |      __Stability__ |
|-----------------------|--------------------|
|<p align = "center"> Insertion Sort </p>| <p align = "center"> Use < instead of <= </p>|
|<p align = "center"> Selection Sort </p>| <p align = "center"> Append instead of swapping</p>|
|<p align = "center"> Bubble Sort </p>| <p align = "center"> Use < instead of <= </p>|
|<p align = "center"> Count Sort </p>| <p align = "center">Read array from R --> L instead of L --> R </p>|

<br /> <br />

### Applications:

| __Sorting Algorithm__ |      __Application__ |
|-----------------------|--------------------|
|<p align = "center"> Insertion Sort </p>| <p align = "center"> Use in almost sorted sequence </p>|
|<p align = "center"> Selection Sort </p>| <p align = "center"> Use when swapping operation is costly </p>|
|<p align = "center"> Bubble Sort </p>| <p align = "center"> Use when you're not allowed to swap distant elements </p>|
|<p align = "center"> Count Sort </p>| <p align = "center"> Don't use for sparsely distributed array <br /> Use only when you know the min, max element <br /> 1 <= n <= 10^8 ,  1 <= k <=10^2 Use count sort <br /> n < 10^5, k <= 10^9 Go for Merge or Quick sort </p>|
|<p align = "center"> Merge Sort </p>| <p align = "center"> * Sorting Linked List in O(nlog n) time <br /> * Inversion count problem <br /> * Used in external sorting</p>|

<br />
<br />

For __Quick Sort__, you can use Lomuto or Hoares for partitioning
