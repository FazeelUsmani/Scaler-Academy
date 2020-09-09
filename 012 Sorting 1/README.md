

## Intuition behind Sum the Difference problem:

### How the Time Complexity changes from O(2^N) --> O(n^2) --> O(n*log n) 

Read about [Horner's formula](https://en.wikipedia.org/wiki/Horner%27s_method) before proceeding further

![Sum the Difference 1](img/Sum%20the%20difference.jpg)

1) Here you can observe in the 1st approach we're generating all subsets in O(2^n) time and calculating max-min in O91) time so overall time is O(2^n)

2) First sort the array in O(nlogn) time and then for every value I mean for every i and j calculate (A[j] - A[i]) * 2^(j-i-1).
(A[j] - A[i]) for max - min and 2^(j-i-1) for the number of subsets has the max and min as A[j] & A[i] respectively

3) Here draw some more observation by counting how many times 1,2,3 and 4 appears in the max and min of all subsets of {1,2,3,4}?
We found that the count appears as 2^0, 2^1, 2^2, 2^3........ So we simply use Horner's method to calculate the max and min. 

![Horner's method](img/Horners%20method.JPG)

![Sum the Difference 1](img/Sum%20the%20difference%201.jpg)

![Sum the Difference 1](img/Sum%20the%20difference%202.jpg)






This folder contains all the assignment and homework problems
