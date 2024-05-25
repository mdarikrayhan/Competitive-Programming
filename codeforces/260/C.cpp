#pragma GCC optimize("Ofast")
#pragma GCC target("avx,popcnt,sse4,abm")
#include <bits/stdc++.h>
#define AC ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define loli long long int
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>
#define pqueue priority_queue
#define pb push_back
#define F first
#define S second
#define tmi(a,b) a=min(a,b)
#define tmx(a,b) a=max(a,b)
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) (x).size()
#define rALL(x) (x).rbegin(),(x).rend()
#define EB emplace_back
#define PB push_back
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define cmax(a, b) a = (a > b ? a : b)
#define cmin(a, b) a = (a < b ? a : b)
#define put(x) cout << x << "\n";
#define DB(x) cerr << #x << " " << x << "\n"
#define all(v) v.begin(), v.end()
#define MEM(x, n) memset(x, n, sizeof(x));
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define lyes cout << "Yes\n"
#define lno cout << "No\n"
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define TEST cout<<"!";exit(0)
#define nosol cout<<"-1\n"
#define lowbit(x) x &(-x)
#if !LOCAL
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;
const double eps = 1e-8;
using namespace std;
/******************************************************************************/
int ary[100010];
void solve(){
	int n,x;
	cin>>n>>x;	
	rep(i,n)cin>>ary[i];
	int mp = 0,mm = ary[0],fp = 0;
	x--;
	rep(i,n){
		if(ary[i]<mm){
			mm = ary[i];
			mp = i;
			fp = i;
		}
		else if(ary[i]==mm&&i<=x){
			mp = i;
		}
		else if(ary[i]==mm&&fp>x){
			mp = i;
		}
	}
	bool meetx = 0;
	if(mp==x)meetx = 1;
	int add = 0;
	rep1(i,n-1){
		ary[(i+mp)%n]-=mm;
		if(!meetx){
			add++;
			ary[(i+mp)%n]--;
		}
		if((i+mp)%n==x){
			meetx = 1;
		}
	}
	ary[mp]*=n;
	ary[mp]+=add;
	rep(i,n)cout<<ary[i]<<" ";
}
signed main(){
	AC
	int t = 1;
	// cin>>t;while(t--)
	solve();
}
