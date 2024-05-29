// LUOGU_RID: 160591724
#include <bits/stdc++.h>
#define F(i,x,y) for(int i=(x);i<=(y);i++)
#define DF(i,x,y) for(int i=(x);i>=(y);i--)
#define ms(x,y) memset(x,y,sizeof(x))
#define SZ(x) (int)x.size()-1
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int,int> pii;
template<typename T> void chkmax(T &x,T y){ x=max(x,y);}
template<typename T> void chkmin(T &x,T y){ x=min(x,y);}
template<typename T> void read(T &FF){
    FF=0;int RR=1;char ch=getchar();
    for(;!isdigit(ch);ch=getchar()) if(ch=='-') RR=-1;
    for(;isdigit(ch);ch=getchar()) FF=(FF<<1)+(FF<<3)+ch-48;
    FF*=RR;
}
const int N=1010,P=1e9+7;
int n,a[N],rv[N],ps[N];
int ans,f[N][N];
inline void inc(int &x,int y){ x+=y;if(x>=P) x-=P;}
void tag(int &cnt,int i){ rv[cnt]=i,ps[i]=cnt,cnt++;}
bool in(int l,int r,int p){
    if(l<=r) return l<=p&&p<=r;
    else return p>=l||p<=r;
}
bool chk(int l,int r,int p){
    if(p<n/2) return !in(l,r,ps[rv[p]-1])&&(rv[p]==n||!in(l,r,ps[rv[p]+1]));//even
    else return (rv[p]==1||in(l,r,ps[rv[p]-1]))&&((rv[p]==n||in(l,r,ps[rv[p]+1])));//odd
}
void solve(){
    int cnt=0;
    for(int i=n-(n&1);i>=1;i-=2) tag(cnt,i);
    for(int i=1;i<=n;i+=2) tag(cnt,i);
    F(i,0,n-1) F(j,0,n-1) f[i][j]=0;
    F(i,0,n/2-1) if(a[rv[i]]==1||a[rv[i]]==-1) f[i][i]=1;
    F(len,2,n)
        F(l,0,n-1){
            int r=(l+len-1)%n;
            if((a[rv[l]]==len||a[rv[l]]==-1)&&chk(l,r,l)){
                inc(f[l][r],f[(l+1)%n][r]);
                if(len==n&&l>=n/2) inc(ans,f[l][r]);
            }
            if((a[rv[r]]==len||a[rv[r]]==-1)&&chk(l,r,r)) inc(f[l][r],f[l][(r+n-1)%n]);
        }
}
void work(){
    read(n);ans=0;
    F(i,1,n) read(a[i]);
    solve();
    F(i,1,n) if(a[i]!=-1) a[i]=n-a[i]+1;
    solve();
    printf("%d\n",ans);
}
int main(){
    int T;read(T);
    while(T--) work();
    return 0;
}
