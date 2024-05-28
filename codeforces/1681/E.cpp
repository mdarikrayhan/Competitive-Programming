//code by MINO1
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;

ll dp1[400005][2];
ll dp2[400005][2];
int xy[100005][4];

void init(int p,int s,int t) {
    if (s == t) {
        dp1[p][0] = dp2[p][1] = 0;
        dp1[p][1] = dp2[p][0] = abs(xy[s][0] - xy[s][2]) + abs(xy[s][1] - xy[s][3]);
        return;
    }
    int m = (s + t) >> 1;
    init(p * 2,s,m);
    init(p * 2 + 1,m + 1,t);
    dp1[p][0] = min(min(dp1[p * 2][0] + 1 + abs(xy[m][0] + 1 - xy[m + 1][0]) + abs(xy[m][1] - xy[m + 1][1]) + dp1[p * 2 + 1][0],dp1[p * 2][0] + 1 + abs(xy[m][0] + 1 - xy[m + 1][2]) + abs(xy[m][1] - xy[m + 1][3]) + dp2[p * 2 + 1][0]),
                    min(dp1[p * 2][1] + 1 + abs(xy[m][2] - xy[m + 1][0]) + abs(xy[m][3] + 1 - xy[m + 1][1]) + dp1[p * 2 + 1][0],dp1[p * 2][1] + 1 + abs(xy[m][2] - xy[m + 1][2]) + abs(xy[m][3] + 1 - xy[m + 1][3]) + dp2[p * 2 + 1][0]));
    dp1[p][1] = min(min(dp1[p * 2][0] + 1 + abs(xy[m][0] + 1 - xy[m + 1][0]) + abs(xy[m][1] - xy[m + 1][1]) + dp1[p * 2 + 1][1],dp1[p * 2][0] + 1 + abs(xy[m][0] + 1 - xy[m + 1][2]) + abs(xy[m][1] - xy[m + 1][3]) + dp2[p * 2 + 1][1]),
                    min(dp1[p * 2][1] + 1 + abs(xy[m][2] - xy[m + 1][0]) + abs(xy[m][3] + 1 - xy[m + 1][1]) + dp1[p * 2 + 1][1],dp1[p * 2][1] + 1 + abs(xy[m][2] - xy[m + 1][2]) + abs(xy[m][3] + 1 - xy[m + 1][3]) + dp2[p * 2 + 1][1]));
    dp2[p][0] = min(min(dp2[p * 2][0] + 1 + abs(xy[m][0] + 1 - xy[m + 1][0]) + abs(xy[m][1] - xy[m + 1][1]) + dp1[p * 2 + 1][0],dp2[p * 2][0] + 1 + abs(xy[m][0] + 1 - xy[m + 1][2]) + abs(xy[m][1] - xy[m + 1][3]) + dp2[p * 2 + 1][0]),
                    min(dp2[p * 2][1] + 1 + abs(xy[m][2] - xy[m + 1][0]) + abs(xy[m][3] + 1 - xy[m + 1][1]) + dp1[p * 2 + 1][0],dp2[p * 2][1] + 1 + abs(xy[m][2] - xy[m + 1][2]) + abs(xy[m][3] + 1 - xy[m + 1][3]) + dp2[p * 2 + 1][0]));
    dp2[p][1] = min(min(dp2[p * 2][0] + 1 + abs(xy[m][0] + 1 - xy[m + 1][0]) + abs(xy[m][1] - xy[m + 1][1]) + dp1[p * 2 + 1][1],dp2[p * 2][0] + 1 + abs(xy[m][0] + 1 - xy[m + 1][2]) + abs(xy[m][1] - xy[m + 1][3]) + dp2[p * 2 + 1][1]),
                    min(dp2[p * 2][1] + 1 + abs(xy[m][2] - xy[m + 1][0]) + abs(xy[m][3] + 1 - xy[m + 1][1]) + dp1[p * 2 + 1][1],dp2[p * 2][1] + 1 + abs(xy[m][2] - xy[m + 1][2]) + abs(xy[m][3] + 1 - xy[m + 1][3]) + dp2[p * 2 + 1][1]));
}

struct node{
    ll aa;
    ll ab;
    ll ba;
    ll bb;
};

node query(int p,int l,int r,int s,int t) {
    if (l <= s && r >= t) {
        return {dp1[p][0],dp1[p][1],dp2[p][0],dp2[p][1]};
    }
    int m = (s + t) >> 1;
    node ll,rr;bool flag1 = 0,flag2 = 0;
    if (l <= m) {
        flag1 = 1;
        ll = query(p * 2,l,r,s,m);
    }
    if (r > m) {
        flag2 = 1;
        rr = query(p * 2 + 1,l,r,m + 1,t);
    }
    if (flag1 && flag2) {
        node rt;
        rt.aa = min(min(ll.aa + 1 + abs(xy[m][0] + 1 - xy[m + 1][0]) + abs(xy[m][1] - xy[m + 1][1]) + rr.aa,ll.aa + 1 + abs(xy[m][0] + 1 - xy[m + 1][2]) + abs(xy[m][1] - xy[m + 1][3]) + rr.ba),
                    min(ll.ab + 1 + abs(xy[m][2] - xy[m + 1][0]) + abs(xy[m][3] + 1 - xy[m + 1][1]) + rr.aa,ll.ab + 1 + abs(xy[m][2] - xy[m + 1][2]) + abs(xy[m][3] + 1 - xy[m + 1][3]) + rr.ba));
        rt.ab = min(min(ll.aa + 1 + abs(xy[m][0] + 1 - xy[m + 1][0]) + abs(xy[m][1] - xy[m + 1][1]) + rr.ab,ll.aa + 1 + abs(xy[m][0] + 1 - xy[m + 1][2]) + abs(xy[m][1] - xy[m + 1][3]) + rr.bb),
                    min(ll.ab + 1 + abs(xy[m][2] - xy[m + 1][0]) + abs(xy[m][3] + 1 - xy[m + 1][1]) + rr.ab,ll.ab + 1 + abs(xy[m][2] - xy[m + 1][2]) + abs(xy[m][3] + 1 - xy[m + 1][3]) + rr.bb));
        rt.ba = min(min(ll.ba + 1 + abs(xy[m][0] + 1 - xy[m + 1][0]) + abs(xy[m][1] - xy[m + 1][1]) + rr.aa,ll.ba + 1 + abs(xy[m][0] + 1 - xy[m + 1][2]) + abs(xy[m][1] - xy[m + 1][3]) + rr.ba),
                    min(ll.bb + 1 + abs(xy[m][2] - xy[m + 1][0]) + abs(xy[m][3] + 1 - xy[m + 1][1]) + rr.aa,ll.bb + 1 + abs(xy[m][2] - xy[m + 1][2]) + abs(xy[m][3] + 1 - xy[m + 1][3]) + rr.ba));
        rt.bb = min(min(ll.ba + 1 + abs(xy[m][0] + 1 - xy[m + 1][0]) + abs(xy[m][1] - xy[m + 1][1]) + rr.ab,ll.ba + 1 + abs(xy[m][0] + 1 - xy[m + 1][2]) + abs(xy[m][1] - xy[m + 1][3]) + rr.bb),
                    min(ll.bb + 1 + abs(xy[m][2] - xy[m + 1][0]) + abs(xy[m][3] + 1 - xy[m + 1][1]) + rr.ab,ll.bb + 1 + abs(xy[m][2] - xy[m + 1][2]) + abs(xy[m][3] + 1 - xy[m + 1][3]) + rr.bb));
        return rt;
    }
    else if (flag1) return ll;
    else return rr;
}

void solve() {
    cin >> n;
    for (int i = 1;i < n;i++) {
        cin >> xy[i][0] >> xy[i][1] >> xy[i][2] >> xy[i][3];
    }
    init(1,1,n - 1);
    int m;cin >> m;
    while (m--) {
        int x1,y1,x2,y2;cin >> x1 >> y1 >> x2 >> y2;
        int l = max(x1,y1);
        int r = max(x2,y2);
        if (l > r) {
            swap(l,r);swap(x1,x2);swap(y1,y2);
        }
        else if (l == r) {
            cout << abs(x1 - x2) + abs(y1 - y2) << endl;
            continue;
        }
        node ner = query(1,l,r - 1,1,n - 1);
        cout << min(abs(x1 - xy[l][0]) + abs(y1 - xy[l][1]) + min(ner.aa + 1 + abs(xy[r - 1][0] + 1 - x2) + abs(xy[r - 1][1] - y2),ner.ab + 1 + abs(xy[r - 1][2] - x2) + abs(xy[r - 1][3] + 1 - y2)),
                    abs(x1 - xy[l][2]) + abs(y1 - xy[l][3]) + min(ner.ba + 1 + abs(xy[r - 1][0] + 1 - x2) + abs(xy[r - 1][1] - y2),ner.bb + 1 + abs(xy[r - 1][2] - x2) + abs(xy[r - 1][3] + 1 - y2))) << endl;
    }
} 

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
}