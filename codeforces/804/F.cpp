#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;
const int WZP=6666666;
char LZH[WZP],*SSS=LZH,*TTT=LZH;
inline char gc(){
	if (SSS==TTT){
		TTT=(SSS=LZH)+fread(LZH,1,WZP,stdin);
		if (SSS==TTT) return EOF;
	}
	return *SSS++;
}
inline int read01(){
	char s=gc();
	for (;s<'0'||s>'1';s=gc());
	return s-'0';
}
inline int read(){
	char s=gc(); int x=0;
	for (;s<'0'||s>'9';s=gc());
	for (;s>='0'&&s<='9';s=gc())
		x=x*10-48+s;
	return x;
}
const int N=5005;
bool e[N][N];
int dfn[N],low[N],stk[N];
int be[N],vis[N],blk;
int sz[N],G[N];
bool OK[2000005];
vector<int> vec[N];
vector<int> ok[N];
int s1[N],s2[N];
int n,A,B;
char s[2000005];
void tarjan(int x){
	vis[x]=1; stk[++*stk]=x;
	dfn[x]=low[x]=++*dfn;
	For(i,1,n)
		if (e[x][i])
			if (!dfn[i]){
				tarjan(i);
				low[x]=min(low[x],low[i]);
			}
			else if (vis[i])
				low[x]=min(low[x],dfn[i]);
	if (low[x]==dfn[x]){
		int y=23333333;
		++blk;
		for (;y!=x;){
			y=stk[(*stk)--];
			vis[y]=0;
			be[y]=blk;
		}
	}
}
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
void init(){
	For(i,1,n)
		For(j,1,n) e[i][j]=read01();
	For(i,1,n)
		if (!dfn[i]) tarjan(i);
	For(i,1,n){
		sz[i]=read();
		vec[i].resize(sz[i]);
		For(j,0,sz[i]-1) vec[i][j]=read01();
	}
	For(i,1,n)
		if (!G[be[i]])
			G[be[i]]=sz[i];
		else G[be[i]]=gcd(G[be[i]],sz[i]);
	For(i,1,blk) ok[i].resize(G[i]);
	For(i,1,n)
		For(j,0,sz[i]-1)
			if (vec[i][j])
				ok[be[i]][j%G[be[i]]]=1;
	Rep(i,blk,2){
		int tmp=gcd(G[i],G[i-1]);
		For(j,0,tmp-1) OK[j]=0;
		For(j,0,G[i]-1)
			if (ok[i][j])
				OK[j%tmp]=1;
		For(j,0,G[i-1]-1)
			if (OK[j%tmp])
				ok[i-1][j]=1;
	}
	For(i,1,n)
		For(j,0,sz[i]-1)
			if (!vec[i][j])
				if (ok[be[i]][j%G[be[i]]])
					vec[i][j]=2;
	For(i,1,n)
		For(j,0,sz[i]-1)
			if (vec[i][j]==1) s1[i]++;
			else if (vec[i][j]==2) s2[i]++;
}
int id[N],C[N][N],ans;
const int mo=1000000007;
bool cmp(int x,int y){
	return s1[x]+s2[x]>s1[y]+s2[y];
}
int main(){
	n=read(); A=read(); B=read();
	init();
	For(i,0,n){
		C[i][0]=1;
		For(j,1,i)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mo;
	}
	For(i,1,n) id[i]=i;
	sort(id+1,id+n+1,cmp);
	For(i,1,n){
		int checked=1;
		For(j,1,i-1)
			if (s1[id[j]]>s1[id[i]]+s2[id[i]])
				checked++;
		For(j,1,min(checked,B)) if (checked+(B-j)<=A)
			ans=(ans+1ll*C[checked-1][j-1]*C[i-checked][B-j])%mo;
	}
	
	printf("%d\n",ans);
}
