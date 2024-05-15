#include <bits/stdc++.h>
using namespace std;
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
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

int main() {
  fastIO;
  ll t, n, m, sumita = 0; cin >> t;

  while(t--){
    sumita = 0;
    cin >> n >> m;
    vector<int> v(n);
    vector<int> vi(m);

    forin(v); 
    for(int &i : vi){
      cin >> i;
      sort(all(v));
      v[0] = i;
    }

    for(int &i : v){
      sumita += i;
    }

    cout << sumita << endl;
  }
  return 0;
}

	 				 			      	 	 	  		   	 	