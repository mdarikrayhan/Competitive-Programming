#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
// *a.find_by_order(b) = bth element, a.order_of_key(b) = no. of elemets smaller than b
// use less_equal<int> for multiset
// less<int> is a comparator,greater int would sort it in descending order
typedef long long int ll;
typedef long double ld;
#define int long long
#define endl "\n"
#define bits(x) __builtin_popcountll(x)
#define minvec(a) *min_element(all(a))
#define maxvec(a) *max_element(all(a))
const ll mod = 1e9+7;
const ll mod1 = 998244353;
const ld pie = 3.141592653589793238;

ll ciel(ll a,ll b){
    if(a%b==0){
        return (a/b);
    }
    return ((a/b)+1);
}


ll binToDec(string s) { return bitset<64>(s).to_ullong(); }
string decToBin(ll a) { return bitset<64>(a).to_string(); }


/*
   *********************SOLVE****************************
*/

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    t=1;
    //cin>>t;
    vector<ll>pow2;
    pow2.push_back(1);
    for(int i=1; i<32; i++){
        pow2.push_back(pow2[i-1] * 2);
    }
    while(t--){
        ll n,q;
        cin>>n>>q;
        vector<vector<ll>>fin(n+1,vector<ll>(50,-1));
        vector<vector<pair<ll,ll>>>grp(n+1);
        for(int i=0; i<q; i++){
            ll u,v,x;
            cin>>u>>v>>x;
            grp[min(u,v)].push_back({max(u,v),x});
            ll cnt=0;
            ll tx=x;
            while(cnt < 50){
                if(tx % 2 == 0){
                    fin[u][cnt] = 0; fin[v][cnt] = 0;
                }
                tx /= 2; cnt++;
            }
        }

        for(int i=1; i<=n; i++){
            ll pos = 0;
            while(pos < 50){
                bool ok = 1;
                for(int j=0; j<grp[i].size(); j++){
                    ll u = i, v = grp[i][j].first, x = grp[i][j].second;
                    ll bit = x >> pos;
                    if(bit % 2 == 1){
                        if((fin[v][pos] == 0) || (u == v)){
                            ok=0; break;
                        }
                    }
                }
                if(fin[i][pos] == 1){
                    ok=0;
                }
                if(!ok){
                    fin[i][pos] = 1; pos++; continue;
                }
                for(int j=0; j<grp[i].size(); j++){
                    ll u=i,v=grp[i][j].first,x=grp[i][j].second;
                    ll bit = x >> pos;
                    if(bit % 2 == 1){
                        fin[v][pos] = 1;
                    }
                }
                pos++;
            }
        }
        vector<ll>a(n+1,0);
        for(int i=1; i<=n; i++){
            ll add = 1;
            for(int j=0; j<50; j++){
                if(fin[i][j] == 1){
                    a[i] += add;
                }
                add *= 2;
            }
        }
        for(int i=1; i<=n; i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
}