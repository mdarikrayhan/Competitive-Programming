#include <bits/stdc++.h>
#define ll long long
#define ls (v << 1)
#define rs ((v << 1)|1)
#define ll long long
#define free fajeiof
#define right fjewiofjaewoi
int gcd(int a, int b){
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
ll power(ll a , ll b , ll c){
	ll res = 1;
	while (b){
		if (b%2)
			res *= a;
		a *= a;
		res %= c;
		a %= c;
		b /= 2;
	}
	return res;
}
using namespace std;
 
const int nmax = 400010;
const int inf = 1e9 + 7;
const ll mod = 998244353;
const bool IS_TEST = 0;
 
int tt, k;
string s;
vector<int> pos[30];
bool used[nmax];
string res;

bool check(string &s){
    if (s.empty()) return false;
    if (s.size() > 1 && s[0] == '0') return false;
    if (s.size() == 7)
        return (s == "1000000");
    return true;
}

void solve(){
    cin >> s;
    int n = s.size();
    int ans = -1;
    for (int len1 = 1; len1 <= min(7, n - 2); len1++)
    for (int len2 = 1; len2 <= min(7, n - len1); len2++){
        int len3 = n - len1 - len2;
        if (len3 <= 0 || len3 > 7) continue;
        string s1 = s.substr(0, len1);
        string s2 = s.substr(len1, len2);
        string s3 = s.substr(len1 + len2, len3);
        if (check(s1) && check(s2) && check(s3)){
            //cout << s1 << " " << s2 << " " << s3 << endl;
            ans = max(ans, stoi(s1) + stoi(s2) + stoi(s3));
        }
    }
    cout << ans << endl;
    
}

 
void prep(){
    
}
 
int main()
{
	srand(time(0));
//	std::ios::sync_with_stdio(false);
//	cin.tie(0);
	
	prep();
    
    if (IS_TEST){
    	cin >> tt;
    } else
		tt = 1;
	while (tt--){
	    solve();
	}
	
	
	return 0;
}