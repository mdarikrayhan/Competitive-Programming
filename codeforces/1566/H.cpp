//#define NDEBUG
#include<bits/stdc++.h>
#define For(i,j,k) for(int i=(j);i<=(k);++i)
#define ForD(i,j,k) for(int i=(j);i>=(k);--i)
#define ll long long
using namespace std;
bool Mbe;
mt19937 gen(time(0));
uniform_int_distribution<int> rnd(0,1e9);
const int N=1e6+5;
int pri[N],cnt=0;
bool is_p[N];
int mn[N],w[N],f[N],g[N],h[N],cur[N],typ[N];
vector<int> buc[N],base[N];
vector<pair<int,int> > vec;
void solve(){
	int c,n; cin>>c>>n;
	mn[1]=1;
	For(i,2,c){
		if(!is_p[i]) pri[++cnt]=i,mn[i]=i;
		for(int j=1;j<=cnt&&i*pri[j]<=c;j++){
			is_p[i*pri[j]]=1;
			if(i%pri[j]==0){
				mn[i*pri[j]]=mn[i];
				break;
			}
			mn[i*pri[j]]=mn[i]*mn[pri[j]];
		}
	}
	int ans=0;
	For(i,1,c) if(mn[i]==i) w[++ans]=i;
	cout<<ans<<' ';
	For(i,1,ans) cout<<w[i]<<' '; cout<<endl;
	For(i,1,ans) cin>>g[w[i]];
	For(i,1,ans) for(int j=w[i];j<=c;j+=w[i]) if(mn[j]==j) h[j]^=g[w[i]];
	For(i,1,ans) for(int j=w[i];j<=c;j+=w[i]) if(mn[j]==j) f[w[i]]^=h[j];
//	For(i,1,ans) cout<<w[i]<<' '<<f[w[i]]<<endl;
	For(i,1,c) buc[mn[i]].push_back(i);
	For(i,1,ans){
		int a[21]={},b[21]={},num=0;
		for(int _x:buc[w[i]]){
			int j=0,x=_x;
			ForD(k,20,0) if(x>>k&1){
				if(!a[k]){
					base[w[i]].push_back(_x);
					a[k]=x,b[k]=j^(1<<num++),j=-1;
					break;
				}
				x^=a[k],j^=b[k];
			}
			if(~j) vec.push_back((pair<int,int>){j,w[i]});
		}
		int x=f[w[i]];
		ForD(k,20,0) if(x>>k&1) x^=a[k],cur[w[i]]^=b[k];
		n-=__builtin_popcount(cur[w[i]]);
	}
	int sz=vec.size();
	if(sz) while(n){
		int id=rnd(gen)%sz,i=vec[id].second,j=vec[id].first;
		n+=__builtin_popcount(cur[i])-__builtin_popcount(cur[i]^abs(j));
		if(j>0) n--; else n++;
		vec[id].first=-vec[id].first,cur[i]^=abs(j);
	}
	for(auto pr:vec) if(pr.first<0){
		int i=pr.second,j=-pr.first,s=0;
		For(k,0,(int)base[i].size()-1) if(j>>k&1) s^=base[i][k];
		typ[s]=1;
	}
	For(i,1,c) For(j,0,(int)base[i].size()-1) if(cur[i]>>j&1) typ[base[i][j]]=1;
	For(i,1,c) if(typ[i]) cout<<i<<" ";
}
bool Med;
signed main(){
	fprintf(stderr,"%.3lf MB\n",(&Mbe-&Med)/1048576.0);
	ios::sync_with_stdio(false); cin.tie(0),cout.tie(0);
	int _=1;
	//cin>>_;
	while(_--) solve();
	cerr<<1e3*clock()/CLOCKS_PER_SEC<<" ms\n";
	return 0;
}