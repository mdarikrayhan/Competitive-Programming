// LUOGU_RID: 160596379
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const long long base = 137;
const long long mod = 1e9 + 7;
string s; bool ok[maxn][20];
int n, H[maxn], cnt[maxn][30], power[maxn];
long long score[maxn][30], d[maxn], a[maxn];
int Get(char c, int low, int high){
    return cnt[high][c - 'a'] - cnt[low - 1][c - 'a'];
}
int getHash(int l, int r){
    if (l == 0) return H[r];
    return (H[r] - H[l - 1] * (long long) power[r - l + 1] + mod * (long long) mod) % mod;
}
void Prepare(){
    cin >> s;
    n = (int) s.size(); s = ' ' + s;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; i++){
        for (int j = 'a' - 'a'; j <= 'z' - 'a'; j++)
            cnt[i][j] = cnt[i - 1][j];
        cnt[i][s[i] - 'a']++;
    }
    power[0] = 1;
    for (int i = 1; i <= n; i++)
        power[i] = (power[i - 1] * base) % mod;
    H[1] = s[1];
    for (int i = 2; i <= n; i++)
        H[i] = (H[i - 1] * (long long) base + s[i]) % mod;
    memset(ok, false, sizeof(ok));
    for (int i = 1; i <= n; i++)
        ok[i][1] = true;
    for (int j = 2; (1 << j) - 1 <= n ; j++)
    for (int i = 1; i + (1 << j) - 2 <= n; i++){
        if (Get(s[i + (1 << (j - 1)) - 1], i, i + (1 << j) - 2) == 1 &&
            ok[i][j - 1] && ok[i + (1 << (j - 1))][j - 1] &&
            getHash(i, i + (1 << (j - 1)) - 2) == getHash(i + (1 << (j - 1)), i + (1 << j) - 2))
            ok[i][j] = true;
        else ok[i][j] = false;
	}
}
int FirstDiff(int i, int j, int x, int y){
    int low = 0, high = j - i, res = high + 1;
    while (low <= high){
        int mid = (low + high) / 2;
        if (getHash(i, i + mid) != getHash(x, x + mid))
            res = min(res, mid), high = mid - 1;
        else low = mid + 1;
    }
    if (res == j - i + 1) return -1;
    if (i + res + 1 <= j){
        if (getHash(i + res + 1, j) != getHash(x + res + 1, y))
            return -1;
    }
    return res;
}
void Process(int low, int high, int sz){
    long long delta = (high - low + 1) * ((long long) high - low + 1);
    if (ok[low][sz]){
        a[low] += delta; a[high + 1] -= delta;
        d[1] += delta; d[low] -= delta;
        d[high + 1] += delta; d[n + 1] -= delta;
    }
    int mid = (high + low) / 2;
    if (ok[low][sz - 1] && ok[low + (1 << (sz - 1))][sz - 1] &&
        getHash(low, low + (1 << (sz - 1)) - 2) == getHash(low + (1 << (sz - 1)), low + (1 << sz) - 2)){
        for (int i = 'a' - 'a'; i <= 'z' - 'a'; i++)
        if (i != s[mid] - 'a' && Get(char(i + 'a'), low, high) - ((int) s[mid] - 'a' == i) == 0)
            score[mid][i] += delta;
    }
    int p = FirstDiff(low, low + (1 << (sz - 1)) - 2, low + (1 << (sz - 1)), high);
    if (ok[low][sz - 1] && Get(s[mid], low, low + (1 << (sz - 1)) - 2) == 0){
        if (p != -1) score[low + (1 << (sz - 1)) + p][s[low + p] - 'a'] += delta;
    }
    if (ok[low + (1 << (sz - 1))][sz - 1] && Get(s[mid], low + (1 << (sz - 1)), high) == 0){
        if (p != -1) score[low + p][s[low + (1 << (sz - 1)) + p] - 'a'] += delta;
    }
}
void Solve(){
    memset(score, 0, sizeof(score));
    for (int i = 1; i <= n; i++)
    for (int j = 2; i + (1 << j) - 2 <= n; j++)
        Process(i, i + (1 << j) - 2, j);
    d[0] = a[0] = 0;
    for (int i = 1; i <= n; i++) d[i] += d[i - 1], a[i] += a[i - 1];
    for (int i = 1; i <= n; i++){
        for (int j = 'a' - 'a'; j <= 'z' - 'a'; j++)
            score[i][j] += d[i];
        score[i][s[i] - 'a'] += a[i];
    }
    long long res = 0;
    for (int i = 1; i <= n; i++)
    for (int j = 'a' - 'a'; j <= 'z' - 'a'; j++)
        res = max(res, score[i][j] + n);
    cout << res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    Prepare();
    Solve();
}