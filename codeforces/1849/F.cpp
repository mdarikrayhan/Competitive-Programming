#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
//#define int ll
#define all(x) x.begin(), x.end()
#define pb push_back
#define pii pair<int, int>
#define F first
#define S second

#define watch(x) cout << (#x) << ':' << (x) << '\n';

template<typename T> // print vector
ostream& operator<<(ostream& os, const vector<T>& v){
    for (int i = 0; i < v.size(); i++) os << v[i] << ' ';
    return os;
}

const int maxn = 2e5+5;
int v[maxn], id[maxn], p[maxn], w[maxn], l[maxn], r[maxn];

pii rfind(int x){
    if (p[x] < 0) return {x, 0};
    else{
        pii y = rfind(p[x]);
        p[x] = y.F;
        w[x] ^= y.S;
        return {p[x], w[x]};
    }
}

bool merge(int rx, int ry){
    int x = rfind(rx).F;
    int y = rfind(ry).F;
    if (x == y) return w[rx] != w[ry];
    if (-p[x] < -p[y]) swap(x, y);
    w[y] = w[rx]^w[ry]^1;
    p[x] += p[y];
    p[y] = x;
    return 1;
}

#define piii pair<int, pair<int, int>> //evil

void orz()
{
    int n; cin >> n;
    vector<pii> raw(n);
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        raw[i] = {x, i};
    }

    sort(all(raw));

    for (int i = 0; i < n; i++)
    {
        v[i] = raw[i].F;
        id[i] = raw[i].S;
    }
    
    priority_queue<piii, vector<piii>, greater<piii>> pq;
    for (int i = 0; i < n-1; i++)
        pq.push({v[i]^v[i+1], {i, i+1}});

    for (int i = 0; i < n; i++)
    {
        l[i] = i-1;
        r[i] = i+1;
        p[i] = -1;
    }

    while (!pq.empty())
    {
        auto t = pq.top();
        pq.pop();
        int x = t.S.F, y = t.S.S;
        if (!merge(x, y)) break;
        if (--l[x] >= 0){
            r[l[x]] = x;
            pq.push({v[x]^v[l[x]], {x, l[x]}});
        }
        if (++r[x] <= n-1){
            l[r[x]] = x;
            pq.push({v[x]^v[r[x]], {x, r[x]}});
        }
        if (--l[y] >= 0){
            r[l[y]] = y;
            pq.push({v[y]^v[l[y]], {y, l[y]}});
        }
        if (++r[y] <= n-1){
            l[r[y]] = y;
            pq.push({v[y]^v[r[y]], {y, r[y]}});
        } 
    }

    vector<int> ans(n);
    for (int i = 0; i < n; i++){
        rfind(i);
        ans[id[i]] = w[i];
    }
    for (int i = 0; i < n; i++)
        cout << ans[i];
    cout << '\n';
}

int32_t main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin.exceptions(cin.failbit);

    orz();

    return 0;
}
