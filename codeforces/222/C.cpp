#include<bits/stdc++.h>
#define F(ii,aa,bb) for(int ii=aa;ii<bb;ii++)
#define FI(ii,aa,bb) for(int ii=aa;ii<=bb;ii++)
#define on (10000005)
int n[2],A[2][100005],P[10000005],B[2][10000005];
int sieve(){F(i,2,on) if(!P[i]) for(int j=i;j<on;j+=i) P[j]=i;}
int p(int x){FI(i,1,n[x]) for(int j=A[x][i];j>1;j/=P[j]) B[x][P[j]]++;}
int rdc(int x,int y){int r;FI(i,1,n[x]){ r=1; for(int j=A[x][i];j>1;j/=P[j]) B[y][P[j]]?B[y][P[j]]-- :r*=P[j];printf("%d ",r); }puts("");}
int main(){scanf("%d %d",n,n+1);FI(i,1,n[0]) scanf("%d",A[0]+i);FI(i,1,n[1]) scanf("%d",A[1]+i);printf("%d %d\n",n[0],n[1]);sieve();p(0);p(1);rdc(0,1);rdc(1,0);return 0;}
