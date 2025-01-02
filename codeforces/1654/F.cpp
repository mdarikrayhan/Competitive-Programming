// LUOGU_RID: 160242017
# include <bits/stdc++.h>

const int N=300010,INF=0x3f3f3f3f;

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
char s[N];

struct Node{
	int fir,sec,id;
	bool operator < (const Node &rhs) const{
		return (fir!=rhs.fir)?(fir<rhs.fir):(sec<rhs.sec);
	}
	bool operator != (const Node &rhs) const{
		return (*this<rhs)||(rhs<*this);
	}
}g[N];

int rk[N];
int n;

int main(void){
	n=1<<read();
	scanf("%s",s);
		
	for(int i=0;i<n;++i) g[i]=(Node){s[i],0,i};
	std::sort(g,g+n);
	for(int i=0,cc=0;i<n;++i){
		if(i==0||g[i]!=g[i-1]) rk[g[i].id]=++cc;
		else rk[g[i].id]=cc;
	}
	
	for(int w=1;w<n;w<<=1){
		for(int i=0;i<n;++i) g[i]=(Node){rk[i],rk[i^w],i};
		std::sort(g,g+n);
		for(int i=0,cc=0;i<n;++i){
			if(i==0||g[i]!=g[i-1]) rk[g[i].id]=++cc;
			else rk[g[i].id]=cc;
		}
	}
	
	for(int v=0;v<n;++v) if(rk[v]==1){
		for(int i=0;i<n;++i) putchar(s[i^v]);
		exit(0);
	}

	return 0;
}