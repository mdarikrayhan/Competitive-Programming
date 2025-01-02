#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define int long long
int bigmod(int b, int p, int mod) {
    b=b%mod;
    int res = 1;
    for(; p; res=(p&1?(1ll*res*b)%mod:res),b=(1ll*b*b)%mod, p/=2);
    return res;
}
void solve();
void preCompute();
vector<int> vt;
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t= 0, tc=1;
    preCompute();
//    cin >> tc;
    while(tc--) {
        solve();
    }


    return 0;
}

int tc = 0;
const int mxn = 1e5+5;
const int N = 100+2;
int q[N], p[N], temp[N];
int target[N];
int match(int n) {
    for(int i=1; i<=n; i++) if(p[i]^target[i]) return 0;
    return 1;
}
void solve() {
    int n, k;
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> q[i];
    for(int i=1; i<=n; i++) cin >> target[i];
    bool ok = 1;
    for(int i=1; i<=n; i++) if(i^target[i]) ok =0;
    if(ok) {
        if(k==0) cout <<"YES";
        else cout <<"NO";
        return;
    }
    bool ok1 = 1, ok2 = 1;
    iota(p+1, p+1+n, 1);
    for(int i=1; i<=n; i++) temp[i] = p[q[i]];
    copy(temp+1, temp+1+n, p+1);
    if(!match(n)) ok1 = 0;
    iota(p+1, p+1+n, 1);
    for(int i=1; i<=n; i++) temp[q[i]] = p[i];
    copy(temp+1, temp+1+n, p+1);
    if(!match(n)) ok2 = 0;
    if(ok1 && ok2) {
        if(k==1) cout <<"YES";
        else cout <<"NO";
        return;
    }

    int cnt = 0;
    iota(p+1, p+1+n, 1);
    while(cnt<k && !match(n)) {
        cnt++;
        for(int i=1; i<=n; i++) {
            temp[i] = p[q[i]];
        }
        copy(temp+1, temp+1+n, p+1);
    }
    if((k-cnt)%2==0 && match(n)) {
        cout << "YES";
        return;
    }
    cnt = 0;
    iota(p+1, p+1+n, 1);
    while(cnt<k && !match(n)) {
        cnt++;
        for(int i=1; i<=n; i++) {
            temp[q[i]]=p[i];
        }

        copy(temp+1, temp+1+n, p+1);
    }
    if((k-cnt)%2==0 && match(n)) {
        cout <<"YES";
        return;
    }

    cout <<"NO";

}

void preCompute() {



}

