#include <bits/stdc++.h>
#define ll long long
#define double long double
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;

const double eps = 1e-8;
pdd operator-(pdd p, pdd q)
{
    return pdd(p.F - q.F, p.S - q.S);
}
double cross(pdd a, pdd b)
{
    return a.F * b.S - a.S * b.F;
}
int ori(pdd a, pdd b, pdd c)
{
    double d = cross(b - a, c - a);
    return (abs(d) <= eps ? 0 : (d < 0 ? -1 : 1));
}
double dot(pdd a, pdd b)
{
    return a.F * b.F + a.S * b.S;
}
double abs2(pdd a)
{
    return dot(a, a);
}
void hull(vector<pdd> &dots)
{
    sort(all(dots));
    vector<pdd> ans(1, dots[0]);
    for (int ct = 0; ct < 2; ++ct, reverse(all(dots)))
        for (int i = 1, t = ans.size(); i < dots.size(); ans.emplace_back(dots[i++]))
            while(ans.size() > t && ori(ans.end()[-2], ans.back(), dots[i]) <= 0)
                ans.pop_back();
    ans.pop_back(), ans.swap(dots);
}
pdd excenter(pdd p0, pdd p1, pdd p2)
{
    p1 = p1 - p0, p2 = p2 - p0;
    auto [x1, y1] = p1;
    auto [x2, y2] = p2;
    double m = 2. * cross(p1, p2);
    pdd center = pdd((x1 * x1 * y2 - x2 * x2 * y1 + y1 * y2 * (y1 - y2)) / m,
                     (x1 * x2 * (x2 - x1) - y1 * y1 * x2 + x1 * y2 * y2) / m);
    return center;
}

#define entry pair<double, array<int, 3>>

int N, out[100005];
double R;
vector<pdd> p;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N >> R;
    p.resize(N);
    for (auto &[x, y] : p)
        cin >> x >> y;

    hull(p), N = p.size();

    set<int> st;
    priority_queue<entry> pq;
    for (int i = 0; i < N; i++) 
        st.insert(i);
    auto safeprev = [&](auto iter)
    {
        return iter == st.begin() ? prev(st.end()) : prev(iter);
    };
    auto safenext = [&](auto iter)
    {
        return next(iter) == st.end() ? st.begin() : next(iter);
    };
    auto insert = [&](int i)
    {
        if (st.size() <= 2) return;
        auto iter = st.find(i);
        int j = *safeprev(iter), k = *safenext(iter);
        if (abs2(p[j] - p[k]) >= abs2(p[i] - p[j]) + abs2(p[k] - p[i]))
            pq.push(make_pair(abs2(excenter(p[j], p[i], p[k])), array{j, i, k}));
    };
    for (int i = 0; i < N; i++) 
        insert(i);
    while (!pq.empty())
    {
        auto [r, arr] = pq.top();
        pq.pop();
        auto [a, b, c] = arr;
        if (r < R * R + eps) break;
        if (out[a] || out[b] || out[c]) continue;
        out[b] = 1;
        st.erase(b);
        insert(a), insert(c);
    }

    vector<pdd> r;
    for (auto i : st)
        r.emplace_back(p[i]);
    
    double ans = 0;
    N = r.size();
    for (int i = 0; i < N; i++)
    {
        int j = (i + 1) % N;
        ans += cross(r[i], r[j]) * .5;
        double d = sqrtl(abs2(r[i] - r[j]));
        double th = asinl(d / R * .5);
        ans += R * R * th - .5 * d * sqrtl(R * R - .25 * d * d);
    }
    cout << fixed << setprecision(10) << ans << '\n';
}
