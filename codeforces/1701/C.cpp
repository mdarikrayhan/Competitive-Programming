#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{int m;
cin>>m;
while(m--)
{
ll n,t;
cin>>n>>t;
vector<int>v(t);
vector<ll>v1(n,0);
for(int&x:v){
cin>>x;
x--;
v1[x]++;
}
ll s=0,e=2*t;
while(s+1<e){
ll m=(s+e)/2;
ll k=0;
for(int i=0;i<n;i++){
ll eff=min(v1[i],m);
k+=eff;
k+=(m-eff)/2;
}
if(k>=t){
e=m;
}else{
s=m;
}
}
cout<<e<<'\n';}}