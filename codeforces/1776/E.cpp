// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
#define int long long
// #define debug
void cmin(int &A, int B) { A = std::min(A, B); }
const long long lcm = 2520;
int n, m;
long long s, v;
std::vector<std::pair<long long, long long>> e[11];
struct seg
{
    long long sx, sy, ex, ey, k;
    int val, tmp;
};
std::vector<seg> g, cur;
void add(long long sx, long long sy, long long ex, long long ey)
{
    if (sx > ex)
        return;
    assert((ex - sx) % (ey - sy) == 0);
    long long k = (ex - sx) / (ey - sy);
    for (int i = sy; ++i != ey;)
    {
        long long v = (i - sy) * k + sx;
        std::vector<std::pair<long long, long long>>::iterator iter =
            std::upper_bound(e[i].begin(), e[i].end(), v,
                             [&](const long long &A, const std::pair<long long, long long> &B)
                             { return A < B.second; });
        if (iter != e[i].end() && iter->first < v)
            return;
    }
    while (sy >= 1)
    {
        std::vector<std::pair<long long, long long>>::iterator iter =
            std::upper_bound(e[sy].begin(), e[sy].end(), sx,
                             [&](const long long &A, const std::pair<long long, long long> &B)
                             { return A < B.second; });
        if (iter != e[sy].end() && iter->first < sx)
            break;
        --sy;
        sx -= k;
    }
    while (ey <= m)
    {
        std::vector<std::pair<long long, long long>>::iterator iter =
            std::upper_bound(e[ey].begin(), e[ey].end(), ex,
                             [&](const long long &A, const std::pair<long long, long long> &B)
                             { return A < B.second; });
        if (iter != e[ey].end() && iter->first < ex)
            break;
        ++ey;
        ex += k;
    }
    g.push_back({sx, sy, ex, ey, k, sy == 0 && sx >= 0 ? 0 : INT_MAX / 2, INT_MAX / 2});
}
void solve(std::vector<seg>::iterator l, std::vector<seg>::iterator r)
{
    if (r - l <= 1)
        return;
    std::vector<seg>::iterator mid = l + (r - l) / 2;
    solve(l, mid);
    solve(mid, r);
    int min = INT_MAX / 2;
    for (std::vector<seg>::iterator i = l, j = mid; i != mid; ++i)
    {
        while (j != r && j->sx <= i->sx)
            cmin(min, j++->val);
        cmin(i->tmp, min + 1);
    }
    min = INT_MAX / 2;
    for (std::vector<seg>::iterator i = r, j = mid; i-- != mid;)
    {
        while (j != l && std::prev(j)->sx >= i->sx)
            cmin(min, (--j)->val);
        cmin(i->tmp, min + 1);
    }
    seg tmp[r - l];
    std::merge(l, mid, mid, r, tmp, [&](const seg &A, const seg &B)
               { return A.sx < B.sx; });
    std::copy(tmp, tmp + (r - l), l);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> s >> v;
    s -= (m + 1) * v;
    // std::cout << 0 << ' ' << 0 << std::endl;
    // std::cout << s << ' ' << m + 1 << std::endl;
    s *= lcm;
    for (int i = 1, a, b, r; i <= n; ++i)
    {
        std::cin >> a >> b >> r;
        a -= r * v;
        b -= r * v;
        // std::cout << a << ' ' << r << ' ' << b << ' ' << r << std::endl;
        e[r].push_back({a * lcm, b * lcm});
    }
    for (int i = 1; i <= m; ++i)
        std::sort(e[i].begin(), e[i].end());
    add(0, 0, 0, 1);
    add(s, m, s, m + 1);
    for (int i = 1; i <= m; ++i)
    {
        for (auto k : e[i])
        {
            add(k.first, i, k.first, i + 1);
            add(k.second, i, k.second, i + 1);
            for (int j = i + 1; j <= m; ++j)
            {
                for (auto l : e[j])
                {
                    add(k.first, i, l.first, j);
                    add(k.first, i, l.second, j);
                    add(k.second, i, l.first, j);
                    add(k.second, i, l.second, j);
                }
            }
        }
    }
    // for (auto i : g)
    //     std::cout << 1. * i.sx / lcm << ' ' << i.sy << ' ' << 1. * i.ex / lcm << ' ' << i.ey << std::endl;
    std::sort(g.begin(), g.end(), [&](const seg &A, const seg &B)
              { return A.sy > B.sy; });
    for (int i = 0; i <= m; ++i)
    {
        cur.erase(std::remove_if(cur.begin(), cur.end(), [&](const seg &X)
                                 { return X.sy == X.ey; }),
                  cur.end());
        while (!g.empty() && g.back().sy == i)
            cur.push_back(g.back()), g.pop_back();
        std::sort(cur.begin(), cur.end(), [&](const seg &A, const seg &B)
                  { return A.sx < B.sx; });
        for (auto &j : cur)
        {
            ++j.sy;
            j.sx += j.k;
        }
        // for (std::size_t j = 0; j != cur.size(); ++j)
        //     for (std::size_t k = 0; k != j; ++k)
        //         if (cur[k].sx >= cur[j].sx)
        //         {
        //             cmin(cur[k].val, cur[j].val + 1);
        //             if (cur[k].sx == cur[j].sx)
        //                 cmin(cur[j].val, cur[k].val + 1);
        //         }
        solve(cur.begin(), cur.end());
        for (auto &j : cur)
            cmin(j.val, j.tmp);
        // std::cout << i << std::endl;
        // for (auto &j : cur)
        //     std::cout << 1. * (j.sx - j.k) / lcm << ' ' << j.sy - 1 << ' ' << 1. * j.ex / lcm << ' ' << j.ey << ' ' << j.val << std::endl;
    }
    int ans = INT_MAX / 2;
    for (auto i : cur)
        if (i.ex <= s)
            cmin(ans, i.val);
    std::cout << (ans == INT_MAX / 2 ? -1 : ans) << std::endl;
    return 0;
}