#include<bits/stdc++.h>
using namespace std;
using LL = long long;

struct Point{
    LL x, y;

    Point operator-(const Point &t) const {
        return {x - t.x, y - t.y};
    }

    LL operator^(const Point &t) const {
        return x * t.y - y * t.x;
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

    int n;
    cin >> n;
    vector<Point> p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i].x >> p[i].y;
    }

    auto C2 = [&](int x){
        return x * (x - 1) / 2;
    };
    auto quad = [&](Point p){
        if (p.y < 0) return 1;
        if (p.y > 0) return 3;
        if (p.x > 0) return 2;
        return 0;
    };

    LL ans = 0;
    for(int i = 0; i < n; i++){
        vector<Point> q;
        for(int j = 0; j < n; j++){
            if (i != j){
                q.push_back(p[j] - p[i]);
            }
        }
        sort(q.begin(), q.end(), [&](Point a, Point b){
            int q1 = quad(a), q2 = quad(b);
            if (q1 != q2) return q1 < q2;
            return (a ^ b) > 0;
        });

        const int m = q.size();
        q.resize(2 * m);
        for(int j = 0; j < m; j++) q[j + m] = q[j];

        for(int j = 0, k = 0; j < m; j++){
            k = max(k, j + 1);
            while(k < j + m && (q[j] ^ q[k]) > 0) k++;
            int c1 = k - j - 1;
            int c2 = m - 1 - c1;
            ans += 2LL * C2(c1) * C2(c2);
        }
    }
    cout << ans / 4 << '\n';

}