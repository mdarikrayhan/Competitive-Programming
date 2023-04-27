#include<bits/stdc++.h>
using namespace std;main(){int t,a,b,c;cin>>t;while(t--)cin>>a>>b>>c,cout<<((a+b+c)%9||(a+b+c)/9>min({a,b,c})?"NO\n":"YES\n");}