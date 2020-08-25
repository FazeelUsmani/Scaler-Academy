bool isStepNum(int N){
    int prevNum = -1, currNum;
    while (N){
        currNum = N%10;
        if (prevNum == -1)
            prevNum = currNum;
        else{
            if (abs(currNum-prevNum) != 1)
                return false;
        }
        prevNum = currNum;
        N /= 10;
    }
    return true;
}

vector<int> Solution::stepnum(int A, int B) {
    
    vector<int> res;
    for (int i = A; i <= B; ++i){
        if (isStepNum(i)){
            res.push_back(i);
        }
    }
    sort(res.begin(), res.end());
    
    return res;
}
