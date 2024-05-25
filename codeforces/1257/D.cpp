// Problem: D. Yet Another Monster Killing Problem
// Contest: Codeforces - Educational Codeforces Round 76 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1257/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<unordered_map>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<cstring>
#include<queue>
#include<deque>
using namespace std;
int _;
#define endl '\n'
#define p 1e9+7
#define int long long
const int N=2e5+10;

int d[N][20];//记录值大小的贪
int g[N][20];//处理那个最大的坐标

struct bb{
	int x,y;
	operator<(const bb&t){return x<t.x;};
}b[N];

void solve(){
	
	int n;cin>>n;
	vector<int> a(n+1);
	
	
	for(int i=1;i<=n;++i) cin>>a[i];
	int m;cin>>m;
	vector<int> c(m+1);
	map<int,int> mp;
	for(int i=1;i<=m;++i){
		cin>>b[i].x>>b[i].y;
		g[i][0]=i;
		mp[b[i].x]=max(mp[b[i].x],b[i].y);
	}
	sort(b+1,b+1+m);
	
	for(int i=1;i<=m;++i) d[i][0]=b[i].y,c[i]=b[i].x;
	
	for(int i=1;i<=19;++i){
    	for(int j=1;j+(1<<i)-1<=m;++j){
    		d[j][i]=0;g[j][i]=0;
    	}
    }
    
	for(int i=1;i<=19;++i){
    	for(int j=1;j+(1<<i)-1<=m;++j){
    		d[j][i]=max(d[j][i-1],d[j+(1<<(i-1))][i-1]);
    		if(d[j][i-1]>d[j+(1<<(i-1))][i-1]) g[j][i]=g[j][i-1];
    		else g[j][i]=g[j+(1<<(i-1))][i-1];
    	}
    }
    
    
    
	
	int now=0;//耐力消耗
	int day=0;//记录用了几天
	int nowmax=0;//记录现在的最大值
	int nownow=0;//记录本次应该有的耐力值
	for(int i=1;i<=n;++i){
		if(a[i]>nowmax){
			int id=lower_bound(c.begin()+1,c.begin()+1+m,a[i])-c.begin();
		    if(id==m+1){
	    		cout<<-1<<endl;
			    return;
		    }
		    //if(i<=2)cout<<id<<endl;
		    int len=log2(m-id+1);
    	    if(d[id][len]>d[m-(1<<len)+1][len]) id=g[id][len];
    	    else id=g[m-(1<<len)+1][len];
    	    
			nownow=mp[b[id].x];
			nowmax=b[id].x;
			
			//if(i<=2)cout<<g[m-(1<<len)+1][len]<<endl;
			
		    if(now+1>nownow){
			    now=1;day++;
		    }
		    else now++;
		}
		else{
			if(now+1>nownow){
				now=1;day++;
				int id=lower_bound(c.begin()+1,c.begin()+1+m,a[i])-c.begin();
				int len=log2(m-id+1);
    	        if(d[id][len]>d[m-(1<<len)+1][len]) id=g[id][len];
    	        else id=g[m-(1<<len)+1][len];
				nownow=mp[b[id].x];
				nowmax=b[id].x;
			}
			else{
				now++;
			}
		}
		//cout<<day<<endl;
	}
	//cout<<endl;
	if(now) day++;
	cout<<day<<endl;
}

signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>_;
	while(_--){
		solve();
	}
	return 0;
}