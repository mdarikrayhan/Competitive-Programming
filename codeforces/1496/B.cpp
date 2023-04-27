#include<bits/stdc++.h>
using namespace std;signed main(){int t;cin>>t;while(t--){map<int,int>m;int f=0,X=0,n,k;cin>>n>>k;while(n--){int a;cin>>a;m[a]++;}while(k--){
int M=prev(m.end())->first;
while(m[X])X++;
 m.erase(X);
m[((X+M)>>1)+((X+M)&1)]++;
 if(((X+M)>>1)+((X+M)&1)>X)break;
 if(X>M){f=1;
m[X]++;
break;}
}cout<<m.size()+f*k<<endl;
}}