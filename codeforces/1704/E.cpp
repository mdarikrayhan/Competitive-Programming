// LUOGU_RID: 160133527
//A tree without skin will surely die.
//A man without face is invincible.
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mid ((l+r)>>1)
#define lowbit(x) (x&-x)
#define all(x) (x).begin(),(x).end()
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define per(i,j,k) for (int i=j;i>=k;--i)
#define Tim ((double)clock()/CLOCKS_PER_SEC)
int const N=1e3+10;
int const mod=998244353;
int const inf=1e18;
int n,m,rd[N],cd[N],val[N];
vector<int>a[N];
struct node{int lf,rg,len;};
vector<node>Add[N];
void solve(){
	cin>>n>>m;
	rep(i,1,n) a[i].clear(),Add[i].clear(),rd[i]=cd[i]=0,cin>>val[i];
	while (m--){
		int x,y;cin>>x>>y;
		a[x].push_back(y);
		++rd[y],++cd[x];
	}
	queue<int>q;
	rep(i,1,n)
		if (!rd[i]) q.push(i);
	int ans=0;
	while (!q.empty()){
		int x=q.front();q.pop();
		int lf=1,rg=val[x],len=val[x];
		sort(all(Add[x]),[](node a,node b){
			return (a.lf^b.lf)?(a.lf<b.lf):(a.rg<b.rg);
		});
		vector<node>V;
		for (auto it:Add[x])
			if (it.lf>rg){
				if (lf<=rg) V.push_back((node){lf,rg,len});
				lf=it.lf,rg=it.rg,len=it.len;
			}else{
				len+=it.len,len%=mod;
				rg=min(inf,rg+it.rg-it.lf+1);
			}
		if (lf<=rg) V.push_back((node){lf,rg,len});
		Add[x]=V;
		if (Add[x].size() && !cd[x])
			ans=(Add[x].back().lf+Add[x].back().len+mod-1)%mod;
		for (auto v:a[x]){
			for (auto it:Add[x]) Add[v].push_back((node){it.lf+1,min(inf,it.rg+1),it.len});
			if (!--rd[v]) q.push(v);
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t=1;
	cin>>t;
	while (t--) solve();
	return 0;
}