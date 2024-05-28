#pragma GCC optimize(3,"Ofast","inline")
#pragma GCC optimize(2)
#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt") 
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define int long long
using ll = long long;
using LL = long long;
using i64 = long long;
#define double long double
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define lowbit(x) (x & (-(x)))
constexpr ll mod = 1e9 + 7;
constexpr int M = 3e5 + 3;

void slove(){
    int n; cin >> n;
    vector<map<int, int>> cot(100001);
    int res = mod * mod;
    for(int i = 1;i <= n;++i)
    {
        int x, y;
        cin >> x >> y;
        cot[x][y]++;
        cot[x][-1]++;
    }
    int l = cot[0][-1] - 1, r = n + 1;
    auto check = [&](int x)->int{
        int ans = 0, now = cot[0][-1];
        map<int, int> pp;
        for(int i = 1;i <= 100000;++i)
        {   
            if(cot[i][-1] >= x)
            {
                int d = cot[i][-1] - x + 1;
                // cout << d << ' ' << x << endl;
                for(auto it = next(cot[i].begin());it != cot[i].end();++it)
                {
                    if(it->second < d) d -= it->second, now += it->second, ans += it->first * it->second;
                    else 
                    {
                        ans += it->first * d, now += d;
                        if(d != it->second) pp[it->first] += (it->second - d);
                        d = 0;
                    }
                }
            }
            else
                for(auto&[u, v] : cot[i])
                    pp[u] += v;
        }
        int dis = x - now;
        // cout << x << "#" << ans << ' ' << dis << endl;
        if(dis > 0)
        {
            for(auto it = next(pp.begin()); dis and it != pp.end();++it)
            {
                if(it->second < dis) dis -= it->second, now += it->second, ans += it->first * it->second;
                else 
                {
                    ans += it->first * dis, now += dis;
                    dis = 0;
                }
            }
        }

        // cout << x << '#' << ans << ' ' << dis << endl;
        if(dis <= 0)
            return ans;
        else
            return mod * mod + 1;
    };
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(check(mid) < check(mid+1)) 
            r = mid - 1;
        else 
            l = mid + 1;
    }
    cout << min({res, check(r), check(l)}) << endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int t = 1;  
    // cin >> t;
    //init();
    while(t--)
        slove();
    return 0;
}
