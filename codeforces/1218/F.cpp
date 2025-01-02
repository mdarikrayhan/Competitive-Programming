#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define endl '\n'
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl


typedef pair<int, int> PI;
typedef vector<int> VI;
typedef long long LL;

const int MX = 100005;
priority_queue<LL, vector<LL>, greater<LL> > pq;
int n, k, a; 	
LL x[MX], c[MX];

void solve(){
	cin >> n >> k;
	
	for(int i = 0; i < n; i++){
		cin >> x[i];
	}
	cin >> a;
	
	LL cnt = 0;
	for(int i = 0; i < n; i++){
		cin >> c[i];
		pq.push(c[i]);
		
		while(k < x[i]){
			if(pq.empty()){
				cout << -1 << endl;
				return;
			}
			cnt += pq.top();
			pq.pop();
			k += a;
		}
	}
	
	cout << cnt << endl;
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
