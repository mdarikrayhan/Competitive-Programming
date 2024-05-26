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

void solve(){
    int n, k, l;
    cin >> n >> k >> l;
    
    vi a(n + 1);
    vi pos = {0, n + 1};
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] + k <= l){
            pos.pb(i);
        }
    }
    sort(pos.begin(), pos.end());
    
    for(int i = 1; i < (int)pos.size(); i++){
        int akt = k;
        bool f = true;
        for(int j = pos[i - 1] + 1; j < pos[i]; j++){
            if(f){
                akt--;
                akt -= max(0, a[j] + akt - l);
            }else{
                akt++;
            }
            
            if(akt < 0 || akt + a[j] > l){
                cout << "NO\n";
                return;
            }
            
            if(akt == 0){
                f = false;
            }
        }
    }
    
    cout << "YES\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}