#include <bits/stdc++.h>
using namespace std;
/*
leetcode essentials:
#define fl(i,a,b) for(ll i=a;i<b;i++)
#define rfl(i,a,b) for(ll i=a; i>=b;--i)
*/
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define C1(x) cin >> x
#define C2(x,y) cin >> x >> y
#define C3(x,y,z) cin >> x >> y >> z
#define C4(x,y,z,w) cin >> x >> y >> z >> w
#define C5(x,y,z,w,v) cin >> x >> y >> z >> w >> v
#define Cn(x) cout << x << endl
#define CC(x) cout << x << " "
#define fl(i,a,b) for(ll i=a;i<b;i++)
#define rfl(i,a,b) for(ll i=a; i>=b;--i)
#define w(x) ll x; cin >> x; while(x--)
#define yn(flag) cout << ((flag) ? "Yes\n" : "No\n")
#define lowbit(x) (x&-x)
typedef long long ll;
 // u have nothing:
// practice -> succes::
// everyone challenge u since u are weak;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 100005;
const ll maxn = 2e5+10, mod = 1e9 + 7, inf = 1e10;
#define print(x){ cout << x << "\n"; return;}
void solve() {
   
   ll n;
   cin >> n;
   ll a,b,c,d=0;
   vector<pair<ll, vector<ll>>>vp; 
   
        
        fl(i,0,4) {
                C4(a,b,c,d);
                ll juice ,  choco =0;
                juice = min(a,b);choco = min(c,d);
                if(juice + choco <= n) {
                        cout << i+1 << " " << juice << " " << n-juice ; return ;
                }

        }
        
        cout << -1 << "\n";return;
   
        
}
 
int32_t main() {
  cin.tie(0)->sync_with_stdio(0); 
  int tt = 1;
  //cin >> tt;
  while (tt --) solve();
}
 