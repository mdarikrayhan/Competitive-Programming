#include <bits/stdc++.h>
int a[7],su[7]={2,3,5,7,11,13,17},nxt[1000009],zt[300][12],b[22],id[309],va[309],q,
gg[1000009],f[300][300],k,la[300][300];
#define B 300
static char buf[1000000],*paa=buf,*pd=buf;
static char buf2[1000000],*pp=buf2;
#define getchar() paa==pd&&(pd=(paa=buf)+fread(buf,1,1000000,stdin),paa==pd)?EOF:*paa++
inline void pc(char ch){
  if(pp-buf2==1000000) fwrite(buf2,1,1000000,stdout),pp=buf2;
  *pp++=ch;
}
inline void pcc(){
  fwrite(buf2,1,pp-buf2,stdout);
  pp=buf2;
}
inline int read(void) {
  int w=1;
  register int x(0);register char c(getchar());
  while(c<'0'||c>'9') {if(c=='-') w=-1;c=getchar();}
  while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
  return w*x;
}
void write(int x) {
  if(x<0) pc('-'),x=-x;
  static int sta[20];
  int top=0;
  do {
    sta[top++]=x%10,x/=10;
  } while(x);
  while(top) pc(sta[--top]+48);
}
void we(int x) {
  write(x);
  pc('\n');
}
void tr(int x) {
	k++;gg[x]=k;
	for(int j=0;j<7;j++) zt[k][j]=a[j];
}
void dfs(int n,int v,int Ma) {
	if(n==7) {
		tr(v);
		return;
	}
	for(int i=0;i<=Ma;i++) {
		a[n]=i;
		dfs(n+1,v,i);
		v*=su[n];
		if(v>1000000) break;
	}
}
void tr(int x,int y) {
	for(int i=1;i<=k;i++) {
		int as=0;
		for(int j=0;j<=std::max(y-1,6);j++) {
			as+=abs(b[j]-zt[i][j]);
		}
		f[i][x]=std::min(f[i][x],as);
	}
}
void dfs2(int n,int v,int Ma) {
	if(!id[v]) {
	//	printf("%d\n",v);
		id[v]=++q;
		va[q]=v;
	}
	tr(id[v],n);
	for(int i=1;i<=Ma;i++) {
		if(v*(i+1)>B) break;
		b[n]=i;
		dfs2(n+1,v*(i+1),i);
		b[n]=0;
	}
}
int vt[22];
int yj(int x) {
	while(x>1) {
		int qq=nxt[x],pp=0;
		while(x%qq==0) x/=qq,pp++;
		vt[pp]++;
	}
	int ct=0;
	for(int i=19;i>=1;i--) {
		while(vt[i]--) {
			for(int j=1;j<=i;j++) x*=su[ct];
			ct++;
		}
		vt[i]=0;
	}
	return gg[x];	
}
int fc(int x,int y) {
	if(x>y) std::swap(x,y);
	if(la[x][y]>=0) return la[x][y];
	int as=0x3f3f3f3f;
	for(int j=1;j<=q;j++) as=std::min(as,f[x][j]+f[y][j]);
	return la[x][y]=as;
}
signed main(void) {
	//freopen("m.in","r",stdin);
	memset(f,0x3f,sizeof(f));
	memset(la,-1,sizeof(la));
	dfs(0,1,20);
	dfs2(0,1,20);
	for(int i=2;i<=1000000;i++) nxt[i]=i;
	for(int i=2;i<=1000;i++) {
		if(nxt[i]!=i) continue;
		for(int j=i*i;j<=1000000;j+=i) {
			nxt[j]=std::min(nxt[j],i);
		}
	}
	//return 0;
//	printf("%d %d\n",zt[yj(4)][0],f[yj(10)][3]);
	int T=read();
	while(T--) {
		int a=read(),b=read();
		we(fc(yj(a),yj(b)));
	}
	pcc();
}