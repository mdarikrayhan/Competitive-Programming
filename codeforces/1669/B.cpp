#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define quickio ios::sync_with_stdio(false);
#define quickin cin.tie(nullptr);
#define quickout cout.tie(nullptr);
#define maxn 200005
using namespace std;
int T, n, a[maxn], cnt[maxn];
signed main() {
	quickio
	quickin
	quickout
    cin >> T;
    while(T--) {
        cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> a[i], cnt[i] = 0;
        for(int i = 1; i <= n; i++)
            cnt[a[i]]++;
        bool ans = 0;
        for(int i = 1; i <= n; i++)
            if(cnt[i] >= 3) {
                ans = 1, cout << i << endl;
                break ;
            }
        if(!ans) cout << "-1\n";
    }
 	return 0;
}