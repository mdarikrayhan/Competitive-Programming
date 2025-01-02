#include <bits/stdc++.h>             //                          الْحَمْدُ لِلَّهِ وَحْدَهُ
using namespace std;                 //           وَالصَّلاَةُ وَالسَّلاَمُ عَلَى مَنْ لاَ نَبِيَّ بَعْدَهُ

typedef long long       ll;          //        All praise is due to Allah alone,
typedef vector<int>     vi;          //  and peace and blessings be upon him after
typedef pair<int, int>  pii;         //         whom there is no other Prophet.
typedef map<int,int>    mii;    

#define cin(ar)         for(auto &i: ar) cin >> i;
#define cout(ar)        for(auto i: ar) cout << i <<' '; cout << '\n';
#define yes             cout << "YES\n";
#define no              cout << "NO\n";
#define eb(x)           emplace_back(x)
#define po              pop_back()
#define mp(x, y)        make_pair(x, y)
#define all(ar)         ar.begin(), ar.end()
#define rall(ar)        ar.rbegin(), ar.rend()
#define Case(x)         cout << "Case "<<x<<": ";
#define bug             cout << "You are sinner\n";
inline  ll POW(ll n,ll k){ll ans=1;while(k){if(k&1)ans=ans*n;n=n*n;k>>=1;}return ans;}
const   int mod = 1e9+7, inf = 1e9+9, N = 2e5+5;

inline void test_case(int T){
    int n; cin >> n;
    vi ar(n+1);  for(int i = 1; i <= n; i++) cin >> ar[i];
    int one = 0;
    for(auto i : ar) one += abs(i);
    
    if(one & 1){cout << "-1\n"; return;}
    vector<pii> p;
    int prev = 1;
    for(int i = 1, sum = 0; i <= n; i++){
        if(ar[i] != 0){
            if(prev != i and sum == 0) p.push_back({prev, i-1}), prev = i;
            if(sum == 0) {
                sum += (i-prev) & 1 ? -1 * ar[i] : ar[i];
            }
            else{
                if(sum < 0){
                    if((i-prev) & 1){
                        if(ar[i] < 0){
                            p.emplace_back(make_pair(prev, i));
                        }
                        else{
                            p.emplace_back(mp(prev, i-1));
                            p.emplace_back(mp(i, i));
                        }
                        
                    }
                    else{
                        if(ar[i] < 0){
                            p.emplace_back(mp(prev, i-2));
                            p.emplace_back(mp(i-1, i));
                        }
                        else p.emplace_back(make_pair(prev, i));
                    }
                    prev = i + 1;
                }
                else{
                    if((i-prev) & 1){
                        if(ar[i] < 0){
                            p.emplace_back(mp(prev, i-1));
                            p.emplace_back(mp(i, i));
                        }
                        else p.emplace_back(make_pair(prev, i));
                    }
                    else{
                        if(ar[i] < 0){
                            p.emplace_back(make_pair(prev, i));
                        }
                        else{
                            p.emplace_back(mp(prev, i-2));
                            p.emplace_back(mp(i-1, i));
                        }
                    }
                    prev = i + 1;
                }
                sum = 0;
            }
        }
    }
    if(prev <= n){
        p.push_back({prev, n});
    }
    cout << p.size() << '\n';
    for(auto [a, b] : p) cout << a << ' ' << b << '\n';
}
/// في سبيل الله
signed l9_30; signed main(){
    cin.tie(0)->sync_with_stdio(false);

    l9_30 = true;    cin>>l9_30;
    for(int T = 1; T <= l9_30; T++){
        test_case(T);
    }
    return l9_30 ^ l9_30;
}