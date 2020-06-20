void swap (int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

vector<vector<int>> ans;
void generatePermutations(vector<int> &A, int l, int r){
    if (l == r){
        ans.push_back(A);
        return;
    }
    unordered_set<int> vis;
    for (int i = l; i <= r; ++i){
        if (vis.find(A[i]) == vis.end()){
            swap(A[i], A[l]);
            generatePermutations(A, l+1, r);                
            swap(A[i], A[l]);                              
            vis.insert(A[i]);
        }
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    
    ans.clear();
    generatePermutations(A, 0, A.size()-1);
            
    return ans;   
}
