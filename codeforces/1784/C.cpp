// Har Har Mahadev..
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;
#define ll long long
#define endl "\n"
#define MOD 1000000007
#define pb push_back
#define gcd(a, b) __gcd(a, b)
#define inf 1e17
typedef tree<pair<ll, ll>,null_type,less<pair<ll, ll>>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset; //store values as pairs with second element distinct
typedef tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set; // X.find_by_order(k) return kth element (0 indexed). X.order_of_key(k) returns count of elements strictly less than k.

long long power(long long x,long long y,long long m=MOD) 
{ 
    long long p=m;long long res = 1;x = x % p;if (x == 0) return 0;
    while (y > 0) 
    { 
        if (y & 1) res = (res*x) % p; 
        y = y>>1;
        x = (x*x) % p; 
    } 
    return res; 
}

void update(vector<ll>&bit,ll ind,ll val)
{
    if(ind==0) return;
    while(ind<bit.size())
    {
        bit[ind]+=val;
        ind+=(ind&(-ind));
    }
}

ll query(vector<ll>&bit,ll ind)
{
    ll r=0;
    while(ind)
    {
        r+=bit[ind];
        ind-=(ind&(-ind));
    }
    return r;
}

void solve()
{
    ll n;cin>>n;
    vector<ll>vec(n+1);
    for(ll i=1;i<=n;i++) cin>>vec[i];
    vector<ll>v(n+10);
    
    vector<ll>bit1(n+1);
    map<ll,vector<ll>>mp;
    for(ll i=1;i<=n;i++) mp[vec[i]].pb(i);
    vector<ll>pre(n+10);
    for(ll i=1;i<=n;i++){
        ll sz=mp[i].size();
        if(sz==0) continue;
        bool f=0;
        ll mx=n+1;
        for(ll j=0;j<sz;j++){
            ll ind=mp[i][j];
            ll p=query(bit1,ind);
            if(p==i-1){
                mx=min(mx,ind);
                //pre[ind+1]-=i;
            }
            else if(p<i-1){
                ll low=ind;
                ll high=n;
                ll res=n+1;
                while(low<=high){
                    ll mid=(low+high)/2;
                    ll a=query(bit1,mid);
                    if(a>=i-1){
                        res=mid;
                        high=mid-1;
                    }
                    else low=mid+1;
                }
                pre[ind]+=i;
                pre[res]-=i;
                v[ind]++;
                v[res]--;
                mx=min(mx,res);
                update(bit1,ind,1);
                if(res<=n)
                update(bit1,res,-1);
            }
            else continue;
        }
        if(mx!=n+1) {pre[mx]+=i;v[mx]++;update(bit1,mx,1);}
    }
    for(ll i=1;i<=n;i++) v[i]+=v[i-1];
    for(ll i=1;i<=n;i++) pre[i]+=pre[i-1];
    for(ll i=1;i<=n;i++) v[i]=pre[i]-v[i]*(v[i]+1)/2;
    for(ll i=1;i<=n;i++) cout<<v[i]<<" ";cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    clock_t z = clock();
    cout.setf(ios::fixed, ios::floatfield);cout.setf(ios::showpoint);
    cout << setprecision(20);
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll t = 1;
    cin>> t;
    while (t--)
    {
        solve();
    }
    cerr << "\n\nRuntime is: " << ((double)(clock() - z) / CLOCKS_PER_SEC);
    return 0;
}        