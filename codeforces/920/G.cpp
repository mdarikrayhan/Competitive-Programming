/**
*   author: lazyhash(yashkundu)
*   created: 25 May, 2024 | 15:35:48
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 1e6+5;
int spf[MAXN];

void precompute() {
    for(int i=1;i<MAXN;i++) spf[i] = i;
    for(int i=2;i*i<MAXN;i++) {
        if(spf[i]!=i) continue;
        for(int j=i*i;j<MAXN;j+=i) {
            if(spf[j]==j) spf[j] = i;
        }
    }
}

vector<int> primes(int n) {
    vector<int> v;
    while(n>1) {
        int k = spf[n];
        v.push_back(k);
        while(n%k==0) n /= k;
    }
    return v;
}

int x, p, k;


int find(int n, vector<int> &p) {
    int m = p.size();
    int ans = 0;
    for(int mask=1;mask<(1<<m);mask++) {
        int cur = mask;
        int cnt = 0;
        int num = 1;
        for(int j=0;j<m;j++) {
            if(cur&1) {
                cnt++;
                num *= p[j];
            }
            cur = cur>>1;
        }
        if(cnt&1) ans += n/num;
        else ans -= n/num;
    }
    return n - ans;
}

 
void solve() {
    cin >> x >> p >> k;
    vector<int> v = primes(p);
    k += find(x, v);


    int l = 1, r = 1e9;
    while(l<r) {
        int mid = (l+r)>>1;
        if(find(mid, v)<k) l = mid+1;
        else r = mid;
    }

    cout << l << "\n";

}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    cin >> t;
    precompute();
    while (t--) {
        solve();
    }
    return 0;
}
/* stuff you should look for
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/