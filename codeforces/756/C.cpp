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

const int maxn = 1e5 + 10, oo = 8e18 + 10, mod = 1e9 + 7, lg = 31, sq = 700;

int n, seg[maxn << 2], lazy[maxn << 2], a[maxn];

void relax(int id){
    seg[2 * id] += lazy[id];
    lazy[2 * id] += lazy[id];
    seg[2 * id + 1] += lazy[id];
    lazy[2 * id + 1] += lazy[id];
    lazy[id] = 0;
}

void upd(int ql, int qr, int val, int id = 1, int l = 0, int r = maxn){
    if(r <= ql || qr <= l)
        return;
    if(ql <= l && r <= qr){
        seg[id] += val;
        lazy[id] += val;
        return;
    }

    relax(id);
    int mid = (l + r) / 2;
    upd(ql, qr, val, 2 * id, l, mid);
    upd(ql, qr, val, 2 * id + 1, mid, r);
    seg[id] = max(seg[2 * id], seg[2 * id + 1]);
}

int get(int id = 1, int l = 0, int r = maxn){
    if (r - l == 1){
        if (seg[id] <= 0)
            return -1;
        return l;
    }

    relax(id);
    int mid = (l + r) / 2;
    if (0 < seg[2 * id + 1])
        return get(2 * id + 1, mid, r);
    return get(2 * id, l, mid);
}

signed main()
{
    threesum;
    cin >> n;
    for (int i = 1; i <= n;i++){
        int p, t;
        cin >> p >> t;
        if (!t)
            upd(0, p + 1, -1);
        else{
            cin >> a[p];
            upd(0, p + 1, 1);
        }

        int ind = get();
        cout << (ind > 0 ? a[ind] : ind) << "\n";
    }
}