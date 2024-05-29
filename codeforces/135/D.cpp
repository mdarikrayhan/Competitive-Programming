#include<cstdio>
#define	F(i,n)	for(i=0;i<n;++i)
#define N	1024
int d[]={0,1,0,-1,1,1,-1,-1},
	e[]={1,0,-1,0,1,-1,-1,1},l,u,q,n,m,i,j,L,o,a,b,c,
	p[N][N],v[N][N],t[N*N];
char s[N][N];
void f(int x,int y){
	s[x][y]=0;
	int a,b,k;
	F(k,8){
		a=x+d[k],b=y+e[k];
#define C a>=0&&b>=0&&a<n&&b<m
		if(C){
			if(s[a][b]=='1'){
				if(v[a][b]!=u)v[a][b]=u,t[l++]=a*m+b;
				o&=p[a][b]==q||!q;q=p[a][b];
			}
			if(s[a][b]=='0')f(a,b);
		}else o=0;
	}
}
void g(int x,int y){
	if(p[x][y])return;
	p[x][y]=u;
	int a,b,k;
	F(k,4){
		a=x+d[k],b=y+e[k];
		if(C)if(s[a][b]=='1')g(a,b);
	}
}
int main(){
	scanf("%d%d ",&n,&m);
	F(i,n)gets(s[i]);
	F(i,n)F(j,m)if(s[i][j]=='1'){
		if(s[i+1][j]=='1'&&s[i][j+1]=='1'&&s[i+1][j+1]=='1')L=4;
		++u;g(i,j);
	}
	F(i,n)F(j,m)if(s[i][j]=='0'){
		o=1;l=q=0;++u;
		f(i,j);
		if(o&&l>L){
			F(q,l){
				c=0;
				F(o,4)a=t[q]/m+d[o],b=t[q]%m+e[o],c+=C&&v[a][b]==u;
				if(c-2)l=L;
			}
			L=l;
		}
	}
	printf("%d\n",L);
	return 0;
}