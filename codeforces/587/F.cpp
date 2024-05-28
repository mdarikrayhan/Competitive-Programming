// LUOGU_RID: 159820235
# include <bits/stdc++.h>
# define fir first
# define sec second

const int N=100010,INF=0x3f3f3f3f;

inline int read(void){
	int res,f=1;
	char c;
	while((c=getchar())<'0'||c>'9')
		if(c=='-') f=-1;
	res=c-48;
	while((c=getchar())>='0'&&c<='9')
		res=res*10+c-48;
	return res*f;
}

int n,q;
char s[N];
int edp[N];

namespace acam{
	int nex[N][26];
	int fail[N],cnt=1,fa[N];
	
	inline void ins(int x){
		int len=strlen(s+1),cur=1;
		for(int i=1;i<=len;++i){
			int &ne=nex[cur][s[i]-'a'];
			if(!ne) ne=++cnt,fa[cnt]=cur;
			cur=ne;
		}
		edp[x]=cur;
		return;
	}
	std::vector <int> G[N];
	int dfn[N],t,siz[N];
	
	void dfs(int x){
		dfn[x]=++t,siz[x]=1;
		for(auto y:G[x]) dfs(y),siz[x]+=siz[y];
		return;
	}
	inline void init(void){
		for(int i=0;i<26;++i) nex[0][i]=1;
		std::queue <int> q;q.push(1);
		while(!q.empty()){
			int i=q.front();
			q.pop();
			for(int j=0;j<26;++j){
				if(!nex[i][j]) nex[i][j]=nex[fail[i]][j];
				else fail[nex[i][j]]=nex[fail[i]][j],q.push(nex[i][j]);
			}
		}
		for(int i=2;i<=cnt;++i) G[fail[i]].push_back(i);
		dfs(1);
		return;
	}
}
using namespace acam;

int m,T;
int len[N];

long long ans[N];
std::vector <std::pair <int,int> > Qs[N],Qh[N];

int sum[N],tag[N];

inline int lb(int x){
	return x&(-x);
}
inline void add(int x,int v){
	for(;x<=cnt;x+=lb(x)) sum[x]+=v;
	return;
}
inline int query(int x){
	int ans=0;
	for(;x;x-=lb(x)) ans+=sum[x];
	return ans;
}
inline int query(int l,int r){
	return query(r)-query(l-1);
}

void dfs_h(int x){
	for(auto y:G[x]) dfs_h(y),tag[x]+=tag[y];
	return;
}
int sig(int x){
	return (x>0)-(x<0);
}

int main(void){
	n=read(),q=read();
	for(int i=1;i<=n;++i){
		scanf("%s",s+1),ins(i),m+=(len[i]=strlen(s+1));
	}
	init();
	
	T=ceil(m/sqrt(q*log2(m)));
	
	for(int i=1;i<=q;++i){
		int l=read(),r=read(),k=read();
		if(len[k]>T) Qh[k].emplace_back(l-1,-i),Qh[k].emplace_back(r,i);
		else Qs[l-1].emplace_back(k,-i),Qs[r].emplace_back(k,i);
	}
	
	for(int i=1;i<=n;++i){
		if(len[i]>T){
			std::fill(tag+1,tag+1+cnt,0);
			for(int j=edp[i];j;j=fa[j]) tag[j]=1;
			dfs_h(1);
			std::sort(Qh[i].begin(),Qh[i].end());
			long long tsum=0;
			int pt=0;
			
			while(pt<(int)Qh[i].size()&&Qh[i][pt].fir==0) ++pt;
			
			for(int j=1;j<=n;++j){
				tsum+=tag[edp[j]];
				while(pt<(int)Qh[i].size()&&Qh[i][pt].fir==j){
					int id=abs(Qh[i][pt].sec),v=sig(Qh[i][pt].sec);
					ans[id]+=v*tsum;
					++pt;
				}
			}	
		}	
	}
	
	for(int i=1;i<=n;++i){
		add(dfn[edp[i]],1),add(dfn[edp[i]]+siz[edp[i]],-1);
		for(auto qa:Qs[i]){
			int x=qa.fir,id=abs(qa.sec),v=sig(qa.sec);
			for(int j=edp[x];j!=1;j=fa[j]) ans[id]+=v*query(dfn[j]);
		}
	}
	
	for(int i=1;i<=q;++i) printf("%lld\n",ans[i]);
	
	return 0;
}