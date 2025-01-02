#include<iostream>
#include<cstring>
#include<vector>
#include<array>
using namespace std;
using LL = long long;

int main(){

#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    vector<array<int, 4> > cand;

    auto check = [&](int a, int b, int c, int d){
        if ((a + b + c + d) % 4 != 0) return false;
        if ((a + b - c - d) % 4 != 0) return false;
        if ((a - b + c - d) % 4 != 0) return false;
        return true;
    };

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 4; k++){
                for(int t = 0; t < 4; t++){
                    if (check(i, j, k, t)){
                        cand.push_back({i, j, k, t});
                    }
                }
            }
        }
    }

    int T;
    cin >> T;
    while(T--){
        LL mx[8]{};
        memset(mx, -0x3f, sizeof mx);
        int n;
        cin >> n;
        LL x[3];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 3; j++) cin >> x[j];
            for(int j = 0; j < 1 << 3; j++){
                LL sum = 0;
                for(int k = 0; k < 3; k++){
                    if (j >> k & 1){
                        sum += x[k];
                    }
                    else{
                        sum -= x[k];
                    }
                }
                mx[j] = max(mx[j], sum);
            }
        }

        auto check = [&](LL mid){
            LL val[8];
            for(int i = 0; i < 8; i++){
                val[i] = mx[i] - mid;
            }
            pair<LL, LL> rng[4];
            for(int i = 0; i < 4; i++){
                LL l = val[i], r = -val[i ^ 7];
                if (l > r) return false;
                rng[i] = {l, r};
            }
            for(auto &arr : cand){
                bool ok = true;
                LL mn[4], mx[4];
                for(int i = 0; i < 3; i++){
                    LL k1 = rng[i].first;
                    while((k1 % 4 + 4) % 4 != arr[i]){
                        k1 += 1;
                    } 
                    if (k1 > rng[i].second){
                        ok = false;
                        break;
                    }
                    mn[i] = k1;
                    LL k2 = rng[i].second;
                    while((k2 % 4 + 4) % 4 != arr[i]){
                        k2 -= 1;
                    } 
                    mx[i] = k2;
                }
                if (!ok) continue;
                LL t1 = mn[1] + mn[2] - mx[0];
                LL t2 = mx[1] + mx[2] - mn[0];
                t1 = max(t1, rng[3].first);
                t2 = min(t2, rng[3].second);
                while((t1 % 4 + 4) % 4 != arr[3]) t1 += 1;
                if (t1 <= t2) 
                    return true;
            }
            return false;
        };

        LL l = 0, r = 3e18;
        while(l < r){
            LL mid = (l + r) / 2;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }

        auto dis = [&](array<LL, 3> a, array<LL, 3> b){
            LL ans = 0;
            for(int i = 0; i < 3; i++){
                ans += abs(a[i] - b[i]);
            }
            return ans;
        };

        auto get = [&](LL mid){
            LL val[8];
            for(int i = 0; i < 8; i++){
                val[i] = mx[i] - mid;
            }
            pair<LL, LL> rng[4];
            for(int i = 0; i < 4; i++){
                LL l = val[i], r = -val[i ^ 7];
                rng[i] = {l, r};
            }
            for(auto &arr : cand){
                bool ok = true;
                LL mn[4], mx[4];
                for(int i = 0; i < 3; i++){
                    LL k1 = rng[i].first;
                    while((k1 % 4 + 4) % 4 != arr[i]){
                        k1 += 1;
                    } 
                    if (k1 > rng[i].second){
                        ok = false;
                        break;
                    }
                    mn[i] = k1;
                    LL k2 = rng[i].second;
                    while((k2 % 4 + 4) % 4 != arr[i]){
                        k2 -= 1;
                    } 
                    mx[i] = k2;
                }
                if (!ok) continue;
                LL t1 = mn[1] + mn[2] - mx[0];
                LL t2 = mx[1] + mx[2] - mn[0];
                t1 = max(t1, rng[3].first);
                t2 = min(t2, rng[3].second);
                while((t1 % 4 + 4) % 4 != arr[3]) t1 += 1;
                while((t2 % 4 + 4) % 4 != arr[3]) t2 -= 1;
                if (t1 <= t2){
                    mn[3] = t1;
                    mx[3] = t2;
                    LL t[4];
                    t[0] = mn[0];
                    t[3] = mn[3];
                    t[1] = mx[1];
                    if (t[0] + t[3] - t[1] < mn[2]){
                        LL need = (mn[2] - (t[0] + t[3] - t[1]));
                        need = min(need, mx[0] - mn[0]);
                        t[0] += need;
                    }
                    if (t[0] + t[3] - t[1] < mn[2]){
                        LL need = (mn[2] - (t[0] + t[3] - t[1]));
                        need = min(need, mx[3] - mn[3]);
                        t[3] += need;
                    }
                    if (t[0] + t[3] - t[1] < mn[2]){
                        LL need = (mn[2] - (t[0] + t[3] - t[1]));
                        need = min(need, mx[1] - mn[1]);
                        t[1] -= need;
                    }
                    t[2] = t[0] + t[3] - t[1];
                    LL z = -(__int128_t(t[0]) + t[1] + t[2] + t[3]) / 4;
                    LL y = (__int128_t(t[2]) + t[3] - t[0] - t[1]) / 4;
                    LL x = (__int128_t(t[1]) + t[3] - t[0] - t[2]) / 4;
                    cout << x << ' ' << y << ' ' << z << '\n';
                    // cout << dis({x, y, z}, {-712257566754296354, -593963623968111530, 641236676234303465}) << '\n';
                    // cout << dis({x, y, z}, {984585935731393543, -357593808334107843, 419010905666331961}) << '\n';
                    return;
                }
            }
        };
        get(r);
    }

}