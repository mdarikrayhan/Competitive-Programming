#include <bits/stdc++.h>
using namespace std;
int main(){
long long t,s,q;
cin>>t>>s>>q;
int x=0;
while (s<t){
s=s*q;
x++;
}
cout<<x;
}