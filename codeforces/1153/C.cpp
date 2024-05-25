#include <bits/stdc++.h>
 
#define ios ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(s) if (fopen(s".in", "r")) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
#define all(a) a.begin() , a.end()
#define F first
#define S second
 
using namespace std;
using ll = long long;
 
const ll N = 1e3+5 , inf = 2e9 + 7;
const ll INF = 1e18 ,   mod = 1e9+7;

void solve(){
	int n ;
	cin >> n;
	string s;
	cin >> s;
	int cnt = 0 , kol = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '(') cnt++;
		else if(s[i] == ')') kol++;
	}
	int pr = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '(') pr++;
		else if(s[i] == ')') pr--;
		else {
			if(cnt<n/2) cnt++ , s[i] = '(' , pr++;
			else kol++ , s[i] = ')' , pr--;
		} 
		if(pr <= 0 && i+1 < s.size()){
			cout << ":(";
			return;	
		}
		if(pr != 0 && i+1 == s.size()){
			cout << ":(";
			return;	
		}
	}
	string s1 = s;
	reverse(all(s));
	pr = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == ')') s[i] = '(';
		else if(s[i] == '(') s[i] = ')';
		
		if(s[i] == '(') pr++;
		else if(s[i] == ')') pr--;
		
		if(pr <= 0 && i+1 < s.size()){
			cout << ":(";
			return;	
		}
		if(pr != 0 && i+1 == s.size()){
			cout << ":(";
			return;	
		}
	}
	cout << s1;
}
/*
*/
signed main(){
	ios;
	solve();
}