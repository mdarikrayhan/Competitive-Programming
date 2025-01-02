#include<iostream>
#include<cstring>
#include<vector>
#include<random>
#include<chrono>
#include<unordered_map>
using namespace std;
using LL = long long;

int qpow(int a, int b, int mod){
    int res = 1;
    while (b){
        if (b & 1) res = 1LL * res * a % mod;
        a = 1LL * a * a % mod;
        b >>= 1;
    }
    return res;
}

int main(){

#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dist(1, 3);

    int a, b, p;
    cin >> a >> b >> p;    
    const int sq = sqrt(1e9 + 9);
    unordered_map<int, vector<int> > mp;
    for(int i = 1; i <= sq; i++){
        vector<int> v;
        v.reserve(100);
        int cur = a;
        for(int i = 0; i < 100; i++){
            int op = dist(rnd);
            if (op == 1){
                cur += 1;
                if (cur >= p) cur -= p;
            }
            else if (op == 2){
                cur -= 1;
                if (cur < 0) cur += p; 
            }
            else{
                cur = qpow(cur, p - 2, p);
            }
            v.push_back(op);
        }
        mp[cur] = v;
    }
    while(1){
        vector<int> v;
        v.reserve(100);
        int cur = b;
        for(int i = 0; i < 100; i++){
            int op = dist(rnd);
            if (op == 2){
                cur += 1;
                if (cur >= p) cur -= p;
            }
            else if (op == 1){
                cur -= 1;
                if (cur < 0) cur += p; 
            }
            else{
                cur = qpow(cur, p - 2, p);
            }
            v.push_back(op);
            if (mp.contains(cur)){
                auto ans = mp[cur];
                ans.insert(ans.end(), v.rbegin(), v.rend());
                cout << ans.size() << '\n';
                for(auto x : ans) cout << x << ' ';
                cout << '\n';
                return 0;
            }
        }
    }

}