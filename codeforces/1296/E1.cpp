#include <bits/stdc++.h>

using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
typedef pair<int, int>             pii;
typedef pair<pii, int>              piii;
typedef pair<long long, long long> pll;
typedef pair<pll, long long>        plll;
typedef vector<int>                vi;
typedef vector<vector<int>>        vvi;
typedef vector<long long>          vl;
typedef vector<vector<long long>>  vll;
typedef vector<pii>                vpii;
typedef vector<piii>               vpiii;
typedef vector<pll>                vpll;
typedef vector<plll>               vplll;
typedef vector<vector<plll>>       vvplll;
typedef vector<vector<pll>>        vvpll;
typedef vector<vector<piii>>       vvpiii;
typedef vector<vector<pii>>        vvpii;
#define pb push_back
#define mp make_pair
#define data data_
#define endl "\n"
#define isOn(S, j) (S & (1ll << (j)))
#define setBit(S, j) (S |= (1ll << (j)))
#define clearBit(S, j) (S &= ~(1ll << (j)))
#define toggleBit(S, j) (S ^= (1ll << (j)))
#define bzero(b,len) (memset((b), '\0', (len)), (void) 0)

int main(){
	optimizar_io;
	int n;
	cin >> n;
	string str;
	cin >> str;
	vvi g(n);
	for (int i = 0; i < str.size(); i++){
		for (int j = i + 1; j < str.size(); j++){
			if (str[j] < str[i]){
				g[i].pb(j);
				g[j].pb(i);
			}
		}
	}
	bool ok = true;
	int colors[n];
	for (int i = 0; i < n; i++) colors[i] = -1;
	for (int i = 0; i < n; i++){
		if (colors[i] == -1){
			queue<int> pending;
			pending.push(i);
			colors[i] = 0;
			while(pending.size()){
				int u = pending.front();
				pending.pop();
				for (int j : g[u]){
					if (colors[j] == -1){
						colors[j] = 1 - colors[u];
						pending.push(j);
					} else if (colors[j] != 1 - colors[u]){
						ok = false;
					}
				}
			}
		}
	}
	if (ok){
		cout << "YES" << endl;
		for (int i = 0; i < str.size(); i++){
			cout << colors[i];
		}
		cout << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}
