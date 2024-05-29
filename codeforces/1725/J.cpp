#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 1e6 + 1;
const ll M = 1e9 + 7;

ll n, sum = 0, res;
vector<pair<ll, ll>> a[N];
ll d[N], dd[N];

void doTest(ll testID) {
    cin >> n;
    for (int i = 1; i < n; i ++) {
        ll u, v, w; cin >> u >> v >> w;
        a[u].push_back({v, w});
        a[v].push_back({u, w});
        sum += w;
    }

    auto get = [&](vector<pair<ll, ll>> &v, ll par, ll cnt) -> ll {
        ll res = 0;
        for (auto [val, x]: v) {
            if (cnt == 0) break;
            if (x == par) continue;
            res += val; cnt --;
        } return res;
    };

    auto preDpOnTree = [&](ll node, ll par, auto&& preDpOnTree) -> void {
        vector<pair<ll, ll>> v;
        for (auto [x, w]: a[node]) {
            if (x == par) continue;
            preDpOnTree(x, node, preDpOnTree);
            dd[node] = max(dd[node], dd[x]);
            v.push_back({d[x] + w, x});
        }
        sort(v.rbegin(), v.rend());
        d[node] = get(v, 0, 1); dd[node] = max(dd[node], get(v, 0, 2));
    };

    auto dpOnTree = [&](ll node, ll par, auto&& dpOnTree) -> void {
        vector<pair<ll, ll>> v;
        for (auto [x, w]: a[node]) v.push_back({d[x] + w, x});
        sort(v.rbegin(), v.rend());

        vector<pair<ll, ll>> vv;
        for (auto [x, w]: a[node]) vv.push_back({dd[x], x});
        sort(vv.rbegin(), vv.rend());

        ll case1 = get(v, 0, 4);
        res = max(res, case1);

        ll case2 = 0;
        for (auto [x, w]: a[node]) {
            if (x == par) continue;
            ll ddOfNodeExceptX = max(get(vv, x, 1), get(v, x, 2));
            case2 = max(case2, ddOfNodeExceptX + dd[x] + 2 * w);
        }
        res = max(res, case2);

        for (auto [x, w]: a[node]) {
            if (x == par) continue;
            ll ddOfNodeExceptX = max(get(vv, x, 1), get(v, x, 2));
            ll dOfNodeExceptX = get(v, x, 1);

            ll oldD = d[node], oldDD = dd[node];
            d[node] = dOfNodeExceptX, dd[node] = ddOfNodeExceptX;
            dpOnTree(x, node, dpOnTree);
            d[node] = oldD, dd[node] = oldDD;
        }
    };

    preDpOnTree(1, 0, preDpOnTree);
    dpOnTree(1, 0, dpOnTree);

    cout << 2 * sum - res;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int test = 1; 
    // cin >> test;
    for (int _ = 1; _ <= test; _ ++) doTest(test);
}

/*
    Tóm tắt đề: Cho 1 cây n nút. 
        + Tính tổng đường đi ngắn nhất để đi qua tất cả các nút ít nhất một lần.
        + Có một lần teleport đến một nút bất kỳ

    Lời giải: 
        + Biến đổi + phân tích bài toán:
            -> Tổng tất cả đường đi - 2 đường đi không trùng nhau
            -> Tổng tất cả đường đi - 2 đường đi không trùng nhau - 2 * đoạn đường nằm giữa 2 đường đi * [2 đường đi không có nút chung]
        + Dp trên cây: Tại một nút, có thể trừ đi:
            -> TH1: Hoặc là 4 đường đi riêng lẻ lớn nhất của nút đó trên cây
            -> TH2: Hoặc là chọn thêm 1 cạnh có chứa nút đó, khi đó đồ thị chia thành 2 nửa
                * Lấy 1 đường đi dài nhất ở nửa thứ nhất
                * Lấy 1 đường đi dài nhất ở nửa thứ hai
                * Vậy đường nối của 2 nữa là cạnh đang xét
*/