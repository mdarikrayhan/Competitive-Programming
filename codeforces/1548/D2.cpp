#include "bits/stdc++.h"
#ifdef DEBUG
#include "PrettyDebug.hpp"
#else
#define debug(...) [](){}()
#define debuga(...) [](){}()
#endif
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Rev(i,a,b) for(int i=a;i>=b;i--)
#define Fin(file) freopen(file,"r",stdin)
#define Fout(file) freopen(file,"w",stdout)
using namespace std; typedef long long ll;
constexpr int N=6e3+5;
int n,X[N],Y[N],G[N][N];
signed main(){
    atexit([](){cerr<<"Time = "<<clock()<<" ms"<<endl;});
    cin>>n; For(i,1,n) cin>>X[i]>>Y[i];
    For(i,1,n) For(j,i+1,n) G[i][j]=G[j][i]=__gcd(abs(X[i]-X[j]),abs(Y[i]-Y[j]))%4;
    ll ans1=0,ans2=0;
    For(u,1,n){
        int cnt[4][4][4]={0}; For(i,1,n) if(i!=u) cnt[X[i]%4][Y[i]%4][G[u][i]]++;
        For(x1,0,3) For(y1,0,3) For(t1,0,3) if(cnt[x1][y1][t1]) {
            For(x2,0,3) For(y2,0,3) For(t2,0,3) if(cnt[x2][y2][t2]) {
                if(((x1-x2)|(y1-y2))&1) continue;
                int flg1=((x1-X[u])|(y1-Y[u]))&1;
                int flg2=((x2-X[u])|(y2-Y[u]))&1;
                if(flg1!=flg2) continue;
                int t0=__gcd(abs(x1-x2),abs(y1-y2));
                if(((t0+t1+t2)%4==0)!=((1ll*X[u]*(y1-y2)+1ll*x1*(y2-Y[u])+1ll*x2*(Y[u]-y1))%4==0)) continue;
                (flg1?ans2:ans1)+=1ll*cnt[x1][y1][t1]*cnt[x2][y2][t2];
                if(x1==x2&&y1==y2&&t1==t2) (flg1?ans2:ans1)-=cnt[x1][y1][t1];
            }
        }
    }
    debug(ans1,ans2);
    cout<<ans1/6+ans2/2<<'\n';
    return 0;
}

// CONTINUE, NON-STOPPING, FOR CHARLIEY
// START TYPING IF YOU DON'T KNOW WHAT TO DO
// STOP TYPING IF YOU DON'T KNOW WHAT YOU'RE DOING

// Started Coding On: May 08 Wed, 20 : 41 : 34