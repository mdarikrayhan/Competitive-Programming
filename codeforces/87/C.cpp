#include<bits/stdc++.h>

#define ll long long
#define oo 0x3f3f3f3fLL
#define INF 0x3f3f3f3f3f3f3f3fLL
#define mem(a, n) memset((a),n,sizeof (a))
#define sz(s) (int) (s.size())
#define all(v) v.begin(), v.end()

void fast();
ll gcd(ll x, ll y) { return (!y ? x : gcd(y, x % y)); }

ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }

int dx[]{1, -1, 0, 0, 1, 1, -1, -1};
int dy[]{0, 0, 1, -1, 1, -1, 1, -1};
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<vector<pair<int,int>>>range(n+5);
    for (int i=1;i<=n;i++){
        int sum=i;
        for (int j=i+1;j+sum<=n;j++){
            sum+=j;
            range[sum].push_back({i,j});
        }
    }

    vector<int>pre(n+5),dp(n+5);
    for (int i=1;i<=n;i++){
        unordered_set<int>st;
        for (auto &it:range[i]){
            st.insert(pre[it.second]^pre[it.first-1]);
        }
        int mex=0;
        while (st.find(mex)!=st.end())
            mex++;
        dp[i]=mex;
        pre[i]=mex;
        pre[i]^=pre[i-1];
    }

    if (dp[n]==0){
        cout<<-1<<"\n";
        return;
    }
    int ans=n+5;
    for (auto &it:range[n]){
        if ((pre[it.second]^pre[it.first-1])==0){
            ans=min(ans,it.second-it.first+1);
        }
    }
    cout<<ans;



}
int main() {

    fast();
   int t=1;
   //cin>>t;
   while (t--)
       solve();


    return 0;
}

void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
#endif
}