#include <bits/stdc++.h>
#define int long long
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define vb vector<bool>
#define matrix vector<vector<int>>
#define pii pair<int, int>
#define mii map<int, int>
#define mod 1000000007
// #define inf 100000000000
#define fr first
#define sc second

#define rep(i,n) for (int i = 0;i < n;i++)
#define REP(i,k,n) for (int i = k;i < n;i++)
#define bw(i,l,r) (i >= l && i < r)
#define all(a) (a).begin(), (a).end()
#define vii(a,n) vector<int> a(n); rep(i,n) cin>>a[i];

using namespace std;

#define MAXN 100000
int inf = LLONG_MAX/2;

void print(){cout<<endl;}
void print(bool endline) {if(endline)cout<<endl;}
template<typename T, typename ...TAIL>
void print(const T &t, TAIL... tail)
{
    cout<<t<<' ';
    print(tail...);
}

template<typename T>
void printl(const T &t) {
    for (auto val: t) cout<<val<<' ';
    print();
}

int extended_euclidean(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extended_euclidean(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
 
 
int inverse(int a) {
    int x, y;
    int g = extended_euclidean(a, mod, x, y);
    if (g != 1) {
        return -1;
    }
    else {
        return x;
    }
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int t;
    cin>>t;
    
    while(t--) {
        int n, m, k;
        cin>>n>>m>>k;

        int sum = 0;
        int N = n*(n-1)/2;
        rep (i, m) {
            int a, b, c;
            cin>>a>>b>>c;

            sum += c;
        }

        int a = sum % mod * k % mod * (N % mod) % mod;
        int b = N % mod * N % mod;
        b %= mod;

        int p = k*(k-1)/2 % mod * (m % mod) % mod;

        a += p;
        a %= mod;

        print(((a * inverse(b) % mod) + mod) % mod);

    }
    return 0;
}