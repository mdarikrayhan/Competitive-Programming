// LUOGU_RID: 160634321
#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rof(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int Maxn=3e5,Mod=1e9+7,i6=(Mod+1)/6;

inline int Pow(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1) res=1ll*res*x%Mod;
        x=1ll*x*x%Mod,y>>=1;
    }
    return res;
}

int n,m,a[Maxn+5];

inline int C(int x) {return 1ll*x*(x-1)%Mod*(x-2)%Mod*i6%Mod;}
inline void Solve()
{
    cin>>n>>m; For(i,1,n) cin>>a[i]; sort(a+1,a+n+1);
    if(n==1) {puts("0"); return;}
    int c=1ll*n*Pow(m,Mod-2)%Mod*C(m+1)%Mod;
    For(i,2,n)
    {
        int d=a[i]-a[i-1];
        c=(c-1ll*n*Pow(m,Mod-2)%Mod*C(d+1)%Mod+Mod)%Mod;
    } int d=m-a[n]+a[1];
    c=(c-1ll*n*Pow(m,Mod-2)%Mod*C(d+1)%Mod+Mod)%Mod;
    cout<<c<<endl;
}

int main()
{
    // freopen("1.in","r",stdin);

    int T; cin>>T;
    while(T--) Solve();
    return 0;
}