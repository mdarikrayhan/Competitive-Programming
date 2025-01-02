// LUOGU_RID: 159126730
//#pragma GCC optimize(3)
//#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
//#define int long long
//#define ull unsigned long long
//#define lll __int128
//#define double long double
using namespace std;
const long long INF=1e9+5;
//const long long mod=998244353,orm=3;
const long long mod=1000000007;
const int MAXN=1000005;
const double eps=1e-6;
vector<int> ans;
int T,n;
int a[MAXN],sum[MAXN];
int mp[MAXN][2];
string s;
void solve() {
	cin>>s;n=s.size();s=' '+s;
	for(int i=1;i<=n;i++) a[i]=s[i]-'0';
	for(int i=1;i<=n;i++) {
		sum[i]=sum[i-1];
		if(a[i]) sum[i]++;else sum[i]--;
	}
	for(int i=0;i<n;i++) {
		if(sum[i+1]==sum[i]+1) mp[sum[i]+n][0]++,mp[sum[i+1]+n][1]++;
		else mp[sum[i]+n][1]++,mp[sum[i+1]+n][0]++;
	}
	int x=0;
	while(mp[x+n][0]||mp[x+n][1]) {
		ans.push_back(x);
		if(!mp[x+n][0]) mp[x+n][1]--,mp[x-1+n][0]--,x--;
		else {
			if(mp[x+n][1]>=2) mp[x+n][1]--,mp[x-1+n][0]--,x--;
			else mp[x+n][0]--,mp[x+1+n][1]--,x++;
		}
	}
	ans.push_back(x);
	int lst=-INF;
	for(int i:ans) {
		if(lst!=-INF) cout<<max(0,i-lst);
		lst=i;
	}cout<<"\n";
	for(int i=0;i<=n*2;i++) mp[i][0]=mp[i][1]=sum[i]=a[i]=0;ans.clear();
}
signed main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;int tt=0;
	while(T--) {
		solve();
	}
	return 0;
}