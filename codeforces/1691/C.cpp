#include<bits/stdc++.h>
using namespace std;
 
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
 
#ifndef ONLINE_JUDGE
#include "D:\cp\debug.cpp"
#else 
#define debug(x...)
#endif
 
#define int long long
#define ll long long 
#define endl "\n"
#define cy cout<<"YES\n";
#define cn cout<<"NO\n";
#define cl cout<<"\n";
#define con continue;
#define Cout(x) cout<<((x)?"YES\n":"NO\n")
#define MOD 1000000007
#define pb push_back
#define ppb pop_back
#define vi(l, n) vector<int>l(n); for(auto &I : l) cin >> I;
#define all(x) (x).begin(), (x).end()
#define rall(x) x.rbegin(),x.rend() 
#define sum(l) accumulate(l.begin(),l.end(),0ll)
string bin(int n){return bitset<32>(n).to_string();}
// #define bin(n) cout << bitset<64>(n).to_string() << endl;
 
template<class T> void print(T &l,string sep=" ") { for(auto &i:l) { cout<<i<<sep; } }
template<class T> T __lcm(T a, T b) { return (a*(b/__gcd(a,b))); }
template<class T> T max(vector<T>&l){return *max_element(all(l));}
template<class T> T min(vector<T>&l){return *min_element(all(l));}
template<class T>void minmax(T &a,T &b){T t = min(a,b); b = max(a,b); a = t;}
 
string bin1(int n){if(n == 0) return "0"; return bin(n).substr(bin(n).find('1'));}
 
signed main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
 
    int tt; cin >> tt;
 
    while(tt--) {
 
        int n, k; cin >> n >> k;
        string s; cin >> s;
 
        int ans = 0;
 
        int one = count(all(s), '1');
 
        int l = -1, r = -1;
 
        for(int i=0;i<n;i++) {
            if(s[i]=='1') {l=i; break;}
        }
        for(int i=n-1;i>=0;i--) {
            if(s[i]=='1') {r=i; break;}
        }
 
 
        if(one > 0 and (n - r - 1) <= k) {
            k -= (n - r - 1);
            one--;
            ans += 1;
        } 
 
        if(one > 0 and l <= k) {
            one--;
            ans += 10;
        }
 
        cout << ans + one * 11 << endl;
 
 
    }
}