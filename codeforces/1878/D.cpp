#include <bits/stdc++.h>
#define pb emplace_back
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
#define trace(x) cerr << #x << " = " << x << '\n'

using namespace std;

template<class T> bool chmax(T& A, T&& B) { return B > A? A = B, true : false; }
template<class T> bool chmin(T& A, T&& B) { return B < A? A = B, true : false; }

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int MxN = 2e5 + 5;
void solve(){
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	vector<int>l(k),r(k);
	for(auto &kk:l)cin>>kk,--kk;
	for(auto &kk:r)cin>>kk,--kk;
		int q;
	cin>>q;
	vector<int>cnt(n+1,0);
	while(q--){
		int x;
		cin>>x;
		cnt[--x]++;
	}
	for(int i=0;i<k;i++){
		int p=0;
		int ll=l[i];
		int rr=r[i];
		for(int j=ll;j<=(ll+rr)/2;j++){
			p+=cnt[j]+cnt[rr-j+ll];
			if(p&1)swap(s[j],s[ll+rr-j]);
		}
	}
	cout<<s<<endl;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
    	solve();
    }
    return 0;
    // ...
}