#include <bits/stdc++.h>
using namespace std;int main(){int m,n,a,b;for(cin>>n;n--;cout<<m<<" ")for(cin>>a,b=0,m=15;b<=15;b++)m=min(m,b+15-(__builtin_ctz(a+b)>=15?15:__builtin_ctz(a+b)));}