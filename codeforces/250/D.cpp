#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define fi first
#define se second
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define mp make_pair

int readInt () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}

const int MAXN = 1e5 + 7;
pii b[MAXN];
int a[MAXN];
int n, m, p, d;

ld dist(int x, int y){
    return (ld)sqrt((ll)(a[x] - b[y].fi) * (a[x] - b[y].fi) + (ll)(p - d) * (p - d)) + (ld)sqrt((ll)p * p + (ll)a[x] * a[x]) + b[y].se;
}

void solve(){
    cin >> n >> m >> p >> d;
    
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    
    for(int i = 1; i <= m; i++){
        cin >> b[i].fi;
    }
    for(int i = 1; i <= m; i++){
        cin >> b[i].se;
    }
    
    ld ans = 1e18;
    pii res;
    int j = 1;
    for(int i = 1; i <= m; i++){
        while(j < n && dist(j, i) > dist(j + 1, i)){
            j++;
        }
       
        if(ans > dist(j, i)){
            ans = dist(j, i);
            res = {j, i};
        }
    }
    
    cout << res.fi << ' ' << res.se << '\n';
}

int main(){
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }

    return 0;
}