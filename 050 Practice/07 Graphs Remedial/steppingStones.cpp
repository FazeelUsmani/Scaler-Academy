#include<bits/stdc++.h>
using namespace std;

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

vector<int> stepnum(int A, int B) {
    
    vector<int> res;
    for (int i = A; i <= B; ++i){
        if (isStepNum(i)){
            res.push_back(i);
        }
    }
        
    return res;
}

int main(){
    vector<int> res = stepnum(20, 50);
    for (int &x: res)
        cout<<x<<" ";

    return 0;
}
