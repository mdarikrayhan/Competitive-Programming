// LUOGU_RID: 157082713
#include<bits/stdc++.h>
using namespace std;
constexpr int maxn=2e3+5,maxm=4e6+5;
int fir[maxn],to[maxm],val[maxm],nxt[maxm],tot=1;inline void addedge(int u,int v,int w){nxt[++tot]=fir[u],to[fir[u]=tot]=v,val[tot]=w;}
inline void add(int u,int v,int w){addedge(u,v,w),addedge(v,u,0);}
int s,t,dep[maxn];
bool bfs(){
    memset(dep,0,sizeof dep);
    queue<int>q;q.push(s);dep[s]=1;
    while(!q.empty()){
        int p=q.front();q.pop();
        for(int i=fir[p];i;i=nxt[i])if(!dep[to[i]]&&val[i]) dep[to[i]]=dep[p]+1,q.push(to[i]);
    }
    return dep[t];
}
int dfs(int p,int res){
    if(p==t) return res;
    int fl=0;
    for(int i=fir[p];i&&res;i=nxt[i]){
        if(dep[to[i]]==dep[p]+1&&val[i]){
            int z=dfs(to[i],min(res,val[i]));
            fl+=z,res-=z,val[i]-=z,val[i^1]+=z;
        }
    }
    if(fl==0) dep[p]=0;
    return fl;
}
inline int calc(){int ans=0;while(bfs())ans+=dfs(s,1e9);return ans;}
int n,a[1005],b[1005];
vector<int> x[1005],y[1005];
int id[1005][1005];
int cnt;
bool vis[2005],chs[2005];
int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    vector<int> A,B;
    cin>>n;for(int i=1;i<=n;i++) cin>>a[i]>>b[i],A.push_back(a[i]),B.push_back(b[i]);
    sort(A.begin(),A.end()),sort(B.begin(),B.end());
    A.erase(unique(A.begin(),A.end()),A.end()),B.erase(unique(B.begin(),B.end()),B.end());
    for(int i=1;i<=n;i++)a[i]=lower_bound(A.begin(),A.end(),a[i])-A.begin()+1,b[i]=lower_bound(B.begin(),B.end(),b[i])-B.begin()+1;
    for(int i=1;i<=n;i++) x[a[i]].push_back(b[i]),y[b[i]].push_back(a[i]);
    for(int i=1;i<=A.size();i++){
        sort(x[i].begin(),x[i].end());
        for(int j=0;j+1<x[i].size();j++){
            add(s,++cnt,1);
            for(int k=x[i][j]+1;k<x[i][j+1];k++) id[i][k]=cnt;
        }
    }int w=cnt;
    for(int i=1;i<=B.size();i++){
        sort(y[i].begin(),y[i].end());
        for(int j=0;j+1<y[i].size();j++){
            cnt++;
            for(int k=y[i][j]+1;k<y[i][j+1];k++)if(id[k][i]) add(id[k][i],cnt,1);
        }
    }
    t=cnt+1;
    for(int i=w+1;i<=cnt;i++) add(i,t,1);
    int qq=calc(),qqq=cnt;
    queue<int> q;q.push(0);chs[0]=1;
    while(!q.empty()){
        int p=q.front();q.pop();
        for(int i=fir[p];i;i=nxt[i])if(val[i]&&!chs[to[i]]) chs[to[i]]=1,q.push(to[i]);
    }
    vector<array<int,4> >zz;
    cnt=w;
    for(int i=1;i<=B.size();i++){
        int lst=y[i][0];
        for(int j=0;j+1<y[i].size();j++){
            ++cnt;
            if(chs[cnt])zz.push_back({lst,i,y[i][j],i}),lst=y[i][j+1];
        }zz.push_back({lst,i,y[i].back(),i});
    }
    cout<<zz.size()<<'\n';
    for(auto x:zz)cout<<A[x[0]-1]<<' '<<B[x[1]-1]<<' '<<A[x[2]-1]<<' '<<B[x[3]-1]<<'\n';zz.clear();
    cnt=0;
    for(int i=1;i<=A.size();i++){
        int lst=x[i][0];
        for(int j=0;j+1<x[i].size();j++){
            ++cnt;
            if(!chs[cnt])zz.push_back({i,lst,i,x[i][j]}),lst=x[i][j+1];
        }
        zz.push_back({i,lst,i,x[i].back()});
    }
    cout<<zz.size()<<'\n';
    for(auto x:zz)cout<<A[x[0]-1]<<' '<<B[x[1]-1]<<' '<<A[x[2]-1]<<' '<<B[x[3]-1]<<'\n';zz.clear();
}