#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int N = 1000 + 7;

struct seg{
    int x1, y1, x2, y2;
    seg(){};
};

struct line{
    long long A, B, C;
    line(){};
    line(seg a){
        A = a.y1 - a.y2;
        B = a.x2 - a.x1;
        C = -A * a.x1 - B * a.y1;
    };
};

int n;
seg a[N];

int get(seg a){
    int dx = a.x1 - a.x2;
    int dy = a.y1 - a.y2;
    return __gcd(abs(dx), abs(dy)) + 1;
}

long long det(long long a, long long b, long long c, long long d){
    return a * d - b * c;
}

bool in(int x, int l, int r){
    if (l > r) swap(l, r);
    return (l <= x && x <= r);
}

bool inter(seg a, seg b, int& x, int& y){
    line l1(a), l2(b);
    long long dx = det(l1.C, l1.B, l2.C, l2.B);
    long long dy = det(l1.A, l1.C, l2.A, l2.C);
    long long d = det(l1.A, l1.B, l2.A, l2.B);
    if (d == 0)
        return false;
    if (dx % d != 0 || dy % d != 0)
        return false;
    x = -dx / d;
    y = -dy / d;
    if (!in(x, a.x1, a.x2) || !in(y, a.y1, a.y2))
        return false;
    if (!in(x, b.x1, b.x2) || !in(y, b.y1, b.y2))
        return false;
    return true;
}

int main() {
    scanf("%d", &n);
    forn(i, n)
        scanf("%d%d%d%d", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2);
    
    int ans = 0;
    int x, y;
    forn(i, n){
        ans += get(a[i]);
        set<pair<int, int>> pts;
        forn(j, i)
            if (inter(a[i], a[j], x, y))
                pts.insert({x, y});
        ans -= pts.size();
    }
    
    printf("%d\n", ans);
    return 0;
}