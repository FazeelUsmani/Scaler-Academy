#include <bits/stdc++.h>
using namespace std;

int tree[3][10];
int root = 0;
int nextAvailable = 0;

void insert (int val){

    int prevPtr = -1;
    int ptr = 0;
    bool flag = true;
    int prevDirection = -1;

    while (flag){

        if (ptr == -1){

            tree[0][nextAvailable] = val;
            
            if (nextAvailable != 0){
                ptr = nextAvailable;
                tree[prevDirection][prevPtr] = ptr;                            
            }

            nextAvailable++;
            flag = false;    
        }
        else if (tree[0][ptr] > val){
            prevPtr = ptr;
            prevDirection = 1;
            ptr = tree[1][ptr];
        }
        else if (tree[0][ptr] < val){
            prevPtr = ptr;
            prevDirection = 2;
            ptr = tree[2][ptr];
        }
    }
    
}


int main(){
    
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 10; j++)
            tree[i][j] = -1;

    cout<<endl;

    insert (10);
    insert (6);
    insert (2);
    insert (18);
    insert (19);
    insert (15);

    cout<<"After Insert \n";
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 10; j++){
            cout<<tree[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}
