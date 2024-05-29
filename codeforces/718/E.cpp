// LUOGU_RID: 160388422
/*
O(2^kk^2+nk+knlogn)
k=30是什么玩意啊？？？
现写 k<=20 吧，记得测极限数据！！！！
nmd 怎么 k<=20 有 v 和 A 啊
*/
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef unsigned long long ull;
typedef unsigned int uint;
inline ll read() {
	ll x=0,f=1;char ch=getchar();
	while(!isdigit(ch)) {if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)) {x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}
const ll N=1e5+5,K=10,inf=0x3f3f3f3f;
ll n,m,k;
namespace K20 {
    int cnt,blg[N],dis_cp[K][N],dis_cc[K][K],suf[K][N],ov[N];
    ll fnl[N];
    vector <int> pos[K];
    int tot,hd[N];
    struct edge {int to,nxt;}e[N<<1];
    void addedge(int x,int y) {
        e[++tot]={y,hd[x]},hd[x]=tot;
        e[++tot]={x,hd[y]},hd[y]=tot;
    }
    int nt[305],id;
    int chg(int c) {
        if(!nt[c]) nt[c]=++id;
        return nt[c];
    }
    bool app[K];
    void ckmin(int &x,int y) {
        x=(y<x?y:x);
    }
    queue <int> q;
    void get_dis(int c) {
        memset(app,false,sizeof app);
        for(int i=1;i<=n;i++) if(blg[i]==c) dis_cp[c][i]=0,q.push(i);
        while(!q.empty()) {
            int nw=q.front();q.pop();
            if(!app[blg[nw]]) {
                for(int to:pos[blg[nw]]) {
                    if(dis_cp[c][to]!=inf) continue;
                    dis_cp[c][to]=dis_cp[c][nw]+1;q.push(to);
                }
                app[blg[nw]]=true;
            }
            for(int i=hd[nw];i;i=e[i].nxt) {
                int to=e[i].to;
                if(dis_cp[c][to]!=inf) continue;
                dis_cp[c][to]=dis_cp[c][nw]+1;q.push(to);
            }
        }
        for(int i=1;i<=n;i++) ckmin(dis_cc[c][blg[i]],dis_cp[c][i]);
    }
    vector <array<int,2>> S[K];
    map <int,int> mp;
    void dp(int c) {
        mp.clear();
        for(auto nw:pos[c]) {
            int sit=0;
            for(int i=1;i<=k;i++) {
                if(dis_cp[i][nw]==dis_cc[i][c]) {
                    sit|=(1<<(i-1));
                }
            }
            mp[sit]++;ov[nw]=sit;
        }
        for(auto [u,v]:mp) S[c].push_back({u,v});
    }
    int mn[K],ex_sit[K],fk[K][K],rz[K][K],cf[K][K];
    void delta(int x,int y,int dis) {
        if(blg[x]>blg[y]) return ;
        int org=rz[blg[x]][blg[y]]+2;
        if(ov[x]&ov[y]&fk[blg[x]][blg[y]]) org-=2;
        else if((ov[x]&fk[blg[x]][blg[y]])||(ov[y]&fk[blg[x]][blg[y]])||(ov[x]&ov[y]&cf[blg[x]][blg[y]])) org--;
        fnl[org]-=(1+(blg[x]!=blg[y])),fnl[min(org,dis)]+=(1+(blg[x]!=blg[y]));
    }
    void dfs(int x,int fa,int dis,int rt) {
        if(dis>2*k) return ;
        delta(rt,x,dis);
        for(int i=hd[x];i;i=e[i].nxt) {
            int to=e[i].to;
            if(to==fa) continue;
            dfs(to,x,dis+1,rt);
        }
    }
    void calc(int c) {
        for(auto [cs,cnum]:S[c]) {
            for(int ex=c;ex<=k;ex++) {
                int mns=1,val=dis_cc[c][1]+dis_cc[ex][1]+1,ses=0;
                for(int mid=1;mid<=k;mid++) {
                    if(dis_cc[c][mid]+dis_cc[ex][mid]+1<val) mns=(1<<(mid-1));
                    else if(dis_cc[c][mid]+dis_cc[ex][mid]+1==val) mns|=(1<<(mid-1));
                    ckmin(val,dis_cc[c][mid]+dis_cc[ex][mid]+1);
                }
                for(int mid=1;mid<=k;mid++) {
                    if(dis_cc[c][mid]+dis_cc[ex][mid]+1==val+1) ses|=(1<<(mid-1));
                }
                fk[c][ex]=mns,rz[c][ex]=val,cf[c][ex]=ses;
                for(auto [exs,exnum]:S[ex]) {
                    if(cs&exs&mns) fnl[val]+=(1ll+(ex!=c))*cnum*exnum;
                    else if((cs&mns)||(exs&mns)||(cs&exs&ses)) fnl[val+1]+=(1ll+(ex!=c))*cnum*exnum;
                    else fnl[val+2]+=(1ll+(ex!=c))*cnum*exnum;
                }
            }
        }
    }
    void deal(int x) {
        for(int i=hd[x];i;i=e[i].nxt) dfs(e[i].to,x,1,x);
    }
    void solve() {
        for(int i=1;i<=m;i++) {
            string s;cin>>s;
            for(int j=0;j<(int)(s.size());j++) {
                blg[++cnt]=chg(s[j]);
                pos[chg(s[j])].push_back(cnt);
                if(j>0) addedge(cnt,cnt-1);
            }
        }
        memset(dis_cc,inf,sizeof dis_cc);
        memset(dis_cp,inf,sizeof dis_cp);
        for(int i=1;i<=k;i++) get_dis(i);
        for(int i=1;i<=k;i++) dp(i);
        for(int i=1;i<=k;i++) calc(i);
        for(int i=1;i<=n;i++) deal(i);
        fnl[1]-=n;
        for(int i=n;i>=1;i--) {
        	if(fnl[i]) {
        		cout<<i<<' '<<fnl[i]/2<<'\n';
        		return ;
			}
		}
    }
}
int main() {
    //freopen("highway.in","r",stdin);
    //freopen("highway.out","w",stdout);
    n=read(),m=1,k=8;K20::solve();
	return 0;
}
