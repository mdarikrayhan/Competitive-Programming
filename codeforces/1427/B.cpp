#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long
#define ld long double
#define fs(n) cout<< fixed<<setprecision(n)
#define INF 0x3f3f3f3f3f3f3f3fLL
int dx[] = {1, 0, -1, 0, -1, -1, 1, 1};
int dy[] = {0, -1, 0, 1, -1, 1, -1, 1};
//const ll mod=1e9+7;
//ll fpow(ll a,ll b){
//    if(b==0)return 1;
//    ll ans=fpow(a%mod,b/2);
//    return ((b&1?(((a%mod)*((ans%mod)*(ans%mod)))):(((ans%mod)*(ans%mod)))))%mod;
//}
//const ll N=10000000+100;
//bool isprime[N];
//void sieve(){
//    fill(isprime,isprime+N, true);
//    isprime[1]=isprime[0]= false;
//    for (ll i = 2; i*i <= 10000000; i+=(1+(i&1))) {
//        if(isprime[i]){
//            for (ll j = i*i; j <= 10000000;j+=i) {
//                isprime[j]= false;
//            }
//        }
//    }
////    for (int i = 2; i <= 10000000; ++i) {
////        if(isprime[i])ans.push_back(i);
////    }
//}

ll sum(string &s,ll &n){
    ll ans=0;
    for (int i = 0; i < n; ++i) {
        if(s[i]=='W'){
            if(i){
                if(s[i-1]=='W')ans+=2;
                else ans++;
            }
            else ans++;
        }
    }
    return ans;
}
int main() {
    fast
    int t = 1;
    cin >> t;
    while (t--) {
        ll n, k, c = -1;
        string s;
        vector<pair<ll, ll>> v;
        cin >> n >> k >> s;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'W') {
                if (c > 0) {
                    v.emplace_back(c, (i - c)-1);
                }
                c = 0;
            } else {
                if (c != -1)c++;
            }
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); ++i) {
            ll l = v[i].second;
            for (int j = l + 1; j < n && k; ++j) {
                if (s[j] == 'W')break;
                s[j] = 'W';
                k--;
            }
        }
        for (int i = 0; i < n && k; ++i) {
            if (s[i] == 'W') {
                for (int j = i - 1; j >= 0 && k; --j) {
                    s[j] = 'W';
                    k--;
                }
                break;
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == 'W') {
                for (int j = i + 1; j < n && k; ++j) {
                    s[j] = 'W';
                    k--;
                }
                break;
            }
        }

            for (int i = 0; i < n&&k; ++i) {
                if(s[i]=='L')s[i]='W',k--;
            }


        cout << sum(s, n) << "\n";

    }
}