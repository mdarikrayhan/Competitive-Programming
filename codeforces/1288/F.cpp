// LUOGU_RID: 160458627
//#define dxx
#ifdef dxx
#define dbg(...) fprintf(stderr,__VA_ARGS__)
#define dex(a) dbg(#a"=%lld onL%d infun %s\n",(ll)a,__LINE__,__FUNCTION__)
#include<cstdlib>
#define pause sys##tem("read -p \"panss2continue..\"")
#define _GLIBCXX_DEBUG
#endif

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<list>

#define fi first
#define se second
#define mkp std::make_pair
using ll=long long;
using llu=unsigned long long;
using std::max;
using std::min;
template<class T> void cmax(T&a,T b){a=max(a,b);}
template<class T> void cmin(T&a,T b){a=min(a,b);}
template<class T> T sqr(T a){return a*a;}

const int NV=200;

namespace net{
    struct edge{
        int t,w,c,n;
    } G[1000000];
    int ecnt=2,hd[1000],cur[1000],d[1000];
    void ade(int s,int t,int w,int c){
        G[ecnt]={t,w,c,hd[s]};
        hd[s]=ecnt++;
    }void lnk(int s,int t,int l,int r,int c){
        d[s]-=l;
        d[t]+=l;
        ade(s,t,r-l,c);
        ade(t,s,0,-c);
    }
    int N,S,T,dis[1000],flow[1000],pre[1000],lst[1000];
    bool bfs(){
        std::queue<int,std::list<int> > q;
        memset(dis,0x3f,sizeof*dis*(N+1));
        memset(flow,0,sizeof*flow*(N+1));
        memset(pre,0,sizeof*pre*(N+1));
        memset(lst,0,sizeof*lst*(N+1));
        dis[S]=0;
        flow[S]=0x3f3f3f3f;
        q.push(S);
        while(q.size()){
            int x=q.front();
            q.pop();
            for(int e=hd[x];e;e=G[e].n)
                if(G[e].w&&dis[G[e].t]>dis[x]+G[e].c){
                    dis[G[e].t]=dis[x]+G[e].c;
                    flow[G[e].t]=min(flow[x],G[e].w);
                    pre[G[e].t]=x;
                    lst[G[e].t]=e;
                    q.push(G[e].t);
                }
        }
        return flow[T]>0;
    }
}

namespace xm{
    char sz1[NV+5],sz2[NV+5];
    void _(){
        int N1,N2,M,R,B;

        scanf("%d%d%d%d%d%s%s",&N1,&N2,&M,&R,&B,sz1+1,sz2+1);

        int s1=N1+N2+1,t1=s1+1;
        net::S=t1+1;
        net::N=net::T=net::S+1;

        for(int i=1,u,v;i<=M;++i){
            scanf("%d%d",&u,&v);
            net::lnk(u,N1+v,0,1,R);
            net::lnk(N1+v,u,0,1,B);
        }
        for(int i=1;i<=N1;++i){
            if(sz1[i]=='R') net::lnk(s1,i,1,0x3f3f3f3f,0);
            else if(sz1[i]=='B') net::lnk(i,t1,1,0x3f3f3f3f,0);
            else{
                net::lnk(s1,i,0,0x3f3f3f3f,0);
                net::lnk(i,t1,0,0x3f3f3f3f,0);
            }
        }
        for(int i=1;i<=N2;++i){
            if(sz2[i]=='R') net::lnk(i+N1,t1,1,0x3f3f3f3f,0);
            else if(sz2[i]=='B') net::lnk(s1,i+N1,1,0x3f3f3f3f,0);
            else{
                net::lnk(i+N1,t1,0,0x3f3f3f3f,0);
                net::lnk(s1,i+N1,0,0x3f3f3f3f,0);
            }
        }
        net::lnk(t1,s1,0,0x3f3f3f3f,0);
        int ans=0,cost=0,sum=0;
        for(int i=1;i<=t1;++i){
            if(net::d[i]>0){
                sum+=net::d[i];
                net::lnk(net::S,i,0,net::d[i],0);
            }
            if(net::d[i]<0){
                net::lnk(i,net::T,0,-net::d[i],0);
            }
        }
        while(net::bfs()){
            ans+=net::flow[net::T];
            cost+=net::flow[net::T]*net::dis[net::T];
            for(int nw=net::T;nw!=net::S;nw=net::pre[nw]){
                net::G[net::lst[nw]].w-=net::flow[net::T];
                net::G[net::lst[nw]^1].w+=net::flow[net::T];
            }
        }

        if(ans<sum){
            puts("-1");
            return;
        }
        printf("%d\n",cost);
        for(int i=2;i<=4*M;i+=4){
            if(!net::G[i].w) putchar('R');
            else if(!net::G[i+2].w) putchar('B');
            else putchar('U');
        }
        puts("");
    }
}

signed main(){
    xm::_();
    return 0;
}
