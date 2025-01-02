#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef pair<int,int> ii;
#define y first
#define x second

bool good(int h, int w, int y, int x) {
    if (y < 0 || x < 0) return false;
    if (h > w) {
        swap(h,w);
        swap(y,x);
    }
    if (h == 1) return x >= w-2;
    return y != 0 || x != 0;
}

void f(int h, int w, int y, int x, int dy, int dx, int sy, int sx, vector<ii> &res) {
    if (y == 0 && x == 0) {
        res.emplace_back(dy,dx);
    } else if (good(h-1, w, y-1, w-1-x)) {
        FO(i,0,w) res.emplace_back(dy,dx+sx*i);
        f(h-1, w, y-1, w-1-x, dy+sy, dx+sx*(w-1), sy, -sx, res);
    } else if (good(h, w-1, h-1-y, x-1)) {
        FO(i,0,h) res.emplace_back(dy+sy*i,dx);
        f(h, w-1, h-1-y, x-1, dy+sy*(h-1), dx+sx, -sy, sx, res);
    }
}

void append(vector<ii> &a, vector<ii> &b) {
    a.insert(a.end(), b.begin(), b.end());
}

int main() {
    int h, w, x1, y1, x2, y2;
    scanf("%d %d", &h, &w);
    scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
    y1--; x1--; y2--; x2--;

    bool sxy = false, fx = false, fy = false;

    if (x1 == x2 || (y1 != y2 && h % 2 == 1)) {
        sxy = true;
        swap(h,w);
        swap(x1,y1);
        swap(x2,y2);
    }
    if (x1 > x2) {
        fx = true;
        x1 = w-1-x1;
        x2 = w-1-x2;
    }
    if (y1 == h-2) {
        fy = true;
        y1 = h-1-y1;
        y2 = h-1-y2;
    }

    vector<ii> res;
    if (y1 == y2 && h % 2 == 1 && w % 2 == 0 && x1 % 2 != x2 % 2) {
        if (x1 % 2 == 1) {
            vector<ii> lt, b, rt;
            f(y1+1, x1+1, 0, x1, y1, x1, -1, -1, lt);
            f(h-y1-1, w, 0, w-1, y1+1, 0, 1, 1, b);
            f(y1+1, w-x1-1, 0, w-x2-1, y1, w-1, -1, -1, rt);

            res = lt;
            append(res, b);
            append(res, rt);
        } else {
            vector<ii> lt, lm, trb, b, tri;
            f(y1+1, x1+1, y1, 0, y1, x1, -1, -1, lt);
            if (x2-x1 > 1) f(y1+1, x2-x1-1, 0, x2-x1-2, 0, x1+1, 1, 1, lm);
            FO(x,x2,w) trb.emplace_back(0, x);
            FO(y,1,y2+1) trb.emplace_back(y, w-1);
            f(h-y1-1, w, 0, 1, y2+1, w-1, 1, -1, b);
            f(y2, w-x2-1, 0, w-x2-2, y2, w-2, -1, -1, tri);

            res = lt;
            append(res, lm);
            append(res, trb);
            append(res, b);
            append(res, tri);
        }
    }else {
        vector<ii> lt, rt, lb, rb;

        f(h, x1+1, y1, 0, 0, x1, 1, -1, lt);
        reverse(lt.begin(),lt.end());
        f(h, w-x1-1, y2, x2-x1-1, 0, x1+1, 1, 1, rt);
        append(lt, rt);

        f(h, x1+1, h-1-y1, 0, h-1, x1, -1, -1, lb);
        reverse(lb.begin(),lb.end());
        f(h, w-x1-1, h-1-y2, x2-x1-1, h-1, x1+1, -1, 1, rb);
        append(lb, rb);

        if (sz(lt) < sz(lb)) res = lb;
        else res = lt;
    }

    if (fy) {
        for (auto &p : res) p.y = h-1-p.y;
        y1 = h-1-y1;
        y2 = h-1-y2;
    }
    if (fx) {
        for (auto &p : res) p.x = w-1-p.x;
        x1 = w-1-x1;
        x2 = w-1-x2;
    }
    if (sxy) {
        swap(h,w);
        swap(x1,y1);
        swap(x2,y2);
        for (auto &p : res) swap(p.x, p.y);
    }

    printf("%d\n", sz(res));
    for (auto p : res) printf("%d %d\n", p.y+1, p.x+1);
}