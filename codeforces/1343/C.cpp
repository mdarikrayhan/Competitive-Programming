#include<bits/stdc++.h>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef vector<ll>vl;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef map<ll, ll> mll;
typedef set<ll> sll;
 
#define ld long double
#define gcd(a,b)  __gcd(a,b)
#define pb(a) push_back(a)
#define rep(var, start, num) for(ulli var = start; var <num; var++)
#define all(x) x.begin(), x.end()
#define ulli unsigned long long int
#define mp make_pair
#define maxe(v)  *max_element(v.begin(),v.end())
#define mine(v)  *min_element(v.begin(),v.end())
#define out1(x1) cout << x1 << endl;
#define out2(x1,x2) cout << x1 << " " << x2 << endl;
#define out3(x1,x2,x3) cout << x1 << " " << x2 << " " << x3 << endl;
#define cy  cout<<"yes"<<endl;
#define cn cout<<"no"<<endl;
#define CY cout<<"YES"<<endl;
#define CN cout<<"NO"<<endl;
#define F first
#define S second
const ll Max=LONG_MAX;
bool sortbysec(const pair<ll,ll> &a,const pair<ll,ll> &b) { return (a.second < b.second); }
 
void solve()
{
    ll n,maxi,ans=0;
    cin>>n;
    ll a[n];
    rep (i,0,n)
    {
        cin>>a[i];
    }
    maxi=a[0];
    for (ll i=0;i<(n-1);i++)
    {
        if (a[i]*a[i+1]>0)
        {
            maxi=max(maxi,a[i+1]);
            continue;
        }
        ans=ans+maxi;
        maxi=a[i+1];
    }
    ans+=maxi;
    cout<<ans<<endl;
}
 
 
int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#ifndef ONLINE_JUDGE
//    freopen("input.txt","r",stdin);
//freopen ("output.txt","w",stdout);
//#endif
 
int t=1;
cin>>t;
while(t--)
{
    solve();
}
return 0;
}