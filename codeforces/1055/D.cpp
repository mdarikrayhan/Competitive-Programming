#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define PB push_back
#define FS first
#define SD second
#define ary(k) array<int,k>
template<class A,class B> void cmx(A& x, B y) {x=max<A>(x,y);}
template<class A,class B> void cmn(A& x, B y) {x=min<A>(x,y);}
typedef pair<int, int> pii;
typedef vector<int> vi;
vi pi(const string& s) {
	vi p(sz(s));
	rep(i,1,sz(s)) {
		int g = p[i-1];
		while (g && s[i] != s[g]) g = p[g-1];
		p[i] = g + (s[i] == s[g]);
	}
	return p;
}

vi match(const string& s, const string& pat) {
	vi p = pi(pat + '\0' + s), res;
	rep(i,sz(p)-sz(s),sz(p))
		if (p[i] == sz(pat)) res.PB(i - 2 * sz(pat));
	return res;
}
signed main() {
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(cin.failbit);
    int n; cin >> n; 
    vector<string> s(n),t(n);
    rep(i,0,n) cin >> s[i]; 
    rep(i,0,n) cin >> t[i];
    string ns,nt;
    vector<pii> need;
    rep(i,0,n){
        int fs = -1,sd;
        rep(j,0,sz(s[i])){
            if(s[i][j] != t[i][j]){
                if(fs == -1) fs = j;
                sd = j;
            }
        }
        if(fs != -1){
            string x = s[i].substr(fs,sd-fs+1);
            string y = t[i].substr(fs,sd-fs+1);
            if(!sz(ns) || (ns == x && nt == y)){
                ns = x; nt = y; 
            } else{
                cout << "NO\n";
                return 0;
            }
            need.PB({i,fs});
        }
    }
    cerr << "base " << ns << " " << nt << " " << sz(need) << "\n";
    int len = sz(ns); 
    for(int j = 0; ; j++){
        char c = 0;
        for(auto[i,f]:need){
            if(f+len+j >= sz(s[i]) || (c && s[i][f+len+j] != c)){
                c = 0;
                break;
            }
            c = s[i][f+len+j];
        }
        if(!c) break; 
        ns += c; nt += c;
    } 
    for(int j = 1; ; j++){
        char c = 0;
        for(auto[i,f]:need){
            if(f-j < 0 || (c && s[i][f-j] != c)){
                c = 0;
                break;
            }
            c = s[i][f-j];
        }
        if(!c) break; 
        ns = c + ns; nt = c + nt;
    }
    cerr << "final " << ns << " " << nt << "\n";
    rep(i,0,n){
        auto vec = match(s[i],ns);
        string x = s[i];
        if(sz(vec)){
            rep(j,0,sz(ns)) x[j+vec[0]] = nt[j];
        }
        if(x != t[i]){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n" << ns << "\n" << nt << "\n";
}
