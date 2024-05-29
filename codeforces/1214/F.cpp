#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
int n,m;
int a[200500],b[200500];
int c[800500],d[805000],tt,sum[800500];
vector<int>va[805000],vb[805000];
ll Ans[400500];
struct BIT{
	ll c[800500];
	void add(int p,ll v){
	    for(int i=p;i<=(n<<2);i+=(i&-i))c[i]+=v;
	}
	ll qry(int p){
		ll ans=0;
		for(int i=p;i;i&=(i-1))ans+=c[i];
		return ans;
	}
}fwk1,fwk2;
int id1[200500],id2[200500],lk[200500];
void print(int id){
	int tt1=0,tt2=0;
	for(int i=id;i<id+tt;++i){
		for(int v:va[i])a[++tt1]=v;
		for(int v:vb[i])b[++tt2]=v;
	}
	for(int i=1;i<=n;++i)lk[a[i]]=b[i];
	for(int i=1;i<=n;++i)printf("%d ",lk[i]);
}
int main(){
	cin>>m>>n;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),c[++tt]=a[i];
	for(int i=1;i<=n;++i)scanf("%d",&b[i]),c[++tt]=b[i];
	sort(c+1,c+tt+1),tt=unique(c+1,c+tt+1)-c-1;
	for(int i=1;i<=tt;++i)c[i+tt]=c[i];
	for(int i=1;i<=(tt<<1);++i){
		int now=c[i],nxt=c[i%(tt<<1)+1];
		if(now<=nxt)d[i]=nxt-now;else d[i]=nxt-now+m;
	}
	sum[0]=n+1;
    for(int i=1;i<=n;++i){
    	int pos=lower_bound(c+1,c+tt+1,a[i])-c;
    	++sum[pos],++sum[pos+tt],va[pos].pb(i),va[pos+tt].pb(i);
    	pos=lower_bound(c+1,c+tt+1,b[i])-c;
    	--sum[pos],--sum[pos+tt],vb[pos].pb(i),vb[pos+tt].pb(i);
	}
	for(int i=1;i<=(tt<<1);++i)sum[i]+=sum[i-1];
	for(int i=1;i<=(tt<<1);++i){
		fwk1.add(sum[i],1ll*sum[i]*d[i]),fwk2.add(sum[i],d[i]);
		if(i<tt)Ans[i+1]-=(fwk1.qry(n<<2)-2ll*fwk1.qry(sum[i])-1ll*sum[i]*(fwk2.qry(n<<2)-2ll*fwk2.qry(sum[i])));
		else if(i>=tt&&i<(tt<<1))Ans[i-tt+1]+=(fwk1.qry(n<<2)-2ll*fwk1.qry(sum[i-tt])-1ll*sum[i-tt]*(fwk2.qry(n<<2)-2ll*fwk2.qry(sum[i-tt])));
	}
	ll mn=1e18;int id=-1;
    for(int i=1;i<=tt;++i)if(mn>Ans[i])mn=Ans[i],id=i;
	cout<<mn<<endl;
	print(id);
	return 0;
}