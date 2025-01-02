// LUOGU_RID: 160180250
# include <bits/stdc++.h>

const int N=1000010,INF=0x3f3f3f3f,mod=1e9+7;

char s[N],t[N];

int n;

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

namespace pam{
	int ch[N][26],len[N],slink[N],fail[N],diff[N];
	int cnt=-1,last;
	inline int node(int l){
		return len[++cnt]=l,cnt;
	}
	inline void init(void){
		node(0),node(-1),fail[0]=1;
		return;
	}
	inline int getfail(int x,int pos){
		while(t[pos-1-len[x]]!=t[pos]) x=fail[x];
		return x;
	}
	inline void extend(int pos,int c){
		int x=getfail(last,pos),p;
		if(!ch[x][c]){
			p=node(len[x]+2),fail[p]=ch[getfail(fail[x],pos)][c],ch[x][c]=p;
			diff[p]=len[p]-len[fail[p]];
			slink[p]=((diff[p]==diff[fail[p]])?slink[fail[p]]:fail[p]);
		}
		last=ch[x][c];
		return;
	}	
}

using namespace pam;

int g[N],f[N];

int main(void){
	scanf("%s",s+1),n=strlen(s+1);
	if(n%2) puts("0"),exit(0);
	for(int i=1,l=1,r=n;i<=n/2;++i,++l,--r) t[2*i-1]=s[l],t[2*i]=s[r];	
	init();
	f[0]=1;
	for(int i=1;i<=n;++i){
		extend(i,t[i]-'a');
		for(int j=last;j;j=slink[j]){
			g[j]=f[i-len[slink[j]]-diff[j]];
			if(slink[j]!=fail[j]) g[j]=(g[j]+g[fail[j]])%mod;
			if(i%2==0) f[i]=(f[i]+g[j])%mod;
		}
	}
	
	printf("%d",f[n]);

	return 0;
}

