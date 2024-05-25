#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define endl "\n"
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define ff first
#define ss second
#define forl(i,n) for(int i=0;i<n;i++)
 
void dbgp(vector<pair<ll,ll> >& vec){
    for(auto i:vec) cerr << i.ff << " " << i.ss << endl;
}
 
void dbg(){
    cerr << "here" << endl;
}

struct DSU { 
	vector<ll> parent, rnk; 
	ll n; 
	DSU(ll _n) { 
		n = _n; 
		parent.resize(n+1),rnk.resize(n+1);
		for (int i = 0; i <= n; i++) { 
			rnk[i] = 0; 
			parent[i] = i; 
		} 
	} 

	ll find(ll u){ 
		if (u != parent[u]) parent[u] = find(parent[u]); 
		return parent[u]; 
	} 

	void merge(ll x, ll y) { 
		x = find(x), y = find(y); 
		if (rnk[x] > rnk[y]) parent[y] = x; 
		else parent[x] = y; 

		if (rnk[x] == rnk[y]) rnk[y]++; 
	} 
};


void solve(){
    ll n,a,b;
    cin >> n >> a >> b;

    vector<ll> vec(n);
    map<ll,ll> pos;
    forl(i,n){
        cin >> vec[i];
        pos[vec[i]]=i;
    }

    DSU dsu(n);
    vector<ll> can_a(n,0),can_b(n,0);

    forl(i,n){
        if(pos.count(a-vec[i])){
            can_a[i]=1;
            dsu.merge(i,pos[a-vec[i]]);
        }
        if(pos.count(b-vec[i])){
            can_b[i]=1;
            dsu.merge(i,pos[b-vec[i]]);
        }
    }

    vector<ll> comp(n,3);
    forl(i,n){
        ll mask = 0;
        if(can_a[i])mask+=1;
        if(can_b[i])mask+=2;
        comp[dsu.find(i)]&=mask;
    }

    forl(i,n){
        if(!comp[i]){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    forl(i,n){
        if(comp[dsu.find(i)]==1) cout << 0 << " ";
        else cout << 1 << " ";
    }
    cout << endl;

}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--){
        solve();
    }
}