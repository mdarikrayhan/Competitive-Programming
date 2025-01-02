#include <bits/stdc++.h>
#define sws cin.tie(0)->sync_with_stdio(0); 
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define endl '\n'
using namespace std;
    
// Extra
#define all(x) x.begin(), x.end()
//

const int MAX = 30;
ll tab[MAX][2];
ll a[MAX], b[MAX];
int n;

ll dp(int i, int last) {
    if(i >= n) return 0;
    ll& res = tab[i][last];
    if(res != -1) return res;

    ll a0 = a[i-1], b0 = b[i-1];
    if(last) swap(a0, b0);

    ll troca = abs(b[i] - a0) + abs(a[i] - b0) + dp(i+1, 1);
    ll ntroca = abs(a[i] - a0) + abs(b[i] - b0) + dp(i+1, 0);

    return res = min(troca, ntroca);
}

int32_t main() {
    #ifndef LOCAL
    sws;
    #endif

    int t;
    cin >> t;

    while(t--) {
        cin >> n;

        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];

        memset(tab, -1, sizeof(tab));

        cout << dp(1, 0) << endl;
    }

    return 0;
}