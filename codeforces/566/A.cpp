#pragma GCC optimize ("Ofast,unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef vector<int > vi;
typedef vector<ll > vl;
#define pb push_back
#define f(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define fr(i, b, a) for(ll i = (ll)a - 1; i >= (ll)b; i--)
#define ff first
#define ss second
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define all(v) (v).begin(), (v).end()
#define sz size
#define trace(...) fff(#__VA_ARGS__, __VA_ARGS__)
template<typename t> void fff(const char* x, t&& val1) { cout<<x<< " : "<<val1<<"\n";}
template<typename t1, typename... t2> void fff(const char* x, t1&& val1, t2&&... val2){
    const char* xd=strchr(x+1, ',');
    cout.write(x, xd-x)<<" : "<<val1<<" | ";
    fff(xd+1, val2...);
}
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 1e9 + 7;
int add(int a, int b){
    if(a + b >= mod){
        return a + b - mod;
    }
    return a + b;
}
int rem(int a, int b){
    if( a <= b){
        return a - b + mod;
    }
    return a - b;
}
int mul(ll a, ll b){
    return (ll) (a * b) % mod;
}
const ll N = 1e5 + 1;
int triee[8*N][27], ans[N], nod = 0, dpt = 0, ch, cur, j, i;
string q;
ll sum = 0;
vi an[8*N][2];
void ad(int c){
    cur = 0;
    for(j = 0; j < q.sz(); j++){
        ch = q[j] - 'a';
        if(triee[cur][ch] == -1) triee[cur][ch] = ++nod;
        cur = triee[cur][ch];
    }
    an[cur][c].pb(i);
}
void dfs(int a){
    for(short g = 0; g < 27; g++){
        if(triee[a][g] == -1) continue;
        dpt ++;
        dfs(triee[a][g]);
        dpt --;
        for(j = 0; j < 2; j++){
            for(auto z: an[triee[a][g]][j]) an[a][j].pb(z);
            an[triee[a][g]][j].clear();
        }
    }
    while(an[a][0].sz() > 0 and an[a][1].sz() > 0){
        ans[an[a][0][an[a][0].sz() - 1]] = an[a][1][an[a][1].sz() - 1];            sum += dpt;
        for(j = 0; j < 2; j++) an[a][j].pop_back();
    }
}
int main(){
    fastio;
    memset(triee, -1, sizeof triee);
    int n; cin >> n;
    for(i = 0; i < n; i++){
        cin >> q;
        ad(0);
    }
    for(i = 0; i < n; i++){
        cin >> q;
        ad(1);
    }
    dfs(0);
    cout << sum << "\n";
    for(i = 0; i < n; i++) cout << i + 1 << " " << ans[i]  + 1 << "\n";
    return 0;
}

/*
#################################################################################################
#                                        You told me                                            #
#           At your absolute best, you still won't be good enough for the wrong person          #
#                   At your worst, you'll still be worth it to the right person                 #
#                           It was good while it lasted, good bye                               #
#    I believe I really loved you... to that point that I always wanted to hear your voice      #
#    But before my hand could reach you... you seem to be slowly disappearing from my sight     #
#                        Sé muy bien que es imposible pero voy a seguir...                      #
#################################################################################################
*/

  			 			 	 	  				    	 	  	