// LUOGU_RID: 160087339
#include<bits/stdc++.h>
#define pi pair<int,int>
#define fi first
#define se second
#define lw(x) (x&(-x))
using namespace std;
#define rep(i,j,k) for(int i=j;i<=k;i++)
const int N=1e5+5;
int T,n,ys,p[N],bj[N],id[N];
pi t[N],dp[N];
vector<int> v[N];
void add(int x,pi k){for(;x<=n;x+=lw(x)) t[x]=max(t[x],k);}
pi qry(int x){pi res={0,0}; for(;x;x-=lw(x)) res=max(res,t[x]); return res;}
signed main(){
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		rep(i,1,ys) v[i].clear(); ys=0;
		cin>>n; int tot=0;
		rep(i,1,n) cin>>p[i],id[++tot]=i;
		while(tot){
			rep(i,1,n) bj[i]=0,t[i]=dp[i]={0,0};
			pi ans={0,0};
			rep(i,1,tot){
				dp[i]=qry(p[id[i]]-1),dp[i].fi++;
				pi dq={dp[i].fi,i}; ans=max(ans,dq),add(p[id[i]],dq);
			}
			int gs=0; while((gs+1)*(gs+2)/2<=tot) gs++;
			if(ans.fi>gs){
				int zz=ans.se,pr=tot; ys++,tot=0;
				while(zz) bj[zz]=1,v[ys].push_back(p[id[zz]]),zz=dp[zz].se;
				reverse(v[ys].begin(),v[ys].end());
				rep(i,1,pr) if(!bj[i]) id[++tot]=id[i];
			}else{
				set<pi> se;
				rep(i,1,tot){
					if(se.empty()||(*se.rbegin()).fi<p[id[i]]) ys++,v[ys].push_back(p[id[i]]),se.insert({p[id[i]],ys});
					else{
						auto it=se.lower_bound({p[id[i]],0}); int dq=(*it).se;
						v[dq].push_back(p[id[i]]),se.erase(it),se.insert({p[id[i]],dq});
					}
				}break;
			}
		}cout<<ys<<'\n';
		rep(i,1,ys){cout<<v[i].size()<<' '; for(auto dq:v[i]) cout<<dq<<' '; cout<<'\n';}
	}
}