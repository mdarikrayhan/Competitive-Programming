#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second

int t, n, m, k, a[1000005], f[1000005], p[20005], mod = 1e9 + 7;
string s;
vector<int> v, nt;
mt19937_64 rng;

int mul(int x, int y){
    if(y == 0) return 1;
    int ans = mul(x, y / 2);
    if(y % 2 == 0) return (ans * ans) % mod;
    else return (((ans * ans) % mod) * x) % mod;
}

void prime(){
    for(int i = 2; i <= 2e4; i++) p[i] = 1;
    for(int i = 2; i * i <= 2e4; i++){
        if(p[i]){
            for(int j = i * i; j <= 2e4; j += i) p[j] = 0;
        }
    }
    for(int i = 2; i <= 2e4; i++){
        if(p[i]) nt.push_back(i);
    }
}
void solve(){
    int num = 0;
    for(int i = 1; i <= n; i++){
        if(f[i] >= n){
            num = i; break;
        }
    }
    v.push_back(0);
    for(int i = 0; i < num; i++){
        v.push_back(i);
        for(int j = 2; j <= (num - 1) / 2; j++){
            int gcd = __gcd(j, num);
            if(i >= gcd) continue;
            for(int k = 1; k <= num / gcd; k++) v.push_back((i + k * j) % num);
        }
        v.push_back((i + 1) % num);
    }
    if(!(k & 1)) v.push_back(num / 2);
    while(v.size() > n) v.pop_back();
    for(auto i: v) cout << nt[i] <<" "; cout << "\n";
}

signed main(){
    ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr);
    rng.seed((int)main ^ time(0));
    #ifdef Kawaii
        auto starttime = chrono::high_resolution_clock::now();
    #endif

    cin >> t;
    for(int i = 1; i <= 2e3; i++) f[i] = i * (i + 1) / 2 - (i - 2) / 2 * (!(i & 1)) + 1;
    prime();
    while(t--){
        cin >> n; v.clear();
        solve();
    }

    #ifdef Kawaii
        auto endtime = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(endtime - starttime).count(); 
        cout << "\n=====" << "\nUsed: " << duration << " ms\n";
    #endif
}