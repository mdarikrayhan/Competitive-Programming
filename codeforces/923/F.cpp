# include<iostream>
# include<sstream>
# include<cstdio>
# include<cstdlib>
# include<algorithm>
# include<cstring>
# include<cmath>
# include<queue>
# include<vector>
# include<set>
# include<iterator>
# include<bitset>
using namespace std;
#define min(a,b)((a)<(b)?(a):(b))
#define pb push_back
#define mem(a,x)memset(a,x,sizeof(a))
#define rep(i,a,b)for(int i=(a);i<=(b);++i)
typedef long long ll;
const int N=10005;
int d1[N],d2[N],ans[N],n,x,y,u,v,w,num,tmp[N];bool vis1[N],vis2[N];
vector<int>V1[N],V2[N];bitset<N>a[N];
struct Btype{int x,y;}E[N];
struct Stype{int d,id;ll r;}s1[N],s2[N];set<Stype>S;
inline ll myrand(){return((ll)(rand()&65535)<<32)+((ll)rand()<<16)+rand();}
inline bool operator<(const Stype p,const Stype q){
return p.d<q.d||p.d==q.d&&p.r<q.r||p.d==q.d&&p.r==q.r&&p.id<q.id;
}
inline bool operator>(const Stype p,const Stype q){
return p.d>q.d||p.d==q.d&&p.r>q.r||p.d==q.d&&p.r==q.r&&p.id>q.id;
}

inline void print(){printf("Yes\n");rep(i,1,n)printf("%d ",ans[i]+n);printf("\n");}
inline void D(int x){
vis1[x]=1,num++;S.erase(s1[x]);
for(auto y: V1[x])if(!vis1[y])S.erase(s1[y]),s1[y].d++,S.insert(s1[y]);
}

inline bool _work(){
random_shuffle(tmp+1,tmp+n+1);
rep(i,1,n-1)if(a[tmp[E[i].x]][tmp[E[i].y]])return 0;
rep(i,1,n)ans[i]=tmp[i];print();return 1;
}

inline bool work(){
mem(vis1,0),mem(vis2,0),mem(ans,0),num=0;S.clear();
rep(i,1,n)s1[i].r=myrand(),S.insert(s1[i]),s2[i].r=myrand();
priority_queue<Stype,vector<Stype>,greater<Stype>>Q;
Stype s=s2[1];rep(i,2,n)if(s2[i].d==1)s=min(s,s2[i]);
Q.push(s),ans[s.id]=S.begin()->id,vis2[s.id]=1,D(S.begin()->id);
while(!Q.empty()){
Stype s=Q.top();Q.pop();u=ans[x=s.id];
for(auto y: V2[x])if(!vis2[y]){
s2[y].d--;auto it=S.lower_bound(Stype{s2[y].d+num,-1,-1});
for(;it!=S.end();it++)if(!a[u][v=it->id]){ans[y]=v;break;}
if(!ans[y])return 0;D(v),vis2[y]=1,Q.push(s2[y]);
}
}
print();return 1;
}

int main(){
scanf("%d",&n);
rep(i,1,n-1){
scanf("%d%d",&x,&y),d2[x]++,d2[y]++;
V2[x].pb(y),V2[y].pb(x);E[i]=Btype{x,y};
}
rep(i,1,n-1){
scanf("%d%d",&x,&y),x-=n,y-=n,d1[x]--,d1[y]--;
V1[x].pb(y),V1[y].pb(x);a[x][y]=a[y][x]=1;
}
rep(i,1,n)d1[i]+=n-1;
rep(i,1,n)if(!d1[i]||d2[i]==n-1)return 0*printf("No\n");
rep(i,1,n)s1[i]=Stype{d1[i],i,myrand()},s2[i]=Stype{d2[i],i,myrand()},tmp[i]=i;
for(;!_work()&&!work(););return 0;
}