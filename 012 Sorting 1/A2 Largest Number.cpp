Largest Number
Given a list of non negative integers, arrange them such that they form the largest number. For example: Given [3, 30, 34, 5, 9], the largest formed number is 9534330. Note: The result may be very large, so you need to return a string instead of an integer.



int cmp(string x, string y){
    string a = x+y;
    string b = y+x;
    return a.compare(b) > 0 ? 1 : 0;
}

string Solution::largestNumber(const vector<int> &A) {
    vector<string> as;
    
    for (auto i:A)
        as.push_back(to_string(i));
        
    sort(as.begin(), as.end(), cmp);
    
    string ans = "";
    
    for (auto i : as)
        ans += i;
        
    if (ans[0] == '0')
        return "0";
        
    return ans;
    
}
