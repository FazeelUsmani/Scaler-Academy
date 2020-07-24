#include <bits/stdc++.h>
using namespace std;
#define ROW 27
#define COL 20

int trie[ROW][COL];
int cnt[ROW][COL];
bool EOW[ROW][COL];
int nextAvailable = 1;
vector<int> ans;

void printCNT(){
    for (int i = 0; i < ROW; ++i){
        for (int j = 0;  j< COL; ++j){
            cout<<cnt[i][j]<<" ";
        }
        cout<<endl;
    }
}

void insert (string word){

    int ptr = 0;
    int len = word.length();
    
    for (int i = 0; i < len; i++){
        char ch = word[i];
        int index = ch-'a'+1;

        cnt[index][ptr] ++;
        
        if (trie [index][ptr] == -1){
            trie [0][nextAvailable] = ch;
            trie [index][ptr] = nextAvailable;
            ptr = nextAvailable;
            nextAvailable++;
        }
        else{
            ptr = trie [index][ptr];
        }
        if (i == len-1)
            EOW[index][ptr] = true;      
    }          
}

bool search (string word){

    int ptr = 0, lastPtr = 0;
    int len = word.length();
    
    for (int i = 0; i < len; i++){
        char ch = word[i];
        int index = ch - 'a' + 1;

        if (trie[index][ptr] == -1)
            return 0;
        else
        {
            
            ptr = trie[index][ptr];
            lastPtr = ptr;
            if (ch != trie[0][ptr])
                return cnt[index][ptr];
            
            if (i == len-1){
                return cnt[index][ptr];
            }
            
        }              
    }
    int x = word[len-1];

    return trie[x][lastPtr];
}

void printTRIE(){
    cout<<"\n\n\nAfter Insert \n";
    char x = 'a';
    for (int i = 0; i < ROW; i++){
        if (i != 0)
            cout << x++ << " ++ ";
        else
        {
            cout<<"  ++ ";
        }       
        
        for (int j = 0; j < COL; j++){
            cout<<trie[i][j]<<" ";
        }
        cout<<endl;
    }
}

vector<int> solve(vector<int> &A, vector<string> &B){

    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++)
            trie[i][j] = -1;


    for (int i = 0; i < A.size(); ++i){
        if (A[i] == 0){
            insert(B[i]);
            cout<<"Inserted "<<B[i]<<endl;
        }
        else{
            ans.push_back(search(B[i]));
        }
    }    
    // printTRIE();
    // printCNT();
}

int main(){
    
    vector<int> A = {0, 0, 1, 1};
    vector<string> B = {"hack", "hacker", "hac", "hak"};
    ans.clear();
    solve(A, B);
    for (int x : ans)
        cout<<x<<" ";

    return 0;
}
