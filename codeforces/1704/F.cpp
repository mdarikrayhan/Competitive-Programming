// LUOGU_RID: 160133317
//A tree without skin will surely die.
//A man without face is invincible.
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mid ((l+r)>>1)
#define lowbit(x) (x&-x)
#define all(x) (x).begin(),(x).end()
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define per(i,j,k) for (int i=j;i>=k;--i)
#define Tim ((double)clock()/CLOCKS_PER_SEC)
int const N=5e5+10;
int sg[N];
void solve(){
    int n;string s;
    cin>>n>>s,s=" "+s;
    int cntR=0,cntB=0;
    rep(i,1,n) cntR+=(s[i]=='R'),cntB+=(s[i]=='B');
    if (cntR>cntB) return cout<<"Alice\n",void();
    if (cntB>cntR) return cout<<"Bob\n",void();
    int smsg=0,len=0;
    rep(i,1,n){
        if (s[i]==s[i-1]) smsg^=sg[len],len=0;
        ++len;
    }
    smsg^=sg[len];
    if (smsg) cout<<"Alice\n";
    else cout<<"Bob\n";
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    rep(i,2,100){
        map<int,int>vis;
        rep(j,1,i-1) vis[sg[j-1]^sg[i-j-1]]=1;
        while (vis[sg[i]]) ++sg[i];
    }
    rep(i,101,N-1) sg[i]=sg[i-34];
    int t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}