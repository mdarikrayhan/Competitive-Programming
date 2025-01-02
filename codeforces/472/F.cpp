// LUOGU_RID: 157250280
#include <bits/stdc++.h>
#define il inline
#define rg register
#define cit const rg unsigned
#define open ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)//,freopen("1.in","r",stdin),freopen("1.out","w",stdout)
#define int rg unsigned
#define void il void
#define ll long long
#define ull unsigned ll
#define db double
#define vector basic_string
#define pq priority_queue
#define vint vector<unsigned>
#define vll vector<ll>
#define vull vector<ull>
#define ump unordered_map
#define ust unordered_set
#define deq deque
#define mkp make_pair
#define pii pair<unsigned,unsigned>
#define pll pair<ull,ull>
#define fi first
#define se second
#define Bool(a,n) bitset<n>a
#define sca(a) for(int $=0;$<n;cin>>a[++$])
#define cle(a) memset(a,0,sizeof a)
#define tmx(a) memset(a,0x3f,sizeof a)
#define tmn(a) memset(a,0xbf,sizeof a)
#define tif(a) memset(a,0xff,sizeof a)
#define ge getchar_unlocked()
#define pu putchar_unlocked
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
//inline ll max(const rg ll a,const rg ll b){return a>b?a:b;}
//inline ll min(const rg ll a,const rg ll b){return a<b?a:b;}
using namespace std;constexpr unsigned N=1e6+1,p=1e9+7;Bool(v,N);
struct A{unsigned a,b;}ans[2][N];unsigned id[2],a[N],b[N],c[N];
unsigned B1[30],B2[30];void XOR(cit i,cit j,cit k){ans[k][++id[k]]={i,j};k?a[i]^=a[j]:b[i]^=b[j];}
void SWP(cit i,cit j){XOR(i,j,1),XOR(j,i,1),XOR(i,j,1);}
signed main(){open;int n;cin>>n;sca(a);sca(b);
	for(int i=1;i<=n;++i)for(int j=29;~j;--j)
	if(a[i]&(1<<j)){if(!B1[j]){B1[j]=i;break;}else XOR(i,B1[j],1);}
	for(int i=1;i<=n;++i)for(int j=29;~j;--j)
	if(b[i]&(1<<j)){if(!B2[j]){B2[j]=i;break;}else XOR(i,B2[j],0);}
	for(int i=0;i<30;++i)for(int j=i+1;j<30;++j)
	if(b[B2[i]]&&((b[B2[j]]&(1<<i))))XOR(B2[j],B2[i],0);
	for(int i=0;i<30;++i)for(int j=i+1;j<30;++j)
	if(a[B1[i]]&&((a[B1[j]]&(1<<i))))XOR(B1[j],B1[i],1);
	for(int i=1;i<=n;++i)if(!a[i])c[++c[0]]=i;

	for(int i=29;~i;--i)if(b[B2[i]]){if(!a[B1[i]])return cout<<"-1",0;
		for(int j=i-1;~j;--j)if((a[B1[i]]^b[B2[i]])&(1<<j)){
		if(!a[B1[j]])return 0;XOR(B1[i],B1[j],1);}
		if(B1[i]^B2[i]){if(!a[B1[i]]||!a[B2[i]])SWP(B2[i],B1[i]);
			else{cit d=__lg(a[B2[i]]),e=__lg(a[B1[i]]);
				SWP(B2[i],B1[i]);swap(B1[d],B1[e]);}}v[i]=1;}
	for(int i=29;~i;--i)if(!v[i]&&a[B1[i]])XOR(B1[i],B1[i],1);
	cout<<id[0]+id[1]<<'\n';
	for(int i=1;i<=id[1];++i)cout<<ans[1][i].a<<' '<<ans[1][i].b<<'\n';
	for(int i=id[0];i   ;--i)cout<<ans[0][i].a<<' '<<ans[0][i].b<<'\n';

}
