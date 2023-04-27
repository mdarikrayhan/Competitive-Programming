#include <iostream>
using namespace std;
int main() {
int n;
cin>>n;
long long int j=1;
for (int i=1; i<n; i++)
j=j*i;
cout<<2*j/n;
}