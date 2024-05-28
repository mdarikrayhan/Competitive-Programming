#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
using LL = long long;
const int maxn = 2005;
int l[maxn][maxn], r[maxn][maxn];

int find(int p[maxn], int x){
    return p[x] == x ? x : p[x] = find(p, p[x]);
}

int main(){

#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n, m, q;
    cin >> n >> m >> q;
    bool rev = false;
    if (n > m){
        rev = true;
        swap(n, m);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= m + 1; j++){
            l[i][j] = j;
            r[i][j] = j;
        }
    }

    auto dis = [&](pair<int, int> a, pair<int, int> b){
        return abs(a.first - b.first) + abs(a.second - b.second);
    };

    auto update = [&](pair<int, int> &a, pair<int, int> b){
        if (rev){
            if (make_pair(b.second, b.first) < make_pair(a.second, a.first)){
                a = b;
            }
        }
        else{
            if (b < a){
                a = b;
            }
        }
    };

    while(q--){
        int x, y;
        cin >> x >> y;
        if (rev) swap(x, y);
        int ans = 1e9;
        pair<int, int> best;
        for(int i = 0; i <= ans; i++){
            if (x - i >= 1){
                int L = find(l[x - i], y);
                int R = find(r[x - i], y);
                if (L >= 1){
                    int dist = dis({x - i, L}, {x, y});
                    if (dist < ans){
                        ans = dist;
                        best = {x - i, L};
                    }
                    else if (dist == ans){
                        update(best, make_pair(x - i, L));
                    }
                }
                if (R <= m){
                    int dist = dis({x - i, R}, {x, y});
                    if (dist < ans){
                        ans = dist;
                        best = {x - i, R};
                    }
                    else if (dist == ans){
                        update(best, make_pair(x - i, R));
                    }
                }
            }
            if (x + i <= n){
                int L = find(l[x + i], y);
                int R = find(r[x + i], y);
                if (L >= 1){
                    int dist = dis({x + i, L}, {x, y});
                    if (dist < ans){
                        ans = dist;
                        best = {x + i, L};
                    }
                    else if (dist == ans){
                        update(best, make_pair(x + i, L));
                    }
                }
                if (R <= m){
                    int dist = dis({x + i, R}, {x, y});
                    if (dist < ans){
                        ans = dist;
                        best = {x + i, R};
                    }
                    else if (dist == ans){
                        update(best, make_pair(x + i, R));
                    }
                }
            }
        }
        auto [xx, yy] = best;
        if (rev) cout << yy << ' ' << xx << '\n';
        else cout << xx << ' ' << yy << '\n';
        l[xx][yy] = yy - 1;
        r[xx][yy] = yy + 1; 
    }

}