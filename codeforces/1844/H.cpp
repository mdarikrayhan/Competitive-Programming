// LUOGU_RID: 160068536
#include<bits/stdc++.h>
#define LL long long
#define LLL __int128
#define uint unsigned
#define ldb long double
#define uLL unsigned long long
using namespace std;
const int N=3e5+5,P=998244353;
int n,m,Rq;
int frc[N],ivf[N],inv[N];
int fd[N],sz[N],ans[N*2],cnt[N*2][3];
inline int qpow(int x,int y,int z=1){
    for(;y;(y>>=1)&&(x=(LL)x*x%P))if(y&1)z=(LL)z*x%P;return z;
}
inline int find(const int&x){
    return fd[x]==x?x:fd[x]=find(fd[x]);
}
inline void init(const int&n){
    frc[0]=1;
    for(int i=1;i<=n;++i)frc[i]=1ll*frc[i-1]*i%P;
    ivf[n]=qpow(frc[n],P-2);
    for(int i=n;i>=1;--i)ivf[i-1]=1ll*ivf[i]*i%P;
    for(int i=1;i<=n;++i)inv[i]=1ll*ivf[i]*frc[i-1]%P;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n,Rq=n+1;
    init(n);
    cnt[0][0]=0,cnt[0][1]=n,cnt[0][2]=0;
    for(int i=1;i<=n;++i)fd[i]=i,sz[i]=1;
    for(int i=1;i<=n;++i){
        cnt[i][0]=cnt[i-1][0],
        cnt[i][1]=cnt[i-1][1],
        cnt[i][2]=cnt[i-1][2];
        int x,y;cin>>x>>y;
        if(find(x)!=find(y)){
            --cnt[i][sz[find(x)]%3];
            --cnt[i][sz[find(y)]%3];
            sz[find(y)]+=sz[find(x)];
            fd[find(x)]=find(y);
            ++cnt[i][sz[find(y)]%3];
        }
        else if(sz[find(x)]%3)Rq=min(Rq,i);
        else --cnt[i][0];
    }
    for(m=n;cnt[m][1]+cnt[m][2];){
        ++m;
        cnt[m][0]=cnt[m-1][0],cnt[m][1]=cnt[m-1][1],cnt[m][2]=cnt[m-1][2];
        int x=cnt[m][1]?1:2;--cnt[m][x];
        int y=cnt[m][1]?1:2;--cnt[m][y];
        ++cnt[m][(x+y)%3];
    }
    int x=1,y=1,Sx=1,Sy=8;
    const auto F=[&](){
        const int Tx=(Sy-(y+1ll)*(x+y+1)%P*Sx)%P*inv[x]%P;
        const int Ty=(x*(x+y+2ll)%P*Tx+(y+2ll)*Sy)%P;
        --x,y+=2,Sx=Tx,Sy=Ty;
    };
    const auto G=[&](){
        const int Tx=(Sy-(x+1ll)*(x+y+1)%P*Sx)%P*inv[y]%P;
        const int Ty=(y*(x+y+2ll)%P*Tx+(x+2ll)*Sy)%P;
        x+=2,--y,Sx=Tx,Sy=Ty;
    };
    for(int i=m;i>=1;--i){
        const int a=cnt[i][1],b=cnt[i][2],c=cnt[i][0];
        if(!a&&!b)ans[i]=1ll*frc[a+b+c]*ivf[a+b]%P;
        else{
            if(a==x-1&&b==y+2)F();
            else if(a==x+2&&b==y-1)G();
            else if(a==x+1&&b==y+1)if(x)F(),G();else G(),F();
            ans[i]=1ll*Sx*frc[a+b+c]%P*ivf[a+b]%P;
        }
    }
    for(int i=1;i<=n;++i)cout<<(i>=Rq?0:ans[i]<0?ans[i]+P:ans[i])<<'\n';
    return 0;
}
/*
*/