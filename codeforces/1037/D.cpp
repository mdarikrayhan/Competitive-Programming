// -=[ In the name of GOD ]=- //
// Author: MKasirloo
// Libraries:
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <cmath>
#include <set>
using namespace std;
// Type Defenitions:
typedef pair<int,int> pii;
typedef long long ll;
typedef string str;
typedef char ch;
// Functions:
str to_binary(ll n){str r="";while(n){if(n%2){r+='1';}else{r+='0';};n/=2;}reverse(r.begin(),r.end());return r;}
ll pw(ll x,ll y,ll mod=1e9+7){ll a=1;while(y){if(y&1)a=a*x%mod;x=x*x%mod;y/=2;}return a;}
ll rd(ll a,ll b){return (a+b-1)/b;}
ll gcd(ll a,ll b){return (b?gcd(b,a%b):a);}
// Generations:
#define gen(nCr) for(int i=0;i<1005;i++)c[i][0]=1;for(int i=1;i<1005;i++)for(int j=0;j<805;j++)if(i>=j)c[i][j]=c[i-1][j-1]+c[i-1][j];
// Defenitions:
#define iOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define Test int tttt;cin>>tttt;while(tttt--)
#define dsort(a) sort(a,a+n,greater<int>())
#define all(x) (x).begin(),(x).end()
#define YES cout<<"YES"<<endl
#define asort(a) sort(a,a+n)
#define NO cout<<"NO"<<endl
#define db cout<<":P"<<endl
#define el cout<<endl
#define pb push_back
#define bye return 0
#define Y second
#define X first
// Consts:
const int D = 10639;
const int DO = 10607;
const int MAXN = 2e5+5;
const ll MOD = 1e9+7;
const ll INF = 1e18;
vector<int> g[MAXN]; ll h[MAXN]; bool vis[MAXN]; int pos[MAXN];
bool cr(int i,int j){return pos[i]<pos[j];}
int main(){
	iOS;
	int n,u,v;
	cin>>n;
	int a[n];
	for(int i=1; i<n; i++){
		cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	for(int i=0; i<n; i++){
		cin>>a[i],a[i]--;
		pos[a[i]]=i;
	}
	for(int i=0; i<n; i++) sort(all(g[i]),cr);
	queue<int> q; vector<int> p;
	q.push(0); p.pb(0);
	vis[0]=true;
	while(q.size()){
		int head=q.front();
		q.pop();
		for(int u:g[head]){
			if(vis[u]) continue;
			h[u]=h[head]+1;
			vis[u]=true;
			q.push(u);
			p.pb(u);
		}
	}
	for(int i=0; i<n; i++){
		if(a[i]!=p[i]){
			NO;
			bye;
		}
	}
	YES;
}