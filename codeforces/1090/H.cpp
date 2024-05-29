#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
using LL = long long;
int pre[400005][20];

int main(){

#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    // 条件等价于对于i = [0, log(n)], lowbit在第i位是位置全部相等.
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = "0" + s;
    vector<int> val(n + 1);
    for(int i = 1; i <= n; i++){
        val[i] = s[i] ^ s[i + 1];
    }
    for(int i = 0; i <= 19; i++){
        for(int j = n - 1; j >= 1; j--){
            pre[j][i] = val[j];
            if (j + (1 << i + 1) < n){
                pre[j][i] += pre[j + (1 << i + 1)][i];
            }
        }
    }
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        l++, r++;
        int len = (r - l + 1);
        int ans = 0;
        for(int i = 0; i + 1 <= __lg(len); i++){
            int pos = l + (1 << i) - 1;
            int t = pre[pos][i];
            if (pos + len < n) t -= pre[pos + len][i];
            ans += min(t, len / (1 << i + 1) - t);
        }
        cout << (ans + 1) / 2 << '\n';
    }

}