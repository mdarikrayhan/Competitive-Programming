#include<bits/stdc++.h>

#define inf 300000000

#define y second

#define x first
using namespace std;typedef pair<int,int>pii;typedef pair<pii,int>pi3;template<typename T,typename U>inline void smin(T&a,const U&b){if(a>b)a=b;}template<typename T,typename U>inline void smax(T&a,const U&b){if(a<b)a=b;}
#define NN 100100

#define MM 400400
int id[NN],LL[MM],RR[MM];int x[NN],y[NN],xmn[MM],xmx[MM],ymn[MM],ymx[MM];inline void select(int L,int mid,int R,int*val){R--;while(L+1<=R){if(L+1==R){if(val[id[L]]>val[id[R]])swap(id[L],id[R]);return;}int S=L+1,X=S+rand()*rand()%(R-L);swap(id[L],id[X]);if(val[id[L]]>val[id[R]])swap(id[L],id[R]);if(val[id[L]]>val[id[S]])swap(id[L],id[S]);if(val[id[S]]>val[id[R]])swap(id[S],id[R]);int i=L,j=R,p=val[id[S]];while(1){while(i<=R&&val[id[i]]<=p)i++;while(j>=L&&val[id[j]]>=p)j--;if(i>j)break;swap(id[i],id[j]);}if(mid<=j)R=j;else if(mid>=i)L=i;else break;}}inline void build(int u,int L,int R,int dp=0){LL[u]=L,RR[u]=R;if(L+1==R){xmn[u]=xmx[u]=x[id[L]];ymn[u]=ymx[u]=y[id[L]];return;}int ls=u<<1,rs=ls|1,mid=L+R>>1;if(dp)select(L,mid,R,x);else select(L,mid,R,y);dp^=1;build(ls,L,mid,dp);build(rs,mid,R,dp);xmn[u]=min(xmn[ls],xmn[rs]),xmx[u]=max(xmx[ls],xmx[rs]);ymn[u]=min(ymn[ls],ymn[rs]),ymx[u]=max(ymx[ls],ymx[rs]);}int ax,ay,bx,by;inline bool calc(int u){if(xmn[u]>bx||xmx[u]<ax||ymn[u]>by||ymx[u]<ay)return false;if(ax<=xmn[u]&&xmx[u]<=bx&&ay<=ymn[u]&&ymx[u]<=by)return true;if(LL[u]+1==RR[u])return false;int ls=u<<1;if(calc(ls))return true;return calc(ls|1);}pi3 p[NN];int n,m;inline bool can(int T){ax=ay=-inf,bx=by=inf;for(int i=0;i<n;i++){if(ax<=bx&&ay<=by){if(m&&p[i].y<=T){int d=T-p[i].y;ax-=d,bx+=d,ay-=d,by+=d;if(calc(1))return true;ax+=d,bx-=d,ay+=d,by-=d;}}else return false;int x=p[i].x.x,y=p[i].x.y;smax(ax,x-T),smin(bx,x+T);smax(ay,y-T),smin(by,y+T);}return ax<=bx&&ay<=by;}main(){
#ifndef ONLINE_JUDGE
freopen("in.in","r",stdin);freopen("out.out","w",stdout);
#endif
srand(time(0));scanf("%d%d",&n,&m);if(n==1)return puts("0");for(int i=0,x,y;i<n;i++){scanf("%d%d",&x,&y);p[i]=pi3(pii(x-y,x+y),0);}for(int i=0,x,y;i<m;i++){scanf("%d%d",&x,&y);::x[i]=x-y;::y[i]=x+y;id[i]=i;}if(m)build(1,0,m);for(int i=0,x,y;i<n;i++){x=p[i].x.x,y=p[i].x.y;int st=-1,ed=inf;while(st+1<ed){int md=st+ed>>1;ax=x-md,bx=x+md,ay=y-md,by=y+md;if(m&&calc(1))ed=md;else st=md;}p[i].y=ed;}sort(p,p+n,[](pi3 a,pi3 b){return a.y>b.y;});int st=-1,ed=inf;while(st+1<ed){int md=st+ed>>1;if(can(md))ed=md;else st=md;}printf("%d",ed);}