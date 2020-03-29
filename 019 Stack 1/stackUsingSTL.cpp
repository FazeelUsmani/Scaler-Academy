#include<bits/stdc++.h>
using namespace std;

void showstack(stack <int> s){
    cout<<"The stack is ";
    while (!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

int main(){

    stack <int> s;

    s.push(10);
    s.push(100);
    s.push(1000);
    s.push(10000);

    showstack(s);
    cout<<"Size is "<<s.size()<<endl;
    cout<<"Is stack empty "<<s.empty()<<endl;

    cout<<"Top Element is "<<s.top()<<endl;
    s.pop();
    cout<<"Top Element is "<<s.top()<<endl;
    showstack(s);
    
    return 0;
}
