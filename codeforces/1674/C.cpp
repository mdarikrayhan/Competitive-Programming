#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define endl '\n'
using namespace std;
using ll = long long;
using ld = long double;
void prt(bool f){cout<<((f)? "YES\n" : "NO\n");}
void out(){cout<<"-1\n";}
const ld PI = 2*acos(0.0);
const ld EPS = 1e-11;
const int MOD = 1e9 + 7;
// const int MOD = 998244353;
const int INF = 1e9;
const int N = 2e5;
const int M = 1e6;
const int B = 11;
// #define int ll

void ah_shit_here_we_go_again()
{
    string s, t; cin>>s>>t;
    bool thasa = false;
    for(auto &i : t)
        thasa |= i == 'a';
    if(thasa && t != "a")
        return out();
    if(thasa && t == "a")
        return void (cout<<1<<endl);
    cout<<(1LL << sz(s))<<endl;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin>>t;
    for(int i = 1; i <= t; ++i)
        ah_shit_here_we_go_again();
    return 0;
}

/*

*/