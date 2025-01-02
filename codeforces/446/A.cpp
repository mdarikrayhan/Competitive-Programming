#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lld long double
#define endl "\n"
#define in insert
#define pb push_back
#define eb emplace_back
#define Sort(a) sort(a.begin(),a.end())
#define GSort(a) sort(a.begin(),a.end(),greater<long long int>())
#define vi vector<int>
#define vll vector<long long int>
#define vovll vector<vector<ll>>
#define vpi vector<pair<long long int , long long int>>
#define mll map<long long int,long long int>
#define F first
#define S second
#define max_e(x) *max_element(x.begin(), x.end())
#define min_e(x) *min_element(x.begin(), x.end())
#define inf numeric_limits<long long>::max()
#define all(x) x.begin(),x.end()
#define sz size()
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define f(i,a,b) for(ll i = a; i < b; i++)
#define fr(i,a,b) for(ll i = a; i >= b; i--)
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    ll t;
    // cin>>t;
    t=1;
    while(t--)
    {
        ll n; cin>>n;
        ll a[n]; f(i,0,n) cin>>a[i];
        vll pref(n+1);pref[0]=1;
        if(n==1)
        {
            cout<<1<<endl;
            continue;
        }
        f(i,1,n)
        {
            if(a[i]>a[i-1]) pref[i]=1+pref[i-1];
            else pref[i]=1;
        }
        ll x=max_e(pref);
        vll suff(n+1);suff[n-1]=1;
        fr(i,n-2,0)
        {
            if(a[i]<a[i+1]) suff[i]=1+suff[i+1];
            else suff[i]=1;
        }
        ll y=max_e(suff);
        ll ans=max(x+1,y+1);
        f(i,1,n-1)
        {
            if(a[i-1]+1<a[i+1])
            {
                ans=max(ans,pref[i-1]+suff[i+1]+1);
            }
        }
        if(pref[n-1]==n)
        {
            cout<<n<<endl;
            continue;
        }
        cout<<ans<<endl;




    }
    return 0;
}