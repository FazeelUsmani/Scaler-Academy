Flight Range Bookings
Lets say, there is a company CorpFly which only takes booking from corporates. Lets say I have A flights and they are 
numbered from 1 to A. Most corporate bookings are of the following form (i, j, K). This implies book K seats each on 
every flight numbered between i and j (inclusive). Given a sequence of these bookings from corporates, your job is to 
tell the number of seats booked on each of the A flights. Note that CorpFly will not take bookings from any other means. 
In other words, you can assume the bookings mentioned here cover all the bookings for CorpFly. 

Constraints :
1 <= i <= j <= A

Assume the number of seats in every flight is infinite. 
1 <= A <= 10^5 ( Yes, CorpFly is huge ).
The number of corporate bookings would be less than 100000.

Example:

Input:
A = 5, B = [[1, 2, 10], [2, 3, 20], [2, 5, 25]]

Return: [10, 55, 45, 25, 25]

Explanation:
=> First booking books 10 seats on flights 1 to 2(1 and 2). Final bookings in each flight after first booking: [10, 10, 0, 0, 0]

=> Second booking books 20 seats on flights 2 to 3(2 and 3). Final bookings in each flight after second booking: [10, 30, 20, 0, 0]

=> Third booking books 25 seats on flights 2 to 5(2,3,4,5). Final bookings in each flight after third booking: [10, 55, 45, 25, 25]


vector<int> Solution::solve(int A, vector<vector<int> > &B) {
    
    vector<int> res( A + 1 , 0);
    
    int Bsize = sizeof(B)/sizeof(B[0]);
    
    for (auto i : B){
        
        res[ i[0] - 1] += i[2];
        res[ i[1] ] -= i[2];
    }
        
    for (int j = 1; j < A; j++)
        res[j] += res[j-1];
        
    res.pop_back();
    
    return res;
    
}
