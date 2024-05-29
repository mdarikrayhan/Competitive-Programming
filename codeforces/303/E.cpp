// LUOGU_RID: 160605797
#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define min amin
#define max amax
#define eb emplace_back
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int N=90;
const int inf=1E9;
const int p=998244353;
void add(int &x,int y){x-=(x+=y)<p?0:p;}
void sub(int &x,int y){x+=(x-=y)<0?p:0;}
int qpow(int x,int n){int y=1;for(;n;n>>=1,x=1LL*x*x%p)if(n&1)y=1LL*y*x%p;return y;}
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename U,typename V>U min(U x,V y){return x<y?x:y;}
template<typename U,typename V>U max(U x,V y){return x>y?x:y;}
template<typename U,typename ...V>U min(U x,V... y){return min(x,min(y...));}
template<typename U,typename ...V>U max(U x,V... y){return max(x,max(y...));}
template<typename U,typename V>bool cmin(U &x,V y){return x>y?x=y,true:false;}
template<typename U,typename V>bool cmax(U &x,V y){return x<y?x=y,true:false;}

int L[N],R[N],q[N<<1],s[8];
double A[N],B[N],C[N],f[N][N][N],g[8][N][N],dp[N];
double calc(int i,int x)
{
    if(L[i]>=x)return 0;
    if(R[i]<=x)return 1;
    return 1.*(x-L[i])/(R[i]-L[i]);
}
void cp(int d)
{
    int t=max(s[d-1],s[d]);
    for(int i=0;i<=t;++i)
        for(int j=t-i;j>=0;--j)
            g[d][i][j]=g[d-1][i][j];
    s[d]=s[d-1];
}
void ins(int d,int x)
{
    for(int i=s[d];i>=0;--i)
        for(int j=s[d]-i;j>=0;--j)
        {
            g[d][i][j+1]+=g[d][i][j]*B[x];
            g[d][i+1][j]+=g[d][i][j]*A[x];
            g[d][i][j]*=C[x];
        }
    ++s[d];
}
void cdq(int d,int l,int r)
{
    if(l==r)
    {
        for(int i=0;i<=s[d];++i)
            for(int j=s[d]-i;j>=0;--j)
                f[l][i][j]+=g[d][i][j]*B[l];
        return;
    }
    int m=l+r>>1;
    ++d;
    cp(d);
    for(int i=m+1;i<=r;++i)ins(d,i);
    cdq(d,l,m);
    cp(d);
    for(int i=l;i<=m;++i)ins(d,i);
    cdq(d,m+1,r);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m=0;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>L[i]>>R[i];
        q[++m]=L[i];
        q[++m]=R[i];
    }
    sort(q+1,q+m+1);
    m=unique(q+1,q+m+1)-q-1;
    g[0][0][0]=1;
    for(int i=1;i<m;++i)
    {
        for(int j=1;j<=n;++j)
        {
            double x=calc(j,q[i]),y=calc(j,q[i+1]);
            A[j]=x;
            B[j]=y-x;
            C[j]=1-y;
        }
        cdq(0,1,n);
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<n;++j)
            for(int k=n-1-j;k>=0;--k)
            {
                double x=f[i][j][k]/(k+1);
                dp[j+1]+=x;
                dp[j+k+2]-=x;
            }
        double res=0;
        for(int j=1;j<=n;++j)
        {
            res+=dp[j];
            cout<<fixed<<setprecision(8)<<res<<' ';
            dp[j]=0;
        }
        cout<<'\n';
    }
    return 0;
}
