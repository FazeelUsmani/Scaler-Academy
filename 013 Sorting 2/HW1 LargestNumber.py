Largest Number
Problem Description
Given a list A of non negative integers, arrange them such that they form the largest number. Note: The result may be very large, so you need to return a string instead of an integer. 


Problem Constraints
1 <= len(A) <= 100000
0 <= A[i] <= 2*109


Input Format
First argument is an array of integers.


Output Format
Return a string representing the largest number.


Example Input
Input 1:
A = [3, 30, 34, 5, 9]


Example Output
Output 1:
9534330


Example Explanation
Explanation 1:
A = [3, 30, 34, 5, 9]
Reorder the numbers to [9, 5, 34, 3, 30] to form the largest number.




int cmp(string x, string y){
    string a = x+y;
    string b = y+x;
    return a.compare(b)>0 ? 1:0;
}

string Solution::largestNumber(const vector<int> &A) {
    
    vector<string> temp;
    
    for (auto &i: A)
        temp.push_back(to_string(i));
        
    sort(temp.begin(), temp.end(), cmp);
    
    string ans = "";
    
    for (auto &i: temp)
        ans += i;
        
    if (ans[0] == '0')
        return "0";
    
    return ans;
    
}
