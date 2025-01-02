// LUOGU_RID: 159698774
//A tree without skin will surely die.
//A man without face is invincible.
#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define per(i,j,k) for (int i=j;i>=k;--i)
int const N=2e5+10;
int n,m,k,l[N],r[N],lg[N],dp[N][15];
vector<int>V[N];
struct ST_Table{
    int mx[20][N];
    inline void add(int pl,int y){
        ++pl,mx[0][pl]=y;
        rep(i,1,19){
            if ((1<<i)>pl) break;
            mx[i][pl]=max(mx[i-1][pl],mx[i-1][pl-(1<<(i-1))]);
        }
    }
    inline int getmax(int l,int r){
        ++l,++r;
        int k=lg[r-l+1];
        return max(mx[k][r],mx[k][l+(1<<k)-1]);
    }
}ST[11];
void solve(){
    cin>>n>>m>>k;
    rep(i,2,N-1) lg[i]=lg[i>>1]+1;
    rep(i,0,n) rep(j,0,k) dp[i][j]=-2e9;
    rep(i,0,n) V[i].clear();
    rep(i,1,m) cin>>l[i]>>r[i],V[l[i]].push_back(r[i]);
    dp[0][0]=0,ST[0].add(0,0);
    multiset< pair<int,int> >s;
    multiset<int>Rset;
    rep(i,1,n){
        while (s.size() && s.begin()->first<i)
            Rset.erase(Rset.find(s.begin()->second)),s.erase(s.begin());
        for (auto it:V[i])
            s.insert({it,i}),Rset.insert(i);
        vector< pair<int,int> >point;
        vector<int>Add;
        int g=i-1,val=0;
        rep(i,0,k){
            if (!Rset.size()){point.push_back({0,g});break;}
            Add.push_back(*(--Rset.end())),
            point.push_back({*(--Rset.end()),g});
            g=min(g,*(--Rset.end())-1),Rset.erase(--Rset.end());
        }
        for (auto i:Add) Rset.insert(i);
        for (auto it:point){
            if (it.first<=it.second){
                rep(d,val,k) dp[i][d]=max(dp[i][d],ST[d-val].getmax(it.first,it.second)+1);
            }
            ++val;
        }
        rep(j,0,k) ST[j].add(i,dp[i][j]);
    }
    int ans=0;
    rep(j,1,n) rep(i,0,k) ans=max(ans,dp[j][i]);
    cout<<ans<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}