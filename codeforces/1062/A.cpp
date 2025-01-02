#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi > vvi;
typedef pair<int,int> pii;
#define all(a) (a).begin(), (a).end()
#define fr(i,s,e) for(int i = s; i<=e; ++i)
#define rfr(i,s,e) for(int i = s; i>=e; --i)
#define pb push_back
#define mp make_pair
// clang-format off
#define inv(v) for(auto &i:v){cin>>i;}
#define endl "\n"
#define yesprint cout<<"YES\n";
#define noprint cout<<"NO\n";
#define printv(v) for(auto i:v){cout<<i<<" ";}cout<<"\n";
ll ceilDiv(ll a, ll b) { return (a/b) + (a%b > 0); }
// clang-format on

void solve_by_jay_s()
{
    int n;
    cin >> n;

    vi a(n);
    inv(a);
    vi f(1e3+1, 0);
    fr(i,0,n-1){
        f[a[i]]++;
    }

    int cnt = 0, ans = 0;
    int j=1;
    while(j <= 1000 && f[j] != 0){
        j++;
    }
    if(j-2 > 0) ans = j-2;
    // cout << ans << endl;
    fr(i,j+1,1e3){
        if(f[i] == 0){
            if(cnt > 2) ans = max(ans, cnt-2);
            cnt = 0;
        }
        else{
            cnt++;
        }
    }

    // cout << ans << endl; 

    if(f[1000] > 0 && cnt >= 2) ans = max(ans, (cnt-1));
    // if(f[1] > 0 && f[2] > 0) ans += 1;
    // if(f[1000] > 0 && f[999] > 0) ans += 1;

    cout << ans << endl;
}

 

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    // cin >> t;
    // while(t--){
        solve_by_jay_s();
    // }
    return 0;
}