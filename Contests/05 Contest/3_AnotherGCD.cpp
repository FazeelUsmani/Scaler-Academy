unordered_set<int> primeFactors(int n) 
{ 
    unordered_set<int> temp;
	while (n % 2 == 0) 
	{ 
		temp.insert(2);
		n = n/2; 
	} 

	for (int i = 3; i <= sqrt(n); i = i + 2) 
	{ 
		while (n % i == 0) 
		{ 
			temp.insert(i);
			n = n/i; 
		} 
	} 

	if (n > 2) 
		temp.insert(n);

    return temp;
} 


int Solution::solve(vector<int> &A) {
    
    bool flag = true;
    for (int i = 0; i < A.size(); i++){
        if (A[i] != 1){
            flag = false;
        }
    }
    if (flag)
        return -1;
    
    unordered_map<int, vector<int>> umap;

    for (int i = 0; i < A.size(); i++){
        unordered_set<int> res = primeFactors(A[i]);    
        for (auto j : res){
            umap[j].push_back(i);
        }
    }
    
    int _max = INT_MIN;

    for (auto x = umap.begin(); x != umap.end(); x++){
        int cnt = 1;
        sort(x->second.begin(), x->second.end());
        for (int y = 1; y < x->second.end() - x->second.begin(); y++){

            if (x->second[y] - x->second[y-1] == 1){
                cnt++;
                _max = max(_max, cnt);
            }
            else{
                cnt = 1;
            }
        }
    }
    
    return max(_max, 1);
}
