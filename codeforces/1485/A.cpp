#include<bits/stdc++.h>
int X(int a,int x){
int lav=0;while(a){lav++;a/=x;}return lav;
}using namespace std;signed main(){int t;cin>>t;while(t--){
int a,b,val=100000;cin>>a>>b;for(int x=max(b,2);x<=b+10000;x++){
val=min(val,x-b+X(a,x));
}cout<<val<<endl;
}}