#include "bits/stdc++.h"
using namespace std;

#define int long long 
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0);
#define all(x) x.begin(),x.end()
#define pi pair<int,int> 
#define vi vector<int>
#define si set<int> 
#define mi map<int,int>
#define mc map<char,int>
#define YES cout<<"Yes"<<endl;
#define NO  cout<<"No"<<endl;
#define pb(x) push_back(x);
#define fi first
#define sc second
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }

const int INF =1e18;
const int mod =1e8;

// 如果前面一个大于后面一个，前面一个变为0
//一次变0，是所有这一个数都变0，，可能会对之前的或后面的产生影响。
//最后变成非递减。


void solve()
{
	//vi cnt(n+1);
	int n;
	cin>>n;
	vi cnt(n+1);
	vi st(n+1);
	vi a(n);
	for (int i=0;i<n;i++){
		cin>>a[i];
		cnt[a[i]]=i;
	}
	if(n==1){
		cout<<0<<endl;
		return ;
	}
	int pos=-1;
	for (int i=n-1;i>=1;i--){
		if(a[i-1]>a[i]){
			pos=i-1;
			break;
		}
	}
	
	if(pos==-1){
		cout<<0<<endl;
		return ;
	}
	
	int maxn=0;
	for (int i=0;i<=pos;i++){
		maxn=max(maxn,cnt[a[i]]);
	}
	
	int ans=0;
	for (int i=0;i<=maxn;i++){
		if(a[i] && st[a[i]]==0){
			ans++;
			st[a[i]]=1;
		}
	}
	cout<<ans<<endl;

}


signed main()
{
	IOS
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}


//1234123