#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vll vector<ll>
#define vpll vector<pair<ll,ll>>
#define vpi vector<pair<int,int>>
#define fr first
#define sc second
#define rp(i,le,ri) for(ll i=le;i<ri;i++)
#define rrp(i,ri,le) for(ll i=ri;i>=le;i--)
#define hp priority_queue<ll, vector<ll>, greater<>>
#define revhp priority_queue<ll>
inline ll lcm(ll m,ll n) {return(m*n/__gcd(m,n));}

void solve()
{
	ll n,m,k;
	cin>>n>>m>>k; ll j=0,l=0; bool f=0;
	rp(i,0,m)
	{
		cin>>l; if(l==(n+k-1)/k) j++;
		else if(l>(n+k-1)/k) {f=1;}
	}
	if(f) cout<<"NO\n";
	else if(j<=(n-1)%k+1) cout<<"YES\n";
	else cout<<"NO\n";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t; cin>>t;
	while(t--) solve();
}