#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define F first
#define S second
#define all(T) T.begin(),T.end()
#define rall(T) T.rbegin(),T.rend()
#define fast ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define yes cout << "Yes" << endl ;
#define no cout << "No" << endl ;
#define bob cout << "Bob" << endl;
#define alice cout << "Alice" << endl;
#define dbg(x) cout << "#x = " << x << endl;
#define dbg1(x,y) cout << "#x = " << x << "  #y = " << y << endl;
const int mod = 1e9+7;
const int N = 1e6+5;

struct P{
    ll x,y;
    void read(){
        cin >> x >> y;
    }
    P operator -(const P& b) const{
        return P{x - b.x , y - b.y};
    }
    void operator -=(const P& b){
        x -= b.x;
        y -= b.y;
    }
    ll operator *(const P& b) const{
        return x*b.y - y*b.x;
    }
};

string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool sorta(const pair<int, int> &a, const pair<int, int> &b) { return (a.S < b.S); }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i*i<=a;++i) if (a%i==0) return 0; return 1; }
ll exp(ll a,ll b){ll res=1;while(b>0){if(b&1)res=res*a;a=a*a;b/=2;}return res;}
ll gcd(ll a,ll b){return b==0 ? a:gcd(b,a%b);}
ll lcm(ll a,ll b){return (a/gcd(a,b))*b;}

void solve()
{
    int n;cin >> n;
    for(int i = 1;i<n;i++){
        for(int j = 1;j<n;j++){
            cout << ((i*j)/n)*10 + (i*j)%n << " ";
        }
        cout << endl;
    }
}
int main()
{
    fast;
    /*
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    */
    int t;
    t = 1 ;
    //cin>>t;
    while(t--){
        solve();
    }
}
