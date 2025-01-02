#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int signed long long
#define rep(i,a,b) for(ll i=a;i<=b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define pb emplace_back
#define ppb push_back
#define pp pop_back
#define mod 1000000007
#define inf 1e18
#define pii pair<int,int>
#define pll pair<long long,long long>
#define PI 3.141592653589793238462
#define all(x) (x).begin(), (x).end()
#define uall(x) (x).rbegin(), (x).rend()
#define loop(i,a,n,b) for(long long i=a;i<n;i+=b)
#define reloop(i,a,n,b) for(long long i=a;i>=n;i-=b)
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define sp ' '
#define endl "\n"

typedef unsigned long long ull;
typedef long double lld;

int power(int a, int b){
    if(b==0){
        return 1;
    }
    int x=power( a, b/2 );
    int ans=1; 
        if(b%2==0){
            ans =( x * x ) % mod;
        }
        else{
          ans =( x * x * a ) % mod;
    }
    return ans;
}

void solve(){
    int n;
    cin>>n;
    cout<<6*power(4,powl(2,n)-2)%mod<<"\n";
}

signed main(){
    fast;
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}