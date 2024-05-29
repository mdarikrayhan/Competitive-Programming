// LUOGU_RID: 159157938
#include<bits/stdc++.h>

using namespace std;
int n,m;
int x[100005],y[100005];
int Fa[100005];
vector<pair<long double,int> >son[100005];
vector<int>S[100005];
int siz[100005];
struct edge{
    int obj,last;
}e[200005];
int head[100005],g;
void link(int u,int v){
    e[++g].obj=v;
    e[g].last=head[u];
    head[u]=g;
}
const long double pi=acos(-1);
long double calc(int u,int v){
    long double X=x[v]-x[u],Y=y[v]-y[u];
    if(!X)return (Y>0?pi/2:pi/2*3);
    if(!Y)return (X>0?0:pi);
    long double nh=atan(Y/X);
    if(nh<0)nh+=pi;
    return (Y<0?nh+pi:nh);
}
bool pd[100005];
void dfs(int u,int fa){
    Fa[u]=fa;siz[u]=1;pd[u]=true;
    for(int i=head[u];i;i=e[i].last){
        int v=e[i].obj;
        if(pd[v])continue;
        dfs(v,u);//cerr<<u<<"!!"<<v<<endl;
        son[u].push_back({calc(u,v),v});siz[u]+=siz[v];
    }
}
int id[100005],k;
bool check(int u,int v,int w,int t){
    long double ag1=calc(v,u),ag2=calc(v,w),ag3=calc(v,t);
    if(ag1<=ag2)return ag1<=ag3&&ag3<=ag2;
    return !(ag3<ag1&&ag3>ag2);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        link(u,v);
        link(v,u);
    }
    int root=1;x[0]=-1e9;y[0]=-1e9;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&x[i],&y[i]);
        if(make_pair(x[i],y[i])<make_pair(x[root],y[root]))root=i;
    }
    dfs(root,0);
    for(int i=1;i<=n;i++){
        sort(son[i].begin(),son[i].end());
        S[i].resize(son[i].size());
        for(int j=0;j<S[i].size();j++){
            S[i][j]=siz[son[i][j].second];
            if(j)S[i][j]+=S[i][j-1];
        }
    }
    int q;
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        scanf("%d",&k);
        for(int j=1;j<=k;j++)scanf("%d",&id[j]);
        __int128 sum=0;
        for(int j=2;j<k;j++)sum+=1ll*(x[id[j]]-x[id[1]])*(y[id[j+1]]-y[id[1]])-1ll*(x[id[j+1]]-x[id[1]])*(y[id[j]]-y[id[1]]);
        if(sum<=0)reverse(id+1,id+1+k);
        id[0]=id[k],id[k+1]=id[1];
        int ans=0;
        for(int j=1;j<=k;j++){
            int u=id[j];
            // for(auto [ss,v]:son[u])
                // if(!check(id[j+1],id[j],id[j-1],v))ans-=siz[v];
            long double ag1=calc(id[j],id[j+1]),ag2=calc(id[j],id[j-1]);
            if(ag1<=ag2){
                int l=lower_bound(son[u].begin(),son[u].end(),make_pair(ag1,0))-son[u].begin(),r=lower_bound(son[u].begin(),son[u].end(),make_pair(ag2,n+1))-son[u].begin();
                if(l==r)ans-=siz[u]-1;
                else {
                    if(l>0)ans-=S[u][l-1];
                    if(r<son[u].size())ans-=siz[u]-1-(r?S[u][r-1]:0);
                }
            }
            else {
                int l=lower_bound(son[u].begin(),son[u].end(),make_pair(ag2,n+1))-son[u].begin(),r=lower_bound(son[u].begin(),son[u].end(),make_pair(ag1,0))-son[u].begin();
                if(r>l)ans-=S[u][r-1]-(l!=0?S[u][l-1]:0);
            }
            // cerr<<id[j]<<" "<<id[j-1]<<" "<<id[j+1]<<" "<<Fa[u]<<endl;
            if(!Fa[u]||!check(id[j+1],id[j],id[j-1],Fa[u]))ans+=siz[u];
        }
        printf("%d\n",ans);
    }
    return 0;
}
