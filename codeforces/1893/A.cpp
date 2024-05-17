// hola soy Dember :D
// 31/03/2024
 
#include <bits/stdc++.h>
 
#define ll long long 
#define pll pair<ll,ll>
#define F first
#define S second 
#define Z size()
#define pb push_back
#define bp pop_back
#define fo(x,y,z) for(ll x=y; x<=z; x++)
#define of(x,y,z) for(ll x=y; x>=z; x--)
#define all(n) n.begin(), n.end()
#define arr(x,y,z) x+y, x+y+z
 
using namespace std;
 
void value(ll in){cout<<((in)?"YES\n":"NO\n");}
 
const ll N=2e5+5, M=3e3+5, mod=998244353, md=1e9+7, inf=1e18;
 
ll n, m, k, xd, zd, a[N];
ll ans;
vector<ll> v;
set<ll> f;
queue<ll> q;
 
void CD(){
    cin>>n>>k; k=min(n,k);xd=n-1;
    
    fo(i,0,n-1)cin>>a[i];
    
    fo(i,1,k){
        if(a[xd]>n)return value(0), void();
        xd=(xd-a[xd]+n)%n;
    }
    
    value(1);
    
    return;
}
 
int main()
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int t=1; 
    cin>>t;
    
    while(t--){
        CD();
    }
 
    return 0;
}