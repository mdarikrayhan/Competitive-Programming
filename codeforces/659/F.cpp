// LUOGU_RID: 159333119
//Author:Leftist_G / Shunpower
//Spade Su & Xiao Bao
//Hey Left
//Just enjoy the loneliness
//Open a personal party always stay
#include <bits/stdc++.h>
#define ET return 0
#define fi first
#define se second
#define mp make_pair
#define pb emplace_back
#define ll long long
#define ull unsigned long long
#define inf INT_MAX
#define uinf INT_MIN
#define pii pair<int,int>
#define pll pair<ll,ll>
#define debug puts("--------Chery AK IOI--------");
#define Yes cout<<"Yes"<<endl;
#define No cout<<"No"<<endl;
#define pt puts("")
#define fr1(i,a,b) for(int i=a;i<=b;i++)
#define fr2(i,a,b) for(int i=a;i>=b;i--)
#define fv(i,p) for(int i=0;i<p.size();i++)
#define ld long double
#define il inline
#define ptc putchar
using namespace std;
const int N=1e3+10;
namespace Shun{
    int lowbit(int x){
        return x&-x;
    }
    template <typename T>
    inline void read(T &x){
       T s=0,w=1;
       char ch=getchar();
       while(ch<'0'||ch>'9'){
            if(ch=='-'){
                w=-1;
            }
            ch=getchar();
        }
       while(ch>='0'&&ch<='9'){
            s=s*10+ch-'0';
            ch=getchar();
       }
       x=s*w;
    }
    template <typename T>
    inline void write(T x){
        if(x<0){
            putchar('-');
            x=-x;
        }
        if(x>9){
            write(x/10);
        }
        putchar(x%10+'0');
    }
}
using namespace Shun;
int n,m;
ll k;
int c[N][N];
bool vis[N][N];
vector <int> lsh;
int bac[N*N];
int tot;
vector <pii> pos[N*N];
int got(int x,int y){
    return (x-1)*m+y;
}
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
int siz[N*N];
int fa[N*N];
int finder(int x){
    if(fa[x]!=x) fa[x]=finder(fa[x]);
    return fa[x];
}
void merge(int x,int y){
    x=finder(x),y=finder(y);
    if(x==y) return;
    if(siz[x]>siz[y]) swap(x,y);
    siz[y]+=siz[x];
    fa[x]=y;
}
int main(){
#ifdef Griffin
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    fr1(i,1,n) fr1(j,1,m) cin>>c[i][j],lsh.pb(c[i][j]);
    fr1(i,1,n) fr1(j,1,m) fa[got(i,j)]=got(i,j),siz[got(i,j)]=1;
    sort(lsh.begin(),lsh.end());
    lsh.resize(unique(lsh.begin(),lsh.end())-lsh.begin());
    tot=lsh.size();
    fr1(i,0,(int)lsh.size()-1) bac[i+1]=lsh[i];
    fr1(i,1,n){
        fr1(j,1,m) c[i][j]=lower_bound(lsh.begin(),lsh.end(),c[i][j])-lsh.begin()+1;
    }
    fr1(i,1,n) fr1(j,1,m) pos[c[i][j]].pb(mp(i,j));
    fr2(i,tot,1){
        for(auto j:pos[i]){
            fr1(k,0,3){
                int nx=j.fi+dx[k],ny=j.se+dy[k];
                if(nx>0&&ny>0&&nx<=n&&ny<=m&&c[nx][ny]>=i) merge(got(nx,ny),got(j.fi,j.se));
            }
        }
        if(k%bac[i]!=0) continue;
        ll cnt=k/bac[i];
        // cout<<bac[i]<<" "<<cnt<<endl;
        for(auto j:pos[i]){
            int ance=finder(got(j.fi,j.se));
            // cout<<j.fi<<" "<<j.se<<" "<<siz[ance]<<endl;
            if(siz[ance]>=cnt){
                cout<<"YES\n";
                fr1(x,1,n) fr1(y,1,m) c[x][y]=0;
                queue <pii> q;
                q.push(mp(j.fi,j.se));
                vis[j.fi][j.se]=1;
                // cout<<j.fi<<" "<<j.se<<endl;
                while(cnt){
                    // cout<<q.front().fi<<" "<<q.front().se<<endl;
                    pii idx=q.front();
                    c[idx.fi][idx.se]=bac[i];
                    // vis[idx.fi][idx.se]=1;
                    q.pop();
                    cnt--;
                    // if(!cnt) break;
                    fr1(k,0,3){
                        int nx=idx.fi+dx[k],ny=idx.se+dy[k];
                        // cout<<nx<<" "<<
                        if(nx>0&&ny>0&&nx<=n&&ny<=m&&!vis[nx][ny]&&finder(got(nx,ny))==ance){
                            q.push(mp(nx,ny));
                            vis[nx][ny]=1;
                        }
                    }
                }
                fr1(x,1,n){
                    fr1(y,1,m) cout<<c[x][y]<<" ";
                    cout<<'\n';
                }
                ET;
            }
        }
        // cout<<"!!!"<<endl;
    }
    // cout<<"???"<<endl;
    cout<<"NO"<<endl;
    ET;
}
//ETERNAL LOVE FOR Zhang Junhao, Mu Zhicheng and Zuo Hang.
//ALL FOR Zhang Junhao.