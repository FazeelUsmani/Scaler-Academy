#include <bits/stdc++.h>
using namespace std;
#define ROW 27
#define COL 20

int trie[ROW][COL];
int cnt[ROW][COL];
bool EOW[ROW][COL];
int nextAvailable = 1;

bool search (string word){

    int ptr = 0;
    int len = word.length();

    for (int i = 0; i < len; i++){
        char ch = word[i];
        int index = ch - 'a' + 1;

        if (trie[index][ptr] == -1)
            return false;
        else
        {
            ptr = trie[index][ptr];
            if (ch != trie[0][ptr])
                return false;
            cout<<"index, ptr"<<index<<", "<<ptr<<", "<<EOW[index][ptr]<<" "<<endl;
            if (i == len-1){
                if (EOW[index][ptr] == false){
                    return false;
                }
            }
        }              
    }

    return true;
}

bool startsWith (string word){

    int ptr = 0;
    int len = word.length();

    for (int i = 0; i < len; i++){
        char ch = word[i];
        int index = ch - 'a' + 1;

        if (trie[index][ptr] == -1)
            return false;
        else
        {
            ptr = trie[index][ptr];
            if (ch != trie[0][ptr])
                return false;
        }              
    }

    return true;
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

void TRIEremove (string word){

    int ptr = 0;
    int len = word.length();

    for (int i = 0; i < len; i++){
        char ch = word[i];
        int index = ch - 'a' + 1;
        cnt[index][ptr]--;
        int prevPtr = ptr;
        ptr = trie[index][ptr];    
        if (cnt[index][prevPtr] == 0){
            trie[index][prevPtr] = -1;
            EOW[index][ptr] = false;  
        }   
    }

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

int main(){
    
    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++)
            trie[i][j] = -1;

    cout<<endl;
   
    // insert ("player");
    // insert ("plays");
    // insert ("plate");
    // insert ("cat");
    
    insert ("abc");
    //insert ("cab");    
    insert ("aba");
    //printTRIE();
    printTRIE();
    cout<<"\n\ncnt \n";
    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){
            cout<<cnt[i][j]<<" ";
        }
        cout<<endl;
    }
            
    cout<<"\n\nEOW \n";
    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){
            cout<<EOW[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Removing\n";
    TRIEremove("aba");
    // cout<<search("abc")<<" ";
    // cout<<search("cab")<<" ";
    // cout<<search("aca")<<" ";

    // cout<<startsWith("a")<<endl;
    // cout<<startsWith("ca")<<endl;
    // cout<<startsWith("cab")<<endl;
    // cout<<startsWith("aca")<<endl;
    // cout<<startsWith("cba")<<endl;
    
    printTRIE();
    cout<<"\n\ncnt \n";
    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){
            cout<<cnt[i][j]<<" ";
        }
        cout<<endl;
    }
            
    cout<<"\n\nEOW \n";
    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){
            cout<<EOW[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
