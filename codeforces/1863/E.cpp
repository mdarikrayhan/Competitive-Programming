#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

bool sign=1;

#define debug(x) if(sign) cerr<<#x<<"="<<(x)<<'\n';
#define see if(sign) cout<<"Case #"<<tc<<": ";
#define bug(x) if(sign) cout<<"@"<<(x)<<'\n';
#define kill(x) return cout<<x<<'\n',void()
#define fixset(x) fixed<<setprecision(x)
#define endl '\n'

struct node {
	int st,id;
};

const int N=3e5+5;
vector <int> e[N];

int h[N];

int tc,n,m,k;

void RuinGuard()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) {
		cin>>h[i];
		e[i].clear();
	}
	
	vector <pii> input(m);
	
	vector <int> in(n+1,0);
	
	vector <LL> t(n+1,0);
	
	for(auto &it : input) {
		cin>>it.first>>it.second;
		e[it.first].push_back(it.second);
		in[it.second]++;
	}
	
	auto topsort = [&](int st) -> LL {
		
		queue <int> q;
		for(int i=1;i<=n;i++) {
			if(in[i]) continue;
			if(h[i]<st) t[i]=h[i]-st+k;
			else t[i]=h[i]-st;
			q.push(i);
		}
		
		while(q.size()) {
			int temp=q.front(); q.pop();
			for(auto nxt : e[temp]) {
				
				LL num=t[temp]+h[nxt]-h[temp];
				LL cost=(h[nxt]>=h[temp] ? num : num+k);
				
				t[nxt]=max(t[nxt], cost);
				
				if(!--in[nxt]) q.push(nxt);
			}
		}
		
		LL res=0;
		for(int i=1;i<=n;i++) {
			res=max(res, t[i]);
		}
		return res;
	};
	
	vector <node> a;
	for(int i=1;i<=n;i++) {
		if(!in[i]) a.push_back({h[i],i});
	}
	
	sort(a.begin(),a.end(),[&](node x,node y) {
		return x.st < y.st;
	});
	
	LL ans=topsort(0), mx=ans;
	ans -= a[0].st;
	
	vector <bool> vis(n+1,0);
	auto update = [&](int st) -> void {
		vis[st]=1; t[st] += k;
		queue <int> q; q.push(st);
		while(q.size()) {
			int temp=q.front(); q.pop();
			mx=max(mx, t[temp]);
			for(auto nxt : e[temp]) {
				if(vis[nxt]) continue;
				
				LL num=t[temp]+h[nxt]-h[temp];
				LL cost=(h[nxt]>=h[temp] ? num : num+k);
				
				if(t[nxt]<cost) {
					vis[nxt]=1; t[nxt]=cost; q.push(nxt);
				}
			}
		}
	};
	
	for(int i=0;i<a.size()-1;i++) {
		update(a[i].id);
		ans=min(ans, mx-a[i+1].st);
	}
	see kill(ans);
}

signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
	sign=0;
    
    int testcase; cin>>testcase;
    for(tc=1;tc<=testcase;tc++) {
    	RuinGuard();
	} 

    return 0;
}