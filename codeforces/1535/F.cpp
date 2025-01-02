// Problem: F. String Distance
// Contest: Codeforces - Educational Codeforces Round 110 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1535/F
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Author: nullptr_qwq
// 
// Powered by CP Editor (https://cpeditor.org)

// 私は猫です

#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define inf 1e9
#define infll 1e18
#define pii pair<int,int>
#define F(i,a,b) for(int i=a;i<=(b);i++)
#define dF(i,a,b) for(int i=a;i>=(b);i--)
#define wh(lzm) while(lzm--)
#define cmh(sjy) while(sjy--)
#define lowbit(x) (x&(-x))
#define HH printf("\n")
#define eb emplace_back
using namespace std;
ll read(){
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*f;
}
const int mod=998244353,maxn=500005;
int t[maxn][26],tot,n,m,lcp[maxn],nxt[maxn],stk[maxn],top,len;
string a[maxn],b[maxn];
vector<int>vec[maxn];
map<vector<int>,vector<int>>mp;
ll ans=0;
void clear_trie(){
	F(i,0,tot+1) {
		F(j,0,25) t[i][j]=0;
		vec[i].clear();
	}
	tot=0;
}
void solve(){
	if(m<=1)return;
	ll sum=0; sort(b,b+m),clear_trie(),ans+=(1ll*m*(m-1));
	F(i,0,m) lcp[i]=0;
	F(i,0,m-1){
		vec[0].push_back(i);
		int u=0;
		dF(j,len-1,0){
			int c=b[i][j]-'a';
			if(!t[u][c]) t[u][c]=++tot;
			vec[u=t[u][c]].push_back(i);
		}
	}
	top=0;
	dF(i,m-1,0){
		nxt[len-1]=len-1;
		dF(j,len-2,0)
			if(b[i][j]<=b[i][j+1]) nxt[j]=nxt[j+1];
			else nxt[j]=j;
		F(j,1,top){
			int l=stk[j],r=(j>1)?stk[j-1]-1:m-1,u=0;
			dF(p,len-1,nxt[lcp[l]]+1) u=t[u][b[i][p]-'a'];
			sum+=upper_bound(vec[u].begin(),vec[u].end(),r)-lower_bound(vec[u].begin(),vec[u].end(),l);
		}
		if(i==0) continue;
		for(lcp[i]=0;lcp[i]<len&&b[i-1][lcp[i]]==b[i][lcp[i]];++lcp[i]);
		for(;top&&lcp[stk[top]]>=lcp[i];--top);
		stk[++top]=i;
	}
	ans-=sum;
}
signed main(){
	n=read();
	F(i,0,n-1){
		cin>>a[i];
		vector<int>occ(26,0);
		for(char c:a[i]) ++occ[c-'a'];
		mp[occ].push_back(i);
	}
	len=a[0].size();
	int presum=0;
	for(auto it:mp){
		m=it.second.size(),ans+=1337ll*m*presum,presum+=m;
		F(j,0,m-1) b[j]=a[it.second[j]];
		solve();
	}
	cout<<ans;
}