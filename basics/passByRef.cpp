#include <bits/stdc++.h>
using namespace std;

void passByReference(int &i, int &j) {
  int temp = i;
  i = j;
  j = temp;
}

void passByValue(int i, int j){
    int temp = i;
    i = j;
    j = temp;
    cout<<"a & b are "<<i<<"," <<j<<endl;
}

int main(void) {
  int a = 10;
  int b = 20;

  passByReference(a, b);
  printf("A is %d and B is %d\n", a, b);

  swap(a,b);   // swap() in STL
  printf("A is %d and B is %d\n", a, b);

  cout<<"Pass by value: ";
  passByValue(a,b);
  printf("A is %d and B is %d\n", a, b); // loses scope outside the function

  return 0;
}
