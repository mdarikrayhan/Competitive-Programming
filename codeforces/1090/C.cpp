// LUOGU_RID: 159761447
// Problem: New Year Presents
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1090C
// Memory Limit: 500 MB
// Time Limit: 2000 ms
// Written by yhm.
// Start codeing:2024-05-21 16:34:10
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define mod 1000000007ll
#define pii pair<int,int>
#define fi first
#define se second
#define mems(x,y) memset(x,y,sizeof(x))
using namespace std;
const int maxn=100010;
const int inf=1e18;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch-48);ch=getchar();}
	return x*f;
}
bool Mbe;

int n,m,sum;
set<int> a[maxn];
vector<int> l,r;
vector<pair<int,pii> > ans;
void work(){
	n=read(),m=read();
	for(int i=1;i<=n;i++){
	    int x=read();sum+=x;
	    while(x--){
	    	int u=read();
	    	a[i].insert(u);
	    }
	}
	// cout<<sum<<" "<<sum/n<<" run\n";
    int num=0;
    for(int i=1;i<=n;i++){
    	if((int)a[i].size()<sum/n)l.push_back(i);
		if((int)a[i].size()>(sum+n-1)/n)r.push_back(i);
	}
	// cout<<l.size()<<" "<<r.size()<<"\n";
    while(l.size()&&r.size()){
    	int x=l.back(),y=r.back();
    	// cout<<x<<" "<<y<<"\n";
    	auto it=a[y].begin();
    	while(it!=a[y].end()){
    		if(!a[x].count(*it)){
    			// cout<<x<<" "<<y<<" "<<(*it)<<" "<<a[x].size()<<" "<<a[y].size()<<"\n";
    			a[x].insert(*it);ans.push_back({(*it),{x,y}});it=a[y].erase(it);
    			if((int)a[x].size()==sum/n||(int)a[y].size()==(sum+n-1)/n)break;
    		}
			else it++;
    	}
    	// cout<<l.size()<<" "<<r.size()<<"\n";
    	if((int)a[x].size()==sum/n)l.pop_back();
    	if((int)a[y].size()==(sum+n-1)/n)r.pop_back();
    }
    if(l.size()){
    	for(int i=1;i<=n;i++)if((int)a[i].size()==(sum+n-1)/n){
    		int x=l.back(),y=i;
    		for(int j:a[y]){
    			if(!a[x].count(j)){
    				a[x].insert(j),a[y].erase(j);ans.push_back({j,{x,y}});
    				break;
    			}
    		}
    		if((int)a[x].size()==sum/n)l.pop_back();
    		if(!l.size())break;
       	}
    }
    if(r.size()){
    	for(int i=1;i<=n;i++)if((int)a[i].size()==sum/n){
    		int x=i,y=r.back();
    		for(int j:a[y]){
    			if(!a[x].count(j)){
    				a[x].insert(j),a[y].erase(j);ans.push_back({j,{x,y}});
    				break;
    			}
    		}
    		if((int)a[y].size()==(sum+n-1)/n)r.pop_back();
    		if(!r.size())break;
       	}
    }
    // cout<<l.size()<<" "<<r.size()<<"\n";
    printf("%lld\n",(int)ans.size());
    for(pair<int,pii> p:ans)printf("%lld %lld %lld\n",p.se.se,p.se.fi,p.fi);
}

bool Med;
int T;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	
//	ios::sync_with_stdio(0);
//	cin.tie(0);cout.tie(0);
	
//	cerr<<(&Mbe-&Med)/1048576.0<<" MB\n";
	
	T=1;
	while(T--)work();
}