#include <bits/stdc++.h>
using namespace std;
#define READ freopen("input.txt", "r", stdin); 
#define WRITE freopen("output.txt", "w", stdout);
#define TR(i,x) for(auto i=x.begin();i!=x.end();i++)
#define EACH(x, a) for (auto& x: a)
#define mem(a,b) memset((a),(b),sizeof(a))
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define rep(i,n) for(int i=0;i<n;i++)
#define repp(i,k,n) for(int i=k;i<=n;i++)
#define repb(i,n) for(int i=1;i<=n;i++)
#define rrep(i, n) for(int i=n-1;i>=0;i--)
#define rrepp(i,k, n) for(int i=n;i>=k;i--)
#define endl '\n'
#define all(x) x.begin(), x.end()
#define Ignore cin.ignore() 
#define int long long
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;



const int MOD = 1000000007;
const int INF = 1e9;
const long long LINF = 1e18;


const int N=2e4+10;

void solve()
{
    int n,m,r,c;
    cin>>n>>m>>r>>c;
    if(n == 1 && m == 1) {
        cout<<n<<" "<<m<<" ";
        cout<<n<<" "<<m<<endl;
        return;
    }
    if(r == 1 && c == 1) {
        if(n == 1 || m == 1) {
            cout<<n<<" "<<m<<" ";
            cout<<n<<" "<<m<<endl;
        }
        else {
            cout<<1<<" "<<m<<" ";
            cout<<n<<" "<<1<<endl;
        }
    }
    else if(r == n && c == m) {
        cout<<1<<" "<<m<<" ";
        cout<<n<<" "<<1<<endl;
    }
    else {
        cout<<1<<" "<<1<<" ";
        cout<<n<<" "<<m<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
     { 
        //  cout<<"Case #"<<i<<": "<<fixed<<setprecision(0);
        solve();
     }
        //  solve();
    return 0;
}