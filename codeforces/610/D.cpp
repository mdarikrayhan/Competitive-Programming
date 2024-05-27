#include <bits/stdc++.h> 
 
using namespace std;
 
#define threesum cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false)
#define all(a) a.begin(), a.end()
#define F first
#define S second
#define int long long
#define pii pair<int, int>
#define ppp pair<int, pii>
#define dout cout << fixed << setprecision(15)

const int maxn = 1e6 + 10, oo = 8e18 + 10, mod = 1e9 + 7, lg = 31, sq = 700;

int n, fen[maxn], ans, c, l = -oo;

vector<int> x, y;
vector<ppp> v, h;

map<int, vector<pii>> q;
map<int, vector<int>> s, f;
map<int, int> mp;

void add(int i, int val){
    for (; i <= c; i += i & -i)
        fen[i] += val;
}
 
int get(int i){
    int res = 0;
    for (; i > 0; i -= i & -i)
        res += fen[i];
    return res;
}


signed main()
{
    threesum;
    cin >> n;
    for (int i = 1; i <= n;i++){
        int a1, b1, a2, b2;
        cin >> a1 >> b1 >> a2 >> b2;
        if(a1 > a2)
            swap(a1, a2);
        if(b1 > b2)
            swap(b1, b2);
        if (a1 == a2)
        {
            v.push_back({a1, {b1, b2}});
            x.push_back(a1);
            y.push_back(b1);
            y.push_back(b2);
        }
        else{
            h.push_back({b1, {a1, a2}});
            y.push_back(b1);
            x.push_back(a1);
            x.push_back(a2);
        }
    }

    sort(all(x));
    sort(all(y));
    sort(all(v));
    sort(all(h));

    for (int i = 0; i < v.size();i++){
        int j = i;
        while (j + 1 < v.size() && v[j + 1].F == v[i].F)
            j++;

        pii seg = v[i].S;
        for (int k = i + 1; k <= j;k++){
            if(seg.S < v[k].S.F){
                s[seg.F].push_back(v[i].F);
                f[seg.S].push_back(v[i].F);
                ans += seg.S - seg.F + 1;
                seg = v[k].S;
            }
            else if(seg.S < v[k].S.S)
                seg.S = v[k].S.S;
        }
        s[seg.F].push_back(v[i].F);
        f[seg.S].push_back(v[i].F);
        ans += seg.S - seg.F + 1;
        i = j;
    }

    for (int i = 0; i < h.size();i++){
        int j = i;
        while (j + 1 < h.size() && h[j + 1].F == h[i].F)
            j++;

        pii seg = h[i].S;
        for (int k = i + 1; k <= j;k++){
            if(seg.S < h[k].S.F){
                q[h[i].F].push_back(seg);
                ans += seg.S - seg.F + 1;
                seg = h[k].S;
            }
            else if(seg.S < h[k].S.S)
                seg.S = h[k].S.S;
        }
        q[h[i].F].push_back(seg);
        ans += seg.S - seg.F + 1;
        i = j;
    }

    for (int i = 0; i < x.size();i++)
        if (!i || x[i] > x[i - 1])
            mp[x[i]] = ++c;

    for (auto i : y){
        if (i == l)
            continue;

        for(auto j : s[i])
            add(mp[j], 1);
        
        for(auto [a, b]:q[i])
            ans -= get(mp[b]) - get(mp[a] - 1);

        for(auto j : f[i])
            add(mp[j], -1);

        l = i;
    }

    cout << ans << "\n";
}