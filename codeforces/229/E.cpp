// LUOGU_RID: 160423841
#include <bits/stdc++.h>
#define int long long

#define F(i, a, b) for (int i = (a); i <= (b); i++)
#define dF(i, a, b) for (int i = (a); i >= (b); i--)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1005, M = (N << 1), inf = 1e16, mod = 1e9 + 7;
int n, m, k[N];
vector<int> a[N], vec;
double C[N][N], f[N][N], g[N][N];
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    F(i, 0, 1000)
    for (int j = C[i][0] = 1; j <= i; j++) 
    C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    F(i, 1, m) {
        cin >> k[i];
        F(j, 1, k[i]) {
            int x; cin >> x;
            a[i].push_back(x);
            vec.push_back(x);
        }
        sort(a[i].begin(), a[i].end());
    }
    sort(vec.begin(), vec.end(), greater<int>());
    int num = vec[n - 1], cnt = 0, all = 0;
    for (int i = 0; i < n; i ++) 
        if (vec[i] == num) cnt ++;
    all = count(vec.begin(), vec.end(), num);
    f[0][0] = 1;
    F(i, 1, m) {
        int x = upper_bound(a[i].begin(), a[i].end(), num) - a[i].begin();
        int y = lower_bound(a[i].begin(), a[i].end(), num) - a[i].begin();
        if (x == y) {
            F(j, 0, cnt) f[i][j] += f[i - 1][j] / C[k[i]][x];
        } else {
            F(j, 0, cnt) {
                f[i][j] += f[i - 1][j] / C[k[i]][x];
                if (j) f[i][j] += f[i - 1][j - 1] / C[k[i]][y];
            }
        }
    }
    cout << fixed << setprecision(10) << f[m][cnt] / C[all][cnt];
    return 0;
}
