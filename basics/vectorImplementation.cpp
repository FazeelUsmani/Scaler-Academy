#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<int> first;   // Empty vector

    for (auto i : first)
        cout<<i<<" ";       

    vector<int> second (4,100);  // four integers with values 100
    for(auto i : second)   
        cout<<i<<" ";
    cout<<endl;

    vector<int> third (second.begin(), second.end());    // copying second
    for(auto i : third)   
        cout<<i<<" ";
    cout<<endl;

    vector<int> fourth(third);  // Copy of third
    for(auto i : fourth)   
        cout<<i<<" ";
    cout<<endl;


    int myints[] = {1,2,3,4,5};      // Copying these elements in fifth vector
    vector<int> fifth (myints, myints + sizeof(myints)/sizeof(int));
    for(auto i : fifth)   
        cout<<i<<" ";
    cout<<endl;

    int n = 5;           
    vector<int> sixth (n, 10);      // Creating a vector of size n & values 10
    for(auto i : sixth)   
        cout<<i<<" ";
    cout<<endl;

    vector<int> seventh;
    for(auto i : seventh)   
        cout<<i<<" ";
    cout<<endl;
    
    int row = 4;
    int col = 6;
    cout<<"Initializing a 2D array of size 4x6 wtih all values as 5\n";
    vector<vector <int> > A(row, vector<int> (col, 5));

    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;    
    }


    cout<<"Printing 2d array \n";
    vector< vector <int>> temp;

    temp[0].push_back(1);
    temp[0].push_back(2);
    temp[1].push_back(3);
    temp[1].push_back(4);
    temp[2].push_back(5);
    temp[2].push_back(6);

    for (int i = 0; i < temp.size(); i++){
        for (int j = 0; j < temp[0].size(); j++){
            cout<<temp[i][j]<<" ";
        }
        cout<<endl;
    }





    return 0;
}
