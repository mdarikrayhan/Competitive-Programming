#include<bits/stdc++.h>
#define For(a,b,c) for(int a=b;a<=c;++a)
const int dX[]={2,2,1,1,-1,-1,-2,-2},dY[]={1,-1,2,-2,2,-2,1,-1};
enum{N=1007,M=1000007};
int n,m,a,b,c,d,e,f;
struct O {
int t,X[M],Y[M],D[N][N],fX[N][N],fY[N][N];
void fly(int a,int b) {
	X[t=1]=a,Y[1]=b,D[a][b]=1;
	For(i,1,t) {
		int x=X[i],y=Y[i];
		For(d,0,7) {
			int u=x+dX[d],v=y+dY[d];
			if(u<1||v<1||u>n||v>m) continue;
			if(!D[u][v]) D[u][v]=D[x][y]+1,X[++t]=u,Y[t]=v,fX[u][v]=x,fY[u][v]=y;
		}
	}
}
void step(int x,int y) {
	For(i,0,7) {
		if(a+dX[i]==c&&b+dY[i]==d) {
			printf("%d %d\n",c,d),fflush(stdout);
			exit(0);
		}
	}
	printf("%d %d\n",x,y),fflush(stdout);
	if(x==c&&y==d) exit(0);
	if(x==e&&y==f) exit(0);
	scanf("%d%d",&c,&d),a=x,b=y;
}
void go(int x,int y) {
	if(!fX[x][y]) return;
	go(fX[x][y],fY[x][y]);
	step(x,y);
}
}W,B;
int main() {
	scanf("%d%d%d%d%d%d",&n,&m,&a,&b,&c,&d);
	W.fly(a,b),B.fly(c,d);
	int ww=W.D[n/2][m/2],bw=B.D[n/2][m/2],wb=W.D[n/2+1][m/2],bb=B.D[n/2+1][m/2];
	if(ww<bw&&ww<=bb) {
		puts("WHITE"),fflush(stdout);
		e=n/2,f=m/2;
		W.go(e,f);
	}
	else if(bb+1<wb&&bb<ww) {
		puts("BLACK"),fflush(stdout);
		e=n/2+1,f=m/2;
		a=c,b=d,scanf("%d%d",&c,&d);
		B.go(e,f);
	}
	else if(((a+b)&1)!=((c+d)&1)) {
		puts("WHITE"),fflush(stdout);
		e=n/2,f=m/2;
		int p=e+1,q=f;
		if(ww<=bb) W.go(e,f);
		else {
			W.go(p,q);
			W.step(p-1,q-2);
			W.step(p-3,q-1);
			W.step(p-1,q);
		}
	}
	else {
		puts("BLACK"),fflush(stdout);
		a=c,b=d,scanf("%d%d",&c,&d);
		e=n/2+1,f=m/2;
		if(bb<ww) B.go(e,f);
		else {
			int p=e-1,q=f;
			B.go(p,q);
			B.step(p+1,q-2);
			B.step(p+3,q-1);
			B.step(p+1,q);
		}
	}
	exit(0);
}