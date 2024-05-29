#include<bits/stdc++.h>

using namespace std;

#define int long long
int dp[20005][10];
vector<int> v;
const int inf = 10004205361450474;

int ask(vector<int> &v) {
    cout << v.size() << ' ';
    for (int i: v) cout << i << ' ';
    cout << endl;
    int x;
    cin >> x;
    return x;
}

int cal(int num, int d) {
    if(num <= 10000) return dp[num][d];
    int res = 1e4;
    for (int i = 1; i < d; i++) res = res * (1e4 + 1) + 1e4;
    if(d == 0) res = 0;
    return res + num - 1;
}

void solve(int l, int query) {
    v.clear();
    int cur = l;
    for (int i = 1; i <= min(l, 10000ll); i++) {
        cur = cal(cur, query - 1)+1;
        if(cur > inf) break;
        v.push_back(cur);
        cur++;
    }
    int ans = ask(v);
    if(ans == -1 || query == 1) exit(0);
    if(ans == 0) solve(l, query - 1);
    else solve(v[ans-1] + 1, query - 1);
}

signed main() {
    for (int i = 1; i <= 10000; i++) {dp[i][1] = i + i - 1; dp[i][0] = i-1;}
    for (int j = 2; j <= 4; j++) {
        int mx = 1e4;
        for (int dm = 1; dm < j - 1; dm++) mx = mx * (1e4 + 1) + 1e4;
        for (int i = 1; i <= 10000; i++) {
            int num = i;
            for (int k = 0; k <= i; k++) {
                if(num > 10000) num += mx + 1;
                else num = dp[num][j - 1] + 2;
            }
            dp[i][j] = num - 2;
        }
    }
    int M = 10004205361450474, ans = M, cnt = 5;
    for (int i = 1; i <= 5; i++) {
        if(i == 5) {v={1}; int ac=ask(v); return 0;}
        int l = 1, r = 1e15, mid;
        cnt--;
        while(l <= r) {
            mid = (l + r) / 2;
            if(cal(mid, 5 - i) >= M) {
                r = mid - 1;
                ans = min(ans, mid);
            }
            else l = mid + 1;
        }
        ans--;
        M = ans-1;
        v = {ans};
        int x = ask(v);
        if(x == -1) return 0;
        if(x) break;
    }
    solve(ans + 1, cnt);
}

	  	  	 					 		 				  	 	 		