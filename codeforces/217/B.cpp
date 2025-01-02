#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef pair<double,double> pdd;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<vector<ll> > vvl;
typedef vector<vector<pl> > vvpl;
typedef vector<pl> vpl;
typedef vector<pi> vpi;
ll MOD = 998244353;
ll MOD7 = 1e9 + 7;
double eps = 1e-12;
#define loop(i,e) for(ll i = 0; i < e; i++)
#define loopf(i,s,e) for(ll i = s; i < e; i++)
#define rloop(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 
int bad(string &s){
    int ans = 0;
    for(int i = 1; i<s.size();i++){
        if(s[i] == s[i-1]) ans++;
    }
    return ans;
}
void solve(){
   int n, r;
   cin >> n >> r;
   string ans = "IMPOSSIBLE";
   if(n==1 and r== 1){
    cout << "0" << ln << "T" << ln;
    return;
   }
   int mn = 2*n;
   for(int i = 1; i<r; i++){
        int s = 0;
        int a = r, b = i;
        if(gcd(r, i) > 1) continue;
        string temp = "";
        while(a and b){
            if(a > b) temp.pb('T'), a = a-b;
            else temp.pb('B'), b = b-a;
            if(temp.size() > n) break;
        }
        if(a and b) continue;
        if(temp.size()==n and bad(temp) < mn){
            ans = temp;
            mn = bad(temp);
        }

        for(int j = 1; j<temp.size();j++){
            if(temp[j] == 'T') temp[j] = 'B';
            else temp[j] = 'T';
        }
    
        
        if(temp.size()==n and bad(temp) < mn){
          
            ans = temp;
            mn = bad(temp);
        }

   }

   if(ans[0] == 'T') cout << mn << ln;
   cout << ans << ln;
}
int main()
{
    fast_cin();
    solve();
    return 0;
}

