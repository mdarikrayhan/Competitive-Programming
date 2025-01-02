// LUOGU_RID: 159995691
#include<bits/stdc++.h>
#define FL(i,a,b) for(int i=(a);i<=(b);i++)
#define FR(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long
using namespace std;

const int MAXN = 1e6 + 5;
int a[MAXN],vis[MAXN],nxt[MAXN],L[MAXN],R[MAXN];
int n,m,now=1;
void Fail(){
	puts("no");	
	exit(0);
}
int Get(){
	while(vis[now]) now++;
	if(now>n) Fail();
	vis[now]=1;
	return now;
}
void Delete(int l,int r){
	int tl=L[l],tr=R[r];
	R[tl]=tr,L[tr]=tl;
}
void Merge(int l,int r,int &x){
	while(x>l&&R[R[x]]&&R[R[x]]<=r&&!a[x]&&a[R[x]]&&a[R[R[x]]]){
		a[x]=a[R[R[x]]];
		Delete(R[x],R[R[x]]);
		x=L[L[x]];
	}
	while(x>l&&R[R[x]]&&R[R[x]]<=r&&a[x]&&a[R[x]]&&!a[R[R[x]]]){
		a[R[R[x]]]=a[x];
		Delete(R[x],R[R[x]]);
		x=L[L[x]];
	}
}

void solve(int l,int r){
	if(r-l&1) Fail();
	for(int i=l;i<=r;i=R[i]){
		while(nxt[i]){
			if(nxt[i]>r) Fail();
			solve(R[i],L[nxt[i]]);
			Delete(R[i],nxt[i]);
			nxt[i]=nxt[nxt[i]];
		}
	}
	int num1=0,num2=0,rt=a[L[l]];
	for(int i=l;i<=r;i=R[i]) num1+=(a[i]>0),num2++;
	num2=(num2>>1)+1;
	if(num1>num2) Fail();
	num2-=num1; 
	for(int i=l;num2&&i<=r;i=R[i]){
		if(!a[i]) a[i]=Get(),num2--;	
	}
	for(int i=l;i<=r;i=R[i]) Merge(l-1,r,i);
	for(int i=l;i<=r;i=R[i]){
		if(!a[i]) a[i]=rt;
	}
}

int main(){
	scanf("%d",&n);
	if(n==1){
		puts("yes");
		puts("1");
		return 0;
	}
	m=(n<<1)-1;
	FL(i,1,m) scanf("%d",&a[i]);
	FL(i,2,m){
		if(a[i]&&a[i-1]&&a[i]==a[i-1]) Fail();
	}
	if(a[1]&&a[m]&&a[1]!=a[m]) Fail();
	a[1]=a[m]=a[1]|a[m];
	FL(i,0,m+1) L[i]=i-1,R[i]=i+1;
	L[0]=0;
	FR(i,m,1){
		if(a[i]){
			nxt[i]=vis[a[i]];
			vis[a[i]]=i;
		}
	}
	solve(1,m);
	puts("yes");
	FL(i,1,m) printf("%d ",a[i]);
	return 0;
}