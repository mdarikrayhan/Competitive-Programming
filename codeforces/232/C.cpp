// LUOGU_RID: 158970890
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int T,n;
ll D[100];
pair<ll,ll> Q(int k,ll x)
{
	if(k==0) return make_pair(0ll,0ll);
	if(k==1) return make_pair((x==1)?0ll:1ll,(x==1)?1ll:0ll);
	if(x<=D[k-1])
	{
		pair<ll,ll> tmp=Q(k-1,x);
		return make_pair(min(tmp.first,tmp.second+2),min(tmp.first,tmp.second)+((k+1)>>1));
	}
	pair<ll,ll> tmp=Q(k-2,x-D[k-1]);
	return make_pair(tmp.first+1,tmp.second);
}
ll F(int k,ll a,ll b,ll x)
{
	if(a==b) return 0;
	if(k<3) return 1;
	if(b<=D[k-1]) return F(k-1,a,b,2);
	if(D[k-1]<a) return F(k-2,a-D[k-1],b-D[k-1],x+1);
	pair<ll,ll> A=Q(k-1,a),A_=Q(k,a),B=Q(k-2,b-D[k-1]);
	return min(A.second+1+B.first,min(A.first+1+B.first,A_.first+x+B.second));
}
int main()
{
	scanf("%d%d",&T,&n),n=min(n,81),D[0]=1,D[1]=2;
	for(int i=2;i<=n;i++) D[i]=D[i-1]+D[i-2];
	while(T--)
	{
		ll x,y;
		scanf("%lld%lld",&x,&y);
		printf("%lld\n",F(n,min(x,y),max(x,y),1e17));
	}
	return 0;
}