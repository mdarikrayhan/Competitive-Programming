#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
long long cnt[MAXN],F[MAXN];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,m,dx,dy,ans=0;
	cin>>n>>m>>dx>>dy;
	F[0]=0;
	for(int i=1;i<n;i++) F[(long long)dx*i%n]=i;
	while(m--)
	{
		long long x,y;
		cin>>x>>y;
		long long p=F[x];
		y=(y-dy*p+n*p)%n;
		ans=max(ans,++cnt[y]);
	}
	for(int i=0;i<n;i++) if(cnt[i]==ans) return cout<<"0 "<<i,0;
}