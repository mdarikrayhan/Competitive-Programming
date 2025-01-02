#include <bits/stdc++.h>
using namespace std;
int n,i;
main(){
for (cin>>n;cin>>n;) {
for (i=n-1;i>=1<<__lg(n-1);i--)cout<<i<<' ';
for (i=0;i<1<<__lg(n-1);i++)cout << i << ' ';
}}