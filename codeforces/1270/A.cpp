#include<bits/stdc++.h>
using namespace std;
int main(){int t,n,x,y,c;cin>>t;while(t--){cin>>n>>x>>y;string r="YES\n";while(x--)cin>>c;while(y--){cin>>c;if(c==n)r="NO\n";}cout << r;}}