#include <bits/stdc++.h>
using i64 = long long;
constexpr int mod = 998244353;
constexpr i64 MOD = 1e9 + 7;
constexpr int inf = 0x3f3f3f3f;
constexpr i64 INF = 0x3f3f3f3f3f3f3f3f;

template <class Info>
struct SegmentTree
{
    int n;
    std::vector<Info> info;
    SegmentTree() : n(0) {}
    SegmentTree(int n_, Info v_ = Info())
    {
        init(n_, v_);
    }
    template <class T>
    SegmentTree(std::vector<T> init_)
    {
        init(init_);
    }
    void init(int n_, Info v_ = Info())
    {
        init(std::vector(n_, v_));
    }
    template <class T>
    void init(std::vector<T> init_)
    {
        n = init_.size();
        info.assign(4 << std::__lg(n), Info());
        std::function<void(int, int, int)> build = [&](int p, int l, int r)
        {
            if(r - l == 1)
            {
                info[p] = init_[l];
                return;
            }
            int m =(l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            pull(p);
        };
        build(1, 0, n);
    }
    void pull(int p)
    {
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    void modify(int p, int l, int r, int x, const Info &v)
    {
        if(r - l == 1)
        {
            info[p] = v;
            return;
        }
        int m =(l + r) / 2;
        if(x < m)
        {
            modify(2 * p, l, m, x, v);
        }
        else
        {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
    void modify(int p, const Info &v)
    {
        modify(1, 0, n, p, v);
    }
    Info rangeQuery(int p, int l, int r, int x, int y)
    {
        if(l >= y || r <= x)
        {
            return {std::numeric_limits<int>::max()};
        }
        if(l >= x && r <= y)
        {
            return info[p];
        }
        int m =(l + r) / 2;
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }
    Info rangeQuery(int l, int r)
    {
        return rangeQuery(1, 0, n, l, r);
    }
};

struct Info
{
    int info = 0;
};

Info operator +(const Info &a, const Info &b)
{
    return {std::min(a.info, b.info)};
}

void solve()
{
    int n, m, k, q;
    std::cin >> n >> m >> k >> q;
    int siz = std::max(n, m);
    std::map<int, std::vector<std::array<int, 4>>> mpx, mpy;
    for(int i = 1; i <= k; i++)
    {
        int x, y;
        std::cin >> x >> y;
        mpx[x].push_back({x, y, 0, 0});
        mpy[y].push_back({y, x, 0, 0});
    }
    std::map<std::array<int, 4>, bool> ans;
    std::vector<std::array<int, 4>> v;
    for(int i = 1; i <= q; i++)
    {
        int x1, x2, y1, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        v.push_back({x1, y1, x2, y2});
        mpx[x2].push_back({x2, y1, y2, x1});
        mpy[y2].push_back({y2, x1, x2, y1});
    }
    SegmentTree<Info> seg(siz);
    for(auto &[i, j] : mpx)
    {
        for(auto &[x2, y1, y2, x1] : j)
        {
            if(!y2) seg.modify(y1 - 1, {x2});
            else
            {
                int p = seg.rangeQuery(y1 - 1, y2).info;
                if(p >= x1) ans[{x1, y1, x2, y2}] = true;
            }
        }
    }
    seg.init(siz);
    for(auto &[i, j] : mpy)
    {
        for(auto &[y2, x1, x2, y1] : j)
        {
            if(!x2) seg.modify(x1 - 1, {y2});
            else
            {
                int p = seg.rangeQuery(x1 - 1, x2).info;
                if(p >= y1) ans[{x1, y1, x2, y2}] = true;
            }
        }
    }
    for(auto i : v) std::cout <<(ans[i] ? "YES" : "NO") << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}