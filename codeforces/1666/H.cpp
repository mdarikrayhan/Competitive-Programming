//xii
#include<bits/stdc++.h>
#define P pair<ll,ll>
#define F first
#define S second
using namespace std;
typedef long long ll;
const int N=1e3+5;
ll t,n,d,h;
ll a[99],p[99]={0,1},q[99]={1,0},cl,cnt;
P vc[N*61];
ll gcd(ll x,ll y) {return y? gcd(y,x%y):x;}
int main()
{
//	freopen("B.in","r",stdin);
//	freopen("B.out","w",stdout);
cin>>t;
ll i,j;
while(t--)
{
cin>>n>>d>>h,cl=cnt=0,i=gcd(d,h),d/=i,h/=i;
for(i=d,j=h;j;swap(i,j),j%=i,cl++)
a[cl]=i/j,p[cl+2]=p[cl]+p[cl+1]*a[cl],q[cl+2]=q[cl]+q[cl+1]*a[cl];
ll pre=0;
for(i=1;i<=n;i++)
{
cin>>j,pre+=j/d,j%=d;
for(int li=cl+1-cl%2;li>=1&&j;li-=2)
while(j&&j>=p[li-1])
{
ll la=(j-p[li-1])/p[li],lb=p[li-1]+la*p[li],lc=j/lb;
vc[++cnt]=P(lb*lc,lc*(q[li-1]+la*q[li])),j-=lb*lc;
}
}
sort(vc+1,vc+cnt+1,[&](P a,P b){return a.F*b.S-a.S*b.F>0;});
ll ans=((pre*h+1)*(pre*d+1)-pre-1)/2-pre*d; pre=pre*h;
for(i=1;i<=cnt;i++)
ans+=(pre-1)*(vc[i].F)+((vc[i].S+1)*(vc[i].F+1)-gcd(vc[i].S,vc[i].F)-1)/2,pre+=vc[i].S;
cout<<ans+1<<'\n';
}
return 0;
}
/*
1
9 10 7
2 1 10 1 8 7 4 5 6
*/