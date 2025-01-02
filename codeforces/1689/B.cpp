#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
const ll mod = 1e9 + 7;
#define fr first
#define sc second
#define pb push_back
#define inf (1LL<<62)
#define all(v) v.begin(), v.end()
#define all1(v) v.begin()+1, v.end()
#define done(x){ cout << x << endl;return;}
#define f(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i < n; i++)
#define rep(i, st, end) for(int i=st; i<end; i++)
#define rrep(i,st,end) for(int i=st; i>=end; i--)


const ll N = 2e5+ 5;
const ll INF=1e18;



void solve(void){
    
    
    ll n;
    cin>> n;

    ll p[n];
    set<ll> s;

    f(i, n){
        cin>> p[i];
        s.insert(p[i]);
    }

    if(n== 1){
        done(-1)
    }

    vll ans;

    ll prev;
    f(i, n){
        auto itr = s.begin();
        
        if(i== n-1){
            if((*itr)!= p[i]){
                ans.pb((*itr));
            }
            else{
                ll val = ans.back();
                ans.pop_back();
                ans.pb((*itr));
                ans.pb(val);
            }
        }
        else{
            if((*itr)== p[i]){
                itr++;
            }
            ans.pb((*itr));
            s.erase(itr);
        }
    }

    for(auto it: ans){
        cout<<it<<" ";
    }

    cout<<endl;
    return ;

}

int main()
{
    ll t;
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    t = 1;
    cin >> t;
    f(i, t) solve();
    return 0;
}