#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
using LL = long long;

struct Node{
    LL a, b;
    
    bool operator<(const Node &t) const {
        return a * t.b < b * t.a;
    }
};

int main(){

#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n, c, d;
    cin >> n >> c >> d;
    vector<Node> p[2][2];
    int cnt[2][2]{};
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        x -= c, y -= d;
        if (abs(x) != 0 && abs(y) != 0){
            p[x > 0][y > 0].push_back({abs(x), abs(y)});
        }
        else if (abs(x) == 0){
            cnt[0][y > 0] += 1;
        }
        else{
            cnt[1][x > 0] += 1;
        }
    }
    LL ans = 0;
    
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            sort(p[i][j].begin(), p[i][j].end());
        }
    }

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(auto p1 : p[i][j]){
                auto &v = p[i ^ 1][j ^ 1];
                int pos1 = lower_bound(v.begin(), v.end(), p1) - v.begin();
                int pos2 = upper_bound(v.begin(), v.end(), p1) - v.begin();
                int tot = v.size();
                // 没有含0的
                ans += 1LL * pos1 * (tot - pos2);
                if (i == 0 && j == 0){
                    ans += 1LL * pos1 * p[1][0].size();
                }
                else if (i == 0 && j == 1){
                    ans += 1LL * pos1 * p[1][1].size();
                }
                else if (i == 1 && j == 1){
                    ans += 1LL * pos1 * p[0][1].size();
                }
                else{
                    ans += 1LL * pos1 * p[0][0].size();
                }
                // 一个含0的
                if (i == 1 && j == 1){
                    ans += 1LL * pos1 * cnt[0][1];
                    ans += 1LL * pos1 * cnt[1][0];
                }
                else if (i == 1 && j == 0){
                    ans += 1LL * pos1 * cnt[0][0];
                    ans += 1LL * pos1 * cnt[1][0];
                }
                else if (i == 0 && j == 1){
                    ans += 1LL * pos1 * cnt[0][1];
                    ans += 1LL * pos1 * cnt[1][1];
                }
                else{
                    ans += 1LL * pos1 * cnt[0][0];
                    ans += 1LL * pos1 * cnt[1][1];
                }
            }
        }
    }
    // 两个含0的
    {
        ans += 1LL * cnt[0][0] * cnt[1][1] * p[0][1].size();
        ans += 1LL * cnt[0][1] * cnt[1][0] * p[1][0].size();
    }
    {
        ans += 1LL * cnt[0][0] * cnt[1][0] * p[1][1].size();
        ans += 1LL * cnt[0][1] * cnt[1][1] * p[0][0].size();
    }
    // 一个含0的,有克制关系
    {
        ans += 1LL * p[0][0].size() * p[0][1].size() * cnt[1][1];

        ans += 1LL * p[0][1].size() * p[1][1].size() * cnt[0][0];

        ans += 1LL * p[1][1].size() * p[1][0].size() * cnt[1][0];

        ans += 1LL * p[1][0].size() * p[0][0].size() * cnt[0][1];
    }
    cout << ans << '\n';

}