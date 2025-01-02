#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define oo 0x3f3f3f3fLL
#define INF 0x3f3f3f3f3f3f3f3fLL
#define mem(a,n) memset((a),n,sizeof (a))
#define sz(s) (int) (s.size())
#define all(v) v.begin(), v.end()
void fast();
ll gcd(ll x, ll y) { return(!y ? x : gcd(y, x % y)); }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }
int dx[]{ 1, -1, 0, 0, 1, 1, -1, -1 };
int dy[]{ 0, 0, 1, -1, 1, -1, 1, -1 };
using namespace std;
const int N = 5000+5;
int fr[N+5], suf[N+5];
int main() {

    fast();
    int n; cin >> n;
    vector<int>v(n);
    for (auto& it : v)cin >> it;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++)
            fr[abs(v[i] - v[j])]++;
    }
    for (int i = N-1; i >= 0; i--)
        suf[i] = fr[i] + suf[i + 1];
    ll cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; i+j+1 < N; j++) {
            cnt += 1LL*fr[i] * fr[j] *suf[i+j+1];
        }
    }
    double ans = cnt;
    //cout << cnt << "\n";
    for (int i = 0; i < 3; i++)
        ans /= (n * (n - 1)) / 2;
    cout << fixed << setprecision(10);
    cout << ans;


    return 0;
}
void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
   			 		 	   	  	 	 				   	