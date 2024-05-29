#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 1e6 + 1;
const ll M = 1e9 + 7;

ll h, n, q, k;
ll a[N], c[N], mi[N];
vector<ll> ks;
set<pair<ll, ll>> avail;

void doTest(ll testID) {
    cin >> h >> n >> q >> k;
    for (int i = 1; i <= n; i ++) cin >> a[i] >> c[i], a[i] --;
    
    auto update = [&]() -> void {
        for (int i = 0; i < k; i ++) mi[i] = 1e18;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        pq.push({mi[0] = 0, 0});
        while (!pq.empty()) {
            auto [w, u] = pq.top(); pq.pop();
            if (mi[u] != w) continue;
            for (auto x: ks) {
                ll v = (w + x) % k;
                if (mi[v] <= w + x) continue;
                pq.push({mi[v] = w + x, v}); 
            }
        }

        avail.clear();
        for (int i = 1; i <= n; i ++)
            if (a[i] != -1 && mi[a[i] % k] <= a[i])
                avail.insert({c[i], -i});
    };

    update();
    for (int _ = 1; _ <= q; _ ++) {
        ll type; cin >> type;
        if (type == 1) {
            ll x; cin >> x;
            ks.push_back(x);
            update();
        }
        if (type == 2) {
            ll x, y; cin >> x >> y;
            bool inAvail = avail.count({c[x], -x});
            if (inAvail) avail.erase({c[x], -x});
            c[x] -= y;
            if (inAvail) avail.insert({c[x], -x});
        }
        if (type == 3) {
            if (avail.empty()) {cout << "0\n"; continue;}
            ll pos = -(*avail.rbegin()).second;
            cout << c[pos] << '\n';
            avail.erase({c[pos], -pos});
            a[pos] = -1;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int test = 1; 
    // cin >> test;
    for (int _ = 1; _ <= test; _ ++) doTest(test);
}

/*
    Tóm tắt bài toán: 
        + Cho h ô, n ô a[i] có kho báu, kho báo ở ô a[i] có giá trị là c[i]
        + Bắt đầu ở ô 1, có thể di chuyển tiến lên k ô hoặc quay về ô 1
        + Cho ba truy vấn:
            * Truy vấn 1: (1 x) Thêm cách di chuyển tiến lên x ô
            * Truy vấn 2: (2 x y) c[x] -= y
            * Truy vấn 3: (3) In ra kho báu lớn nhất có thể lấy, xóa kho báu đó đi        

    Lời giải:
        + NX1: Chia các ô ra thành k nhóm: {nhóm chia k dư 0, nhóm chia k dư 1, ...}
            -> Các ô trong nhóm đi được tới nhau 
        + NX2: Khi thêm một số x vào các kiểu di chuyển thì
            -> Dùng Dijsktra để tính giá trị nhỏ nhất có thể di chuyển tới các nhóm, đặt là mi[i]
            -> Nếu một ô trong nhóm i mà a[i] <= mi[i] nghĩa là có thể tới ô a[i] từ các cách di chuyển
            VD: k = 7, a[i] = 10, k1 = 6, k2 = 2, tính được mi[a[i] % k] = mi[3] = 10 => tới được ô a[i]
            VD: k = 7, a[i] = 3, k1 = 6, k2 = 2, tính được mi[a[i] % k] = mi[3] = 10 => ko tới được ô a[i]
*/