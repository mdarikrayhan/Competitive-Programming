#include <bits/stdc++.h>
using namespace std;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
#define endl "\n"
#define pb push_back
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define sz(x) (int)((x).size())
#define re(i,a) for(long long i=0;i<a;++i)
#define rep(i,a,b) for(long long i=a;i<b;++i)
#define rer(i,a) for(long long i=a-1;i>=0;--i)
#define repr(i,a,b) for(long long i=b-1;i>=a;--i)
#define trav(a,x) for(auto &a:x)
#define int long long
#define ye cout<<"YES\n";
#define no cout<<"NO\n";
#define in(a) for(int i = 0; i<(a).size(); i++) cin>>a[i];
#define out(a) for(int i = 0; i<(a).size(); i++) cout<<a[i]<<" ";
#define ret(a) {cout<<(a)<<"\n"; return;}
using ll=long long;
using vi=vector<int>;
using vvi=vector<vi>;
using vll=vector<ll>;
using vvll=vector<vll>;
using vb=vector<bool>;
using vd=vector<double>;
using vs=vector<string>;
using pii=pair<int, int>;
using pll=pair<ll, ll>;
using pdd=pair<double, double>;
using vpii=vector<pii>;
using vpll=vector<pll>;
using vpdd=vector<pdd>;
const int M=1000000007;

int mat[17][10005];
int cost1[17][17];
int cost2[17][17];
int dp[(1<<16)][17][17]; //mask, first row, prev row


void solve(){
    int n,m;    cin>>n>>m;
    int mat[n][m];
    re(i,n){
        re(j,m) cin>>mat[i][j];
    }
    re(i,n){
        re(j,n){
            cost1[i][j]=2e9;
            re(k,m) cost1[i][j]=min(cost1[i][j],abs(mat[i][k]-mat[j][k]));
        }
    }
    re(i,n){
        re(j,n){
            cost2[i][j]=2e9;
            re(k,m-1) cost2[i][j]=min(cost2[i][j],abs(mat[i][k]-mat[j][k+1]));
        }
    }
    memset(dp,0,sizeof(dp));
    re(i,n){
        dp[(1<<i)][i][i]=2e9;
    }
    rep(mask,1,(1<<n)-1){
        re(i,n){ //first row
            re(j,n){ //previous row
                int nrows=__builtin_popcount(mask);
                if(i==j && nrows!=1) continue;
                if(!(mask&(1<<i))) continue;
                if(!(mask&(1<<j))) continue;
                re(k,n){ //new row
                    if(mask&(1<<k)) continue;
                    int ns=mask|(1<<k);
                    int v=cost1[j][k];
                    int cost=min(dp[mask][i][j],v);
                    dp[ns][i][k]=max(dp[ns][i][k],cost);
                }

            }
        }
    }
    int ans=0;
    re(i,n){
        re(j,n){
            ans=max(ans,min(dp[(1<<n)-1][i][j],cost2[i][j]));
        }
    }
    cout<<ans;
}

int32_t main(){
    ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)	solve();
    return 0;
}