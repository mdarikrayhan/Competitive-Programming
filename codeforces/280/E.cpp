// LUOGU_RID: 160005499
//A tree without skin will surely die.
//A man without face is invincible.
#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define per(i,j,k) for (int i=j;i>=k;--i)
int const N=1e5+10;
int n,q,a,b,x[N],tot,u;
double const inf=1e18;
double ans[N],las;
pair<double,double>points[N];
void solve(){
    cin>>n>>q>>a>>b;
    rep(i,1,n){
        cin>>x[i];
        if (i==1){
            points[tot++]=make_pair(1,2*(1-x[i]));
            points[tot++]=make_pair(inf,2*(inf-x[i]));
        }else{
            per(j,tot-1,u+1) points[j+2]=points[j];
            ++u,tot+=2,
            points[u]=make_pair(las,0),points[u+1]=make_pair(las,0);
            rep(j,0,u) points[j].first+=a;
            rep(j,u+1,tot-1) points[j].first+=b;
            rep(j,0,tot-1) points[j].second+=2*(points[j].first-x[i]);
        }
        if (points[0].second>=0) ans[i]=points[0].first,u=-1;
        else{
            for (u=0;u<tot;++u)
                if (points[u].second<=0 && points[u+1].second>0) break;
            ans[i]=points[u].first-points[u].second/(points[u+1].second-points[u].second)*(points[u+1].first-points[u].first);
        }
        las=ans[i];
    }
    ans[n]=min(ans[n],1.0*q);
    per(i,n,2) ans[i-1]=min(ans[i-1],ans[i]-a),ans[i-1]=max(ans[i-1],ans[i]-b);
    double an=0;
    cout<<fixed<<setprecision(12);
    rep(i,1,n) cout<<ans[i]<<' ',an+=(ans[i]-x[i])*(ans[i]-x[i]);
    cout<<'\n'<<an<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}