// LUOGU_RID: 159741151
# include <bits/stdc++.h>

const int N=100010,INF=0x3f3f3f3f,mod=1e9+9;

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

int n,m;
int f[1005][105][12];

char s[20];

std::unordered_map <char,int> mp;

namespace acam{
	int nex[N][4],fail[N];
	int cnt=1;
	int ml[N];
	
	inline void ins(void){
		int len=strlen(s+1),cur=1;
		for(int i=1;i<=len;++i){
			if(!nex[cur][mp[s[i]]]) nex[cur][mp[s[i]]]=++cnt;
			cur=nex[cur][mp[s[i]]];
		}
		ml[cur]=len;
		return;
	}
	inline void init(void){
		for(int i=0;i<4;++i) nex[0][i]=1;
		std::queue <int> q;
		q.push(1);
		while(!q.empty()){
			int i=q.front();
			q.pop();
			ml[i]=std::max(ml[i],ml[fail[i]]);
			for(int j=0;j<4;++j){
				if(!nex[i][j]) nex[i][j]=nex[fail[i]][j];
				else fail[nex[i][j]]=nex[fail[i]][j],q.push(nex[i][j]);
			}
		}
		return;
	}
}
using namespace acam;

inline void add(int &a,int b){
	return a=(a+b)%mod,void();
}

int main(void){
	n=read(),m=read();
	mp['A']=0,mp['C']=1,mp['T']=2,mp['G']=3;
	
	for(int i=1;i<=m;++i){
		scanf("%s",s+1),ins();
	}
	
	init();
	
	f[0][1][0]=1;
	
	for(int i=0;i<n;++i){
		for(int j=1;j<=cnt;++j){
			for(int len=0;len<=10;++len){
				for(int d=0;d<4;++d){
					int k=nex[j][d];
					if(ml[k]>len) add(f[i+1][k][0],f[i][j][len]);
					else add(f[i+1][k][len+1],f[i][j][len]);
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=cnt;++i) add(ans,f[n][i][0]);
	printf("%d",ans);
	return 0;
}