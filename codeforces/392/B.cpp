#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
template <typename C> void UNIQUE(vector<C> &v) { sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin()); }
int Log2(int x) {return 31-__builtin_clz(x);}
inline void fmin(int &x, int y){if(x > y)x=y;}
inline void fmax(int &x, int y){if(x < y)x=y;}
int dx[8]={0, 1, 0, -1, 1, -1, -1, 1};
int dy[8]={1, 0, -1,0, 1, -1, 1, -1};

#define int long long
# define Amgadshrief ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lld long double
const int mod = 1000000007;

int cost[3][3];
int dp[44][3][3];

int solve(int n , int source , int target){
    if(!n) return 0;
    int &ret = dp[n][source][target];
    if(~ret) return ret;

    int aux = 3 - source - target;
    ret = solve(n-1,source,aux) + cost[source][target]
            + solve(n-1,aux,target);

    ret = min(ret ,solve(n-1,source,target) + solve(n-1,target,aux) +
    cost[source][target]
    + solve(n-1,aux,target) );

    ret = min(ret , solve(n-1 , source , target)
    +cost[source][aux]+
    solve(n-1,target,source)
    + cost[aux][target]
    + solve(n-1,source,target));

    return ret;
}

void TT() { //think twice code once
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++) cin>>cost[i][j];
    }
    int n; cin>>n;
    memset(dp,-1,sizeof dp);
    cout<<solve(n , 0 , 2)<<'\n';
}

signed main() {
    Amgadshrief
//    int t = 1; cin>>t; while(t--) TT();
    TT();
}