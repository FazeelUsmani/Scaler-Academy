Triplets with Sum between given range
Given an array of real numbers greater than zero in form of strings. Find if there exists a triplet (a,b,c) such that 1 < a+b+c < 2 .
Return 1 for true or 0 for false. 

Example: Given [0.6, 0.7, 0.8, 1.2, 0.4] ,\
You should return 1 as 0.6+0.7+0.4=1.7 1<1.7<2 Hence, the output is 1.

O(n) solution is expected. Note: You can assume the numbers in strings don't overflow the primitive data type and 
there are no leading zeroes in numbers. Extra memory usage is allowed.




int Solution::solve(vector<string> &A) {
    
    int n = A.size();
    
    float sum = 0;
    
    vector<float> Arr;
    for(auto &i : A)
        Arr.push_back(stof(i));
        
    
    int f=0, s=1, t=2;
    int curr = 3;
    while (curr < n){
        sum = (Arr[f] + Arr[s] + Arr[t]); 
        
        if ( (sum > 1) && (sum < 2))
            return 1;
            
        else if (sum > 2){
            
            if(Arr[f] > Arr[s] && Arr[f]>Arr[t])
                f = curr;
                
            else if(Arr[s] > Arr[f] && Arr[s]>Arr[t])
                s = curr;
            
            else if(Arr[t] > Arr[f] && Arr[t]>Arr[s])
                t = curr;
            
            curr++;
        }
        
        else if (sum < 1){
            if(Arr[f] < Arr[s] && Arr[f]<Arr[t])
                f = curr;
                
            else if( Arr[s] < Arr[f] && Arr[s]<Arr[t])
                s = curr;
            
            else if(Arr[t] < Arr[f] && Arr[t]<Arr[s])
                t = curr;
            
            curr++;
        }
    }
    
    sum = (Arr[f] + Arr[s] + Arr[t]);
    if ((sum > 1.0) && (sum < 2.0))
            return 1;
    return 0;

}




