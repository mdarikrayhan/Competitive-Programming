// LUOGU_RID: 160110754
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod (int)(1e9+7)
int n, m;
int a[100005];
struct point{
    int s[2];
}f[400005];
int tag[400005][3];
struct matrix{
    int a[2][2];
};
matrix operator*(matrix x, matrix y){
    matrix ans;
    memset(ans.a, 0ll, sizeof(ans.a));
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                ans.a[i][k] += x.a[i][j] * y.a[j][k] % mod;
                ans.a[i][k] %= mod;
            }
        }
    }
    return ans;
}
matrix ksm(matrix x, int y){
    matrix ans;
    ans.a[0][0] = 1;
    ans.a[0][1] = 0;
    ans.a[1][0] = 0;
    ans.a[1][1] = 1;
    while(y){
        if(y & 1)ans = ans * x;
        x = x * x;
        y >>= 1;
    }
    return ans;
}
int get(int x){
    if(x == 0)return 0;
    matrix base;
    base.a[0][0] = 1;
    base.a[0][1] = 1;
    base.a[1][0] = 1;
    base.a[1][1] = 0;
    base = ksm(base, x - 1);
    return base.a[0][0];
}
void up(int now){
    f[now].s[0] = f[now * 2].s[0] + f[now * 2 + 1].s[0];
    f[now].s[1] = f[now * 2].s[1] + f[now * 2 + 1].s[1];
    f[now].s[0] %= mod;
    f[now].s[1] %= mod;
}
void down(int now){
    int x = tag[now][0] * tag[now * 2][0] + tag[now][1] * tag[now * 2][1];
    int y = tag[now][1] * tag[now * 2][0] + tag[now][2] * tag[now * 2][1];
    int z = tag[now][1] * tag[now * 2][1] + tag[now][2] * tag[now * 2][2];
    x %= mod;
    y %= mod;
    z %= mod;
    tag[now * 2][0] = x;
    tag[now * 2][1] = y;
    tag[now * 2][2] = z;
    x = tag[now][0] * tag[now * 2 + 1][0] + tag[now][1] * tag[now * 2 + 1][1];
    y = tag[now][1] * tag[now * 2 + 1][0] + tag[now][2] * tag[now * 2 + 1][1];
    z = tag[now][1] * tag[now * 2 + 1][1] + tag[now][2] * tag[now * 2 + 1][2];
    x %= mod;
    y %= mod;
    z %= mod;
    tag[now * 2 + 1][0] = x;
    tag[now * 2 + 1][1] = y;
    tag[now * 2 + 1][2] = z;
    x = tag[now][0] * f[now * 2].s[0] + tag[now][1] * f[now * 2].s[1];
    y = tag[now][1] * f[now * 2].s[0] + tag[now][2] * f[now * 2].s[1];
    x %= mod;
    y %= mod;
    f[now * 2].s[0] = x;
    f[now * 2].s[1] = y;
    x = tag[now][0] * f[now * 2 + 1].s[0] + tag[now][1] * f[now * 2 + 1].s[1];
    y = tag[now][1] * f[now * 2 + 1].s[0] + tag[now][2] * f[now * 2 + 1].s[1];
    x %= mod;
    y %= mod;
    f[now * 2 + 1].s[0] = x;
    f[now * 2 + 1].s[1] = y;
    tag[now][0] = 1;
    tag[now][1] = 0;
    tag[now][2] = 1;
}
void init(int now, int l, int r){
    tag[now][0] = 1;
    tag[now][1] = 0;
    tag[now][2] = 1;
    if(l == r){
        f[now].s[0] = get(a[l]);
        f[now].s[1] = get(a[l]+1);
        return;
    }
    int mid = l+r>>1;
    init(now * 2, l, mid);
    init(now * 2 + 1, mid + 1, r);
    up(now);
}
void change(int now, int l, int r, int x, int y, int A, int B, int C){
    if(x <= l && r <= y){
        // cout << l << " " << r << " " << x << " " << y << " " << A << " " << B << " " << C << endl;
        // cout << tag[now][0] << " " << tag[now][1] << " " << tag[now][2] << endl;
        // cout << f[now].s[0] << " " << f[now].s[1] << endl;
        int u, v, w;
        u = A * tag[now][0] + B * tag[now][1];
        v = B * tag[now][0] + C * tag[now][1];
        // if(A * tag[now][1] + B * tag[now][2] != v)cout << "error!" << endl;
        w = B * tag[now][1] + C * tag[now][2];
        u %= mod;
        v %= mod;
        w %= mod;
        tag[now][0] = u;
        tag[now][1] = v;
        tag[now][2] = w;
        u = A * f[now].s[0] + B * f[now].s[1];
        v = B * f[now].s[0] + C * f[now].s[1];
        u %= mod;
        v %= mod;
        f[now].s[0] = u;
        f[now].s[1] = v;
        // cout << tag[now][0] << " " << tag[now][1] << " " << tag[now][2] << endl;
        // cout << f[now].s[0] << " " << f[now].s[1] << endl;
        // cout << endl;
        return;
    }
    down(now);
    int mid = l+r>>1;
    if(x <= mid)change(now * 2, l, mid, x, y, A, B, C);
    if(y > mid)change(now * 2 + 1, mid + 1, r, x, y, A, B, C);
    up(now);
    return;
}
int query(int now, int l, int r, int x, int y){
    if(x <= l && r <= y){
        return f[now].s[0];
    }
    down(now);
    int mid = l+r>>1;
    int ans = 0;
    if(x <= mid)ans += query(now * 2, l, mid, x, y);
    if(y > mid)ans += query(now * 2 + 1, mid + 1, r, x, y);
    ans %= mod;
    return ans;
}
signed main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
    }
    init(1, 1, n);
    for(int i = 1; i <= m; i++){
        int op, l, r, k;
        scanf("%lld%lld%lld", &op, &l, &r);
        if(op == 1){
            scanf("%lld", &k);
            int x = get(k - 1);
            int y = get(k);
            int z = get(k + 1);
            change(1, 1, n, l, r, x, y, z);
        }else{
            printf("%lld\n", query(1, 1, n, l, r));
        }
        // for(int j = 1; j <= n; j++)cout << query(1, 1, n, j, j) << " ";
        // cout << endl;
    }
    return 0;
}