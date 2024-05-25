#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define endl '\n'
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl


typedef pair<int, int> PI;
typedef vector<int> VI;
typedef long long LL;

const int MX = 200005;

int n, l[MX], r[MX];
bool vis[MX];

struct show{
	int l, r;
	show(){}
	show(int l, int r) : l(l), r(r){}
}sh[MX];


bool cmp(const show& s1, const show& s2){
	if(s1.l == s2.l) return s1.r > s2.r;
	return s1.l < s2.l;
}

void solve(){
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> sh[i].l >> sh[i].r;
	}
	
	sort(sh, sh + n, cmp);
	vis[0] = 1;
	int en = sh[0].r;
	int cur = 0, cnt1 = 1;
	while(++cur < n){
		if(sh[cur].l <= en) continue;
		cnt1++;
		vis[cur] = 1;
		en = sh[cur].r;
	}
	
//	cout << cnt1 << endl;
	if(cnt1 >= n - 1){
		YES;
		return;
	}
	
	for(int i = 0; i < n; i++){
		if(!vis[i]){
			cur = i;
			break;
		}
	}
	
	int cnt2 = 1;
	en = sh[cur].r;
	while(++cur < n){
		if(vis[cur]) continue;
		if(sh[cur].l <= en) continue;
		cnt2++;
		vis[cur] = 1;
		en = sh[cur].r;
		if(cnt1 + cnt2 == n){
			YES;
			return;
		}
	}
	
	NO;
	
	
}

int main(){
#ifndef ONLINE_JUDGE
//	freopen("fin.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int Tc = 1;
//	cin >> Tc;
	while(Tc--) solve();

	return 0;
}
