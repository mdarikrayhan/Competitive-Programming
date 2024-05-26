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
constexpr int N=1E5+10;
constexpr int inf=1E9;
constexpr int p=998244353;
int qpow(int x,int n){int y=1;for(;n;n>>=1,x=1LL*x*x%p)if(n&1)y=1LL*y*x%p;return y;}
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename U,typename V>U min(U x,V y){return x<y?x:y;}
template<typename U,typename V>U max(U x,V y){return x>y?x:y;}
template<typename U,typename ...V>U min(U x,V... y){return min(x,min(y...));}
template<typename U,typename ...V>U max(U x,V... y){return max(x,max(y...));}
template<typename U,typename V>bool cmin(U &x,V y){return x>y?x=y,true:false;}
template<typename U,typename V>bool cmax(U &x,V y){return x<y?x=y,true:false;}

char a[N],b[N];
int f[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a,b;
    cin>>a>>b;
    int n=a.size(),m=b.size();
    a='\0'+a;
    b='\0'+b;
    for(int i=1,j=1;i<=n;++i)
    {
        if(a[i]==b[j])++j;
        f[i]=j-1;
    }
    int mx=0,o;
    for(int i=n,j=0;i>=0;--i)
    {
        if(cmax(mx,j+f[i]))o=j;
        if(a[i]==b[m-j])++j;
    }
    if(!mx)return cout<<"-\n",0;
    cmin(mx,m);
    for(int i=1;i<=mx-o;++i)cout<<b[i];
    for(int i=m-o+1;i<=m;++i)cout<<b[i];
    cout<<'\n';
    return 0;
}
