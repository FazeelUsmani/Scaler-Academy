## Mathematics - Modulus

### ncr % p (where p is a prime number)

For n choose r mod p, use [Fermat's Little Theorem](https://www.britannica.com/science/Fermats-theorem#:~:text=Fermat's%20theorem%2C%20also%20known%20as,exactly%20into%20ap%20%E2%88%92%20a.)

__T.C: O(N)   S.C: O(1)__     [CODE](https://github.com/FazeelUsmani/Scaler-Academy/blob/master/005%20Math%203%20Mod/HW3%20ncr%25p.cpp)

![ncr](https://github.com/FazeelUsmani/Scaler-Academy/blob/master/005%20Math%203%20Mod/img/IMG_20200618_003533__01.jpg)


### ncr % m [where m is any number (not necessarily prime)]

For n choose r mod m, we need to find out all combinations over r. As there are many overlapping sub problems here use Dynamic Programming
__T.C: O(N * R)   S.C: O(N * R)__     [CODE](https://github.com/FazeelUsmani/Scaler-Academy/blob/master/005%20Math%203%20Mod/HW5%20ncr%20%25%20m.cpp)

### Do you really need the whole table for calculating the values?
No, right. We can optimize space to O(R).         [CODE](https://github.com/FazeelUsmani/Scaler-Academy/blob/master/005%20Math%203%20Mod/HW5%20ncr%20%25%20m1.cpp)


__P.S: Have you seen any pattern in the dp table?__

This is nothing but a [Pascal Triangle](https://www.mathsisfun.com/pascals-triangle.html). Refer this [link](https://www.mathsisfun.com/pascals-triangle.html) to know more about it. There are many math problems where you can use Pascal Triangle to solve them. So, look at their [properties](https://www.mathsisfun.com/pascals-triangle.html)
