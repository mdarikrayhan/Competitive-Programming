#include<bits/stdc++.h>
using namespace std;
#define rd(i,n) for(int i=0;i<n;i++)
#define rp(i,n) for(int i=1;i<=n;i++)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=b;i>=a;i--)
#define st string
#define vt vector
#define pb push_back
//#define int long long
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int N=2005;
int n,m,v[N<<1],l[N],r[N],lt[N],rt[N];
int vr[N<<1],vid[N<<1],deg[N],L[N],R[N];
int dp[N][N][2][2],sz[N];
int ta[N][N][2][2],tb[N][N][2][2];
int tsz[N],Lid[N],Rid[N],La[N],Ra[N];
int f[2][2][N][N],fr[2][2][N][N],fb[2][2][N][N];
vt<int>G[N];
inline void upd(int &x,int y){
    x=max(x,y);
}
inline void solve(int x,int sa,int sb){
    int m=G[x].size(),mt=sz[x]+1;
    rd(a,2)rd(b,2){
        int cur=1;
        rep(i,0,m){
            rep(j,0,cur)f[a][b][i][j]=-1e9;
            if(i!=m)cur+=sz[G[x][i]]+1,cur=min(cur,mt);
        }
    }
    f[1][1][0][1]=l[G[x][0]]-l[x];
    if(sa)f[0][1][0][0]=l[G[x][0]]-l[x];
    f[0][0][0][0]=0;
    int cur=1;
    rep(i,1,m){
        int td=sz[G[x][i-1]];
        rd(a,2)rep(j,0,cur)rep(t,0,td)rd(b,2){
            rd(s,2){
                if(j+t+s>mt)continue;
                int res=dp[G[x][i-1]][t][b][s];
                if(s)res+=(i==m?r[x]:l[G[x][i]])-r[G[x][i-1]];
                if(f[a][s][i][j+t+s]<f[a][b][i-1][j]+res){
                    f[a][s][i][j+t+s]=f[a][b][i-1][j]+res;
                    fr[a][s][i][j+t+s]=j;
                    fb[a][s][i][j+t+s]=b;
                }
            }
            if(sb&&i==m){
                if(j+t>mt)continue;
                int res=dp[G[x][i-1]][t][b][1];
                res+=r[x]-r[G[x][i-1]];
                if(f[a][0][i][j+t]<f[a][b][i-1][j]+res){
                    f[a][0][i][j+t]=f[a][b][i-1][j]+res;
                    fr[a][0][i][j+t]=j;
                    fb[a][0][i][j+t]=b;
                }
            }
        }
        cur+=td+1;
        cur=min(cur,mt);
    }//左右的没有延申到下面去，怎么办
    rep(i,1,mt)rd(na,2)rd(nb,2){
        if(dp[x][i-1][sa][sb]<f[na][nb][m][i]){
            dp[x][i-1][sa][sb]=f[na][nb][m][i];
            ta[x][i-1][sa][sb]=na;
            tb[x][i-1][sa][sb]=nb;
        }
    }
}
inline void dfs(int x){
    sz[x]=1;
    for(auto i:G[x]){
        dfs(i);
        sz[x]+=sz[i];
    }
    int m=G[x].size(),mt=sz[x]+1;
    if(G[x].size()==0){
        rd(a,2)rd(b,2){
            dp[x][0][a][b]=r[x]-l[x];
            ta[x][0][a][b]=0;
            tb[x][0][a][b]=0;
        }
        rep(i,1,mt)rd(a,2)rd(b,2)dp[x][i][a][b]=-1e9;
        return;
    }
    rd(sa,2)rd(sb,2){
        solve(x,sa,sb);
    }
}
inline void rebuild(int x,int ct,int a,int b,int lid,int rid,vt<int>&v){
 //   cout<<x<<" "<<a<<" "<<b<<" "<<lid<<" "<<rid<<endl;
    int m=G[x].size();
    if(m==0){
        L[x]=l[x],R[x]=r[x];
        return;
    }
    solve(x,a,b);
    int na=ta[x][ct][a][b];
    int nb=tb[x][ct][a][b];
    ct++;
    v.pb(x);
    if(!na&&a)R[lid]=l[G[x][0]],Lid[G[x][0]]=lid,La[G[x][0]]=1;
    if(!nb&&b)L[rid]=r[G[x][m-1]],Rid[G[x][m-1]]=rid,Ra[G[x][m-1]]=1;
    per(i,1,m){
        int j=fr[na][nb][i][ct];
        int s=fb[na][nb][i][ct];
        // if(x==6){
        //     cout<<na<<" "<<nb<<" "<<i<<" "<<ct<<endl;
        // cout<<j<<" "<<s<<endl;
        // }
        if(nb){
            int cur=v.back();
            Rid[G[x][i-1]]=cur,Ra[G[x][i-1]]=1;
            if(i!=m)Lid[G[x][i]]=cur,La[G[x][i]]=1;
            tsz[G[x][i-1]]=ct-j-nb;
            L[cur]=r[G[x][i-1]];
            R[cur]=(i==m?r[x]:l[G[x][i]]);
            v.pop_back();
        }else tsz[G[x][i-1]]=ct-j;
        nb=s,ct=j;
    }
    if(na){
        int cur=v.back();
        Lid[G[x][0]]=cur,La[G[x][0]]=1;
        L[cur]=l[x];
        R[cur]=l[G[x][0]];
        v.pop_back();
    }
    rep(i,0,m-1){
        vt<int>nv;
        int y=G[x][i];
        rd(_,tsz[y]){
            int cur=v.back();
            nv.pb(cur);
            v.pop_back();
        }
        rebuild(y,tsz[y],La[y],Ra[y],Lid[y],Rid[y],nv);
    }
}
inline void check(int ans){
    int cnt=0;
    rp(i,n)cnt+=R[i]-L[i];
    if(cnt!=ans){
        cout<<"Length Wrong\n"<<" "<<cnt<<" "<<ans<<endl;;
        exit(1);
    }else cout<<"Accepted\n";
}
signed main(){
    // freopen("f.in","r",stdin);
    // freopen("f.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    rp(i,n)cin>>l[i]>>r[i];
    rp(i,n)v[++m]=l[i],v[++m]=r[i];
    sort(v+1,v+1+m);
    rp(i,n){
        lt[i]=lower_bound(v+1,v+1+m,l[i])-v;
        rt[i]=lower_bound(v+1,v+1+m,r[i])-v;
        vr[lt[i]]=rt[i],vid[lt[i]]=i;
    }
    rp(i,n)rep(j,lt[i]+1,rt[i])if(vid[j]){
        G[i].pb(vid[j]);
        deg[vid[j]]++,j=vr[j];
    }
    int ans=0;
    rp(i,n)if(!deg[i]){
        dfs(i);
        ans+=dp[i][0][0][0];
        vt<int>v;
        rebuild(i,0,0,0,0,0,v);
    }
    cout<<ans<<'\n';
    // int cnt=0;
    // rp(i,n)cnt+=R[i]-L[i];
  //  cout<<cnt<<'\n';
    rp(i,n)cout<<L[i]<<" "<<R[i]<<'\n';
  //  check(ans);
    // if(cnt!=ans)return 1;
    return 0;
}
//Rain Rain Rain