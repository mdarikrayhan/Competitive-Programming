// LUOGU_RID: 160532740
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<stack>
#include<ctime>
#include<cmath>
#include<cctype>
#include<bitset>
#include<vector>
#include<cstdio>
#include<random>
#include<climits>
#include<cstring>
#include<iostream>
#include<algorithm>
#define inf 0x3f3f3f3f
#define INF 1e9
#define LLINF 1e18
#define ll long long
#define N 100005
#define M 15
#define S 16
#define Mod 1000000007
using namespace std;
int read(){
	int x=0,f=1,ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f=(ch=='-')?-1:1;
	for(;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+(ch^48);
	return x*f;
}
void print(int x){
	if(x<0) putchar('-'),x=~(x-1);
	if(x>9) print(x/10);
	putchar(x%10+48);
}
int n,k,m,ans,len,pos[M][S],cnt;
struct Matrix{
	int n,m;
	int c[300][300];
	Matrix(){memset(c,0,sizeof(c));}
	friend Matrix operator * (const Matrix &a,const Matrix &b){
		Matrix c;c.n=a.n,c.m=b.m;
		for(int i=0;i<a.n;++i){
			for(int j=0;j<a.m;++j){
				for(int k=0;k<b.m;++k){
					c.c[i][j]=((ll)c.c[i][j]+(ll)a.c[i][k]*b.c[k][j]%Mod)%Mod;
				}
			}
		}
		return c;
	}
	void print(){
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j) printf("%d ",c[i][j]);
			puts("");
		}
	}
}I,F;
Matrix qpow(Matrix a,int b){
	Matrix res;res.n=a.n,res.m=a.m;
	for(int i=0;i<res.n;++i) res.c[i][i]=1;
	while(b){
		if(b&1) res=res*a;
		a=a*a;
		b>>=1;
	}
	return res;
}
int main(){
	n=read(),k=read(),m=read();
	for(int j=0;j<=k;++j) for(int s=0;s<(1<<m);++s) pos[j][s]=cnt++;
	I.n=I.m=F.m=cnt,F.n=1,F.c[0][pos[0][0]]=1;
	for(int j=0;j<=k;++j){
		for(int s=0;s<(1<<m);++s){
			I.c[pos[j][s]][pos[j][s>>1]]=1;
			if(j<k) I.c[pos[j][s]][pos[j+1][(1<<m-1)|s>>1]]=__builtin_popcount(s)+1;
		}
	}
	I=qpow(I,n),F=F*I;
	for(int s=0;s<(1<<m);++s) ans=(ans+F.c[0][pos[k][s]])%Mod;
	printf("%d",ans);
	return 0;
}