#include <bits/stdc++.h>             //                          الْحَمْدُ لِلَّهِ وَحْدَهُ
using namespace std;                 //           وَالصَّلاَةُ وَالسَّلاَمُ عَلَى مَنْ لاَ نَبِيَّ بَعْدَهُ

typedef long long       ll;          //        All praise is due to Allah alone,
typedef vector<int>     vi;          //  and peace and blessings be upon him after
typedef pair<int, int>  pii;         //         whom there is no other Prophet.
typedef map<int,int>    mii;    

// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>OM;
// const int dx[] = {+0,+1,+0,-1,-1,+1,-1,+1}, dy[] = {-1,+0,+1,+0,+1,+1,-1,-1};

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
#define bug             cout << "You are sinner\n" << nl;
inline  ll POW(ll n,ll k){ll ans=1;while(k){if(k&1)ans=ans*n;n=n*n;k>>=1;}return ans;}
const   int mod = 1e9+7, inf = 1e9+9, N = 2e5+5;

inline void test_case(int T){
    int n; cin >> n;
    vi ar(n), br(n+1, 0), cr(n+1, 0);
    for(int i = 0; i < n; i++){
        cin >> ar[i]; br[ar[i]]++;
    }
    set<int>ms, bs;
    int missing = 0;
    if(br[1] == 2 or br[n] == 0) {cout << "NO\n"; return;}
    for(int i = 1; i <= n; i++){
        if(br[i] > 2 or missing < 0) {cout << "NO\n"; return;}
        else if(br[i] == 0) ms.insert(i), missing++;
        else if(br[i] == 2) bs.insert(i), missing--;
    }
    cout << "YES\n";
    for(int i = 0; i < n; i++){
        if(br[ar[i]] == 2){
            if(bs.find(ar[i]) == bs.end()){
                auto it = prev(ms.lower_bound(ar[i]));
                cout << *it << ' ';
                cr[ar[i]] = *it;
                ms.erase(it);
            }
            else{
                cout << ar[i] << ' ';
                bs.erase(ar[i]);
            }
        }
        else cout << ar[i] << ' ';
    }
    cout << '\n';
    for(int i = 0; i < n; i++){
        if(br[ar[i]] == 1) cout << ar[i] << ' ';
        else {
            if(cr[ar[i]]) {
                cout << cr[ar[i]] << ' ';
                cr[ar[i]] = 0;
            }
            else cout << ar[i] << ' ';
        }
    }
    cout << '\n';
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