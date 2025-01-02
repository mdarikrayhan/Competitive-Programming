#include <bits/stdc++.h>
using namespace std;
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
#define endl "\n"
#define int ll
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int mod=1e9+7;
#define OVL(x,s) for(auto y:x) cout<<y<<s; cout<<"\n";
template <typename T> istream& operator>>(istream& is, vector<T> &a) {
    copy_n(istream_iterator<T>(is), a.size(), a.begin()); return is;}
#ifdef IOI
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__);
#else
#define dbg(...) 1337;
#endif
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
const int mxn=2e5+100;
set<int> m,a,b;
int solve(string t){
	if(t.length()==1) {
		if(t=="0") return 1;
		if(t=="_") return 1;
		return 0;
	}
	if(t.back()=='0') return 0;
	if(isdigit(t[0])&&isdigit(t[1])){
		int a=t[0]-'0'+(t[1]-'0')*10;
		dbg(a)
		if(m.count(a)==0) return 0;
	}
	int ans=1;
	int n=t.length();
	if(t[0]=='_'&&t[0]==t[1]){
		if(t.length()==2) ans=3;
		else{
			ans=4;
		}
	}
	if(t[0]=='_'&&isdigit(t[1])){
		if(b.count(t[1]-'0')) ans=1;
		else return 0;
	}
	if(isdigit(t[0])&&t[1]=='_'){
		if(a.count(t[0]-'0')) {
			if(t.length()==2&&t[0]=='0') ans=1;
			else ans=2;
		}
		else return 0;
	}
	for(int i=2;i<n;i++){
		if(t[i]=='_') {
			if(i==n-1) ans*=9;
			else ans*=10;
		}
	}
	return ans;
}
signed main(){
ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
string s;
cin>>s;
a.insert(0);
a.insert(5);
b.insert(0);
b.insert(2);
b.insert(5);
b.insert(7);
m.insert(0);
m.insert(25);
m.insert(50);
m.insert(75);
int n=s.length();
int ans=0;
if(count(all(s),'X')==0||(s.length()<=1&&count(all(s),'X')==0)){
	reverse(all(s));
	cout<<solve(s)<<endl;
	return 0;
}
for(int j=0;j<=9;j++){
	string t=s;
	for(int k=0;k<n;k++){
		if(t[k]=='X') t[k]=j+'0';
	}
	reverse(all(t));
	ans+=solve(t);
}
cout<<ans<<endl;
}