#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define ll long long
#define MP make_pair
#define ld long double
#define fuk return
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
#define pb push_back
#define tr(it,a) for(auto it=a.begin();it!=a.end();it++)
#define fo(i,n) for(int i=0;i<n;i++)
#define fop(i,x,n) for(int i=x;i<=n;i++)
#define forv(i,l,n) for(int i=l;i>=n;i--)
#define nl  <<  "\n";
typedef  pair<ll,ll>  pl;
typedef vector<ll> vl;
typedef vector < pair <ll,ll > > vp;
typedef vector<bool> vb;
typedef vector<ld> vd;
typedef vector<string> vs;
#define inp(v, n) for(int i=0; i<n; ++i) cin >> v[i];
#define opt(v) for(auto x: v) cout << x << ' '; cout << endl;
const ll mod = 1000000007;
const ll N = 2e5+10;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
ll binpow(ll a, ll b) {
ll result = 1;
while (b > 0) {
if (b & 1)
result *= a;
        a *= a;
a %= mod;
b /= 2;
result %= mod;
}
return result;
}
void solve(){
    ll n,k;
    cin>>n>>k;
    ll a[k];
    fo(i,k) cin>>a[i];
    stack<ll> st;
    ll kp=0;
    ll req=1;
    ll done[n+1];
    fo(i,n+1)done[i]=0;
    fo(i,k){
        done[a[i]]=1;
    }
    fo(i,k){
        while(!st.empty() && st.top()==req){
            req++;
            st.pop();
        }
        if(!st.empty())
            if(st.top()<a[i]){
                kp=-1;
                break;
            }
        st.push(a[i]);
    }
    if(kp==-1)
    {cout<<kp nl
    return;
    }
    ll x;

    if(!st.empty()){
        fo(i,k){
            cout<<a[i]<<" ";
        }
        ll last=-1;
        fop(i,1,n){
            if(!done[i]){
                last=i;
                break;
            }
        }
        while(!st.empty()){
            ll x=st.top();
            st.pop();
            forv(i,x,last){
                if(!done[i]){
                    done[i]=1;
                    cout<<i<<" ";
                }
            }
            last=x;
        }
        forv(i,n,1){
            if(!done[i]){
                cout<<i<<" ";
            }
        }
        cout nl
    }else{
        fo(i,k){
            cout<<a[i]<<" ";
        }
        forv(i,n,1) if(!done[i]) cout<<i<<" ";
        cout nl
    }
}
signed main(){
    IOS
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    solve();
    return 0;
}