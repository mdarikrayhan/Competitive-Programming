// LUOGU_RID: 160091356
#include<bits/stdc++.h>
#define ll long long
#define mod 998244353
#define G 3
#define N (1<<16)
#define K 16
using namespace std;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0' || ch>'9')f=(ch=='-'?-1:f),ch=getchar();
    while(ch>='0' && ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return x*f;
}
void write(int x){
    if(x<0)x=-x,putchar('-');
    if(x/10)write(x/10);
    putchar(x%10+'0');
}
int add(int x,int y){return (x+y>mod?x+y-mod:x+y);}
int dec(int x,int y){return (x-y<0?x-y+mod:x-y);}
int mul(int x,int y){return (x*1ll*y%mod);}
int qp(int x,int y=mod-2){
    int ans=1;while(y){if(y&1)ans=mul(ans,x);x=mul(x,x);y>>=1;}return ans;
}
void FMT(int *f,int L){
    for(int w=2,mid=1;w<=L;w<<=1,mid<<=1){
        for(int j=0;j<L;j+=w){
            for(int k=j;k<j+mid;k++)f[k]=dec(f[k],f[k+mid]);
        }
    }
}
int rev[K][N];
void prework(){
    for(int i=1;i<K;i++){
        for(int j=0;j<(1<<i);j++){
            rev[i][j]=(rev[i][j>>1]>>1)+(j&1?(1<<(i-1)):0);
        }
    }
}
void NTT(vector<int> &f,int opt,int L){
    int d=__lg(L);
    for(int i=1;i<L;i++)if(rev[d][i]<i)swap(f[i],f[rev[d][i]]);
    for(int len=2,mid=1;len<=L;len<<=1,mid<<=1){
        int wd=qp(G,(mod-1)/len);wd=(!opt?qp(wd):wd);
        for(int j=0;j<L;j+=len){
            for(int k=j,w=1;k<j+mid;k++,w=mul(w,wd)){
                int x=f[k],y=mul(f[k+mid],w);
                f[k]=add(x,y);f[k+mid]=dec(x,y);
            }
        }
    }
    if(opt)return;int w=qp(L);
    for(int i=0;i<L;i++)f[i]=mul(f[i],w);
}
int n;
vector<int> Mul(vector<int> a,vector<int> b){
    int L=a.size()*2;
    for(int i=1;i<=L/2;i++)a.push_back(0),b.push_back(0);
    NTT(a,1,L);NTT(b,1,L);vector<int> res(L);
    for(int i=0;i<L;i++)res[i]=mul(a[i],b[i]);
    NTT(res,0,L);return res;
}
void solve(char *p,int *g){
    vector<vector<vector<int> > > f[K]; 
    //f[i][S][j][k] i floor   S set   j mod 2^{n-i+1}=j   k sum=k
    for(int i=1;i<(1<<(n+1));i++)if(i<rev[n+1][i])swap(p[i],p[rev[n+1][i]]);
    for(int i=0;i<=n+1;i++){
        f[i].resize((1<<i));
        for(int S=0;S<(1<<i);S++){
            f[i][S].resize((1<<(n-i+1)));
            for(int j=0;j<(1<<(n-i+1));j++)f[i][S][j].resize((1<<(i+1-__builtin_popcount(S))));
        }
    }
    for(int j=0;j<(1<<(n+1));j++){
        if(p[j]!='0')f[0][0][j][1]=1;
        if(p[j]!='1')f[0][0][j][0]=1;
    }
    for(int i=1;i<=(n+1);i++){
        for(int S=0;S<(1<<i);S++){
            for(int j=0;j<(1<<(n+1-i));j++){
                int ls=j*2,rs=j*2+1,lim=(1<<((i+1)-__builtin_popcount(S)));
                if(!(S&1)){
                    f[i][S][j]=Mul(f[i-1][S>>1][ls],f[i-1][S>>1][rs]);
                    //for(int k=0;k<lim;k++)cerr<<i<<' '<<S<<' '<<j<<' '<<k<<' '<<f[i][S][j][k]<<endl;
                    continue;
                }
                for(int k=0;k<lim;k++)
                    f[i][S][j][k]=mul(f[i-1][S>>1][ls][k],f[i-1][S>>1][rs][k]);
                
                //for(int k=0;k<lim;k++)cerr<<i<<' '<<S<<' '<<j<<' '<<k<<' '<<f[i][S][j][k]<<endl;
            }
        }
    }
    for(int S=0;S<(1<<(n+1))-1;S++)g[S]=f[n+1][S][0][1<<(n-__builtin_popcount(S))];
    for(int S=1;S<(1<<(n+1));S++)if(rev[n+1][S]<S)swap(g[rev[n+1][S]],g[S]);
}
char s[N],t[N];
int g[N],h[N];
int main(){
    #ifdef EAST_CLOUD
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    #endif
    n=read();scanf("%s",s);scanf("%s",t);prework();reverse(t,t+(1<<(n+1)));
    solve(s,g);solve(t,h);
    FMT(g,(1<<(n+1)));int res=0,S=(1<<(n+1))-1;
    //for(int i=0;i<S;i++)cerr<<g[i]<<' '<<h[S^i]<<endl;
    for(int i=0;i<(1<<(n+1));i++)res=add(res,mul(g[i],h[S^i]));
    write(res);
}
