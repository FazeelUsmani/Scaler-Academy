#include<bits/stdc++.h>
using namespace std;

struct Person{
    int age;
    float ht;
    Person (int a, float h){
        age = a;
        ht = h;
    }
};

struct myCmp{
    bool operator()(Person const &p1, Person const &p2){
        return p1.ht < p2.ht;
    }
};

int main(){

    priority_queue<Person, vector<Person>, myCmp> pq;

    float arr[5][2] = { { 30, 5.5 }, { 25, 5 }, { 20, 6 }, { 33, 6.1 }, { 23, 5.6 } }; 
  
    for (int i = 0; i < 5; ++i) {   
        pq.push(Person(arr[i][0], arr[i][1])); 
    } 

    while (!pq.empty()){
        Person p = pq.top();
        pq.pop();
        cout<<p.age<<" "<<p.ht<<endl;
    }
    

    return 0;
}
