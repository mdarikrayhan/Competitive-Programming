#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
typedef long long LL;
struct pre_liner_base{
    LL p[32];int pos[32];
    void init(){memset(p,0,sizeof p);memset(pos,0,sizeof pos);}
    void insert(pre_liner_base A,int w,LL x){
        *this=A;
        for(int i=30;i>=0;i--){
            if((x>>i)&1){
                if(!p[i]){  p[i]=x;  pos[i]=w;return;}
                else if(pos[i]<w){ swap(pos[i],w);swap(x,p[i]);}
                x^=p[i];
            }
        }
    }
    LL ask(int l){
        LL ans=0;
        for(int i=30;i>=0;i--){
            if(p[i]&&(pos[i]>=l))ans=max(ans,ans^p[i]);
        }
        return ans;
    }
}a[N];

void solve(){
    int n;cin>>n;
    a[0].init();
    for(int i=1;i<=n;i++){
        LL x;cin>>x;
        a[i].insert(a[i-1],i,x);
    }
    int q;cin>>q;
    while(q--){
        int l,r;cin>>l>>r;
        cout<<a[r].ask(l)<<"\n";
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
