#include <bits/stdc++.h>
using namespace std;
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define F first
#define S second
#define pb push_back
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define forsn(i, s, n) for (int i = s; i < n; ++i)
#define forin(x) for(auto &i : (x))cin>>i;
#define dforn(i, n) for (int i = n - 1; i >= 0; --i)
#define DBG(x) cout << #x << " = " << x << endl;
#define sDBG(x) for(auto &el : x){cout<<el<<" ";}cout<<endl;
#define YESNO(b) cout<<(b? "YES" : "NO")<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<long long, long long> pll;
typedef long double ld;

std::ostream &operator<<(std::ostream &str, pii const &p) {
  return str << "(" << p.F << "," << p.S << ")";
}

int main() {
  fastIO;
 	int n; cin>>n;
 	vector<pii> v(n);
 	for(int i = 0; i < n; ++i){
 		cin>>v[i].F;
 		v[i].S = i+1;
 	}
 	if(v[0].F==0){
 		cout<<-1<<endl;
 		return 0;
 	}
 	sort(v.rbegin(), v.rend()-1);
 	//sDBG(v);
 	vector<int> mk(n,0);
 	vector<pii> cosos;
 	mk[0]=1;
 	for(int i = 1; i < n && i - 1 < v[0].F; ++i){
 		cosos.pb({1,v[i].S});
 		mk[i] = 1;
 	}
 	v[0].F = 0;

 	for(int i = 1; i < n; ++i){
 		int j = i+1;
		for(; j < n; ++j)if(!mk[j])break;
		if(j>=n || i>=n)continue;
		//cout<<i<<" "<<j<<" "<<n<<" "<<sz(v)<<endl;
		while(v[i].F-- && j < n){
			cosos.pb({v[i].S,v[j].S});
			mk[j++]=1;
		}
 	}
 	bool ok = 1;
 	for(int i = 0; i < n && ok; ++i){
 		ok = ok && mk[i] == 1;
 	}
 	if(!ok){
 		cout<<-1<<endl;
 		return 0;
 	}
 	//YESNO(ok);
 //	sDBG(mk);
 	cout<<sz(cosos)<<endl;
 	for(auto &p : cosos){
 		cout<<p.F<<" "<<p.S<<endl;
 	}
  return 0;
}
