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

int n, m, p[maxn];

vector<int> v[maxn], seg[maxn << 2];

void merge(int id){
    int a = 0, b = 0;
    while (a < seg[2 * id].size() && b < seg[2 * id + 1].size()){
        if (seg[2 * id][a] > seg[2 * id + 1][b]){
            seg[id].push_back(seg[2 * id + 1][b]);
            b++;
        }
        else{
            seg[id].push_back(seg[2 * id][a]);
            a++;
        }
    }
    for (; a < seg[2 * id].size();a++)
        seg[id].push_back(seg[2 * id][a]);
    for (; b < seg[2 * id + 1].size();b++)
        seg[id].push_back(seg[2 * id + 1][b]);
}

void build(int id = 1, int l = 0, int r = maxn){
    if(r - l == 1){
        seg[id] = v[l];
        sort(all(seg[id]));
        return;
    }

    int mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid, r);
    merge(id);
}

int get(int ql, int qr, int id = 1, int l = 0, int r = maxn){
    if(r <= ql || qr <= l)
        return 0;
    if(ql <= l && r <= qr)
        return lower_bound(all(seg[id]), qr) - seg[id].begin();
    
    int mid = (l + r) / 2;
    return get(ql, qr, 2 * id, l, mid) + get(ql, qr, 2 * id + 1, mid, r);
}

signed main()
{
    threesum;
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        int l, r;
        cin >> l >> r;
        v[l].push_back(r);
    }

    build();

    while(m--){
        int cnt, ans = 0;
        cin >> cnt;
        for (int i = 1; i <= cnt;i++)
            cin >> p[i];
        p[cnt + 1] = maxn;

        for (int i = 0; i <= cnt;i++)
            ans += get(p[i] + 1, p[i + 1]);

        cout << n - ans << "\n";
    }
}