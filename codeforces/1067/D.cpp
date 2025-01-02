// LUOGU_RID: 159131948
// LUOGU_RID: 159027241
// Problem: Computer Game
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1067D
// Memory Limit: 250 MB
// Time Limit: 3000 ms
// UOB Koala
// 
// 
// Powered by CP Editor (https://cpeditor.org)
 
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define db double
const int maxn=1e5+5;
db a[maxn],b[maxn];
int n,t;
db p[maxn],eps=1e-14;
struct line{
	db k,b;
	int id;
	db operator ()(db x){return k*x+b;}
	bool operator <(line B){return fabs(k-B.k)<eps?a[id]<a[B.id]:k<B.k;}
}L[maxn];
db itsect(line A,line B){
	return (B.b-A.b)/(A.k-B.k);
}
int stk[maxn],tp=0;
db V=0;
struct mat{
	int n,m;
	db a[4][4];
	mat(){memset(a,0,sizeof(a));}
};
mat operator *(mat A,mat B){
	mat C;C.n=A.n,C.m=B.m;
	for(int i=1;i<=C.n;i++)
		for(int j=1;j<=C.m;j++)
			for(int k=1;k<=A.m;k++)
				C.a[i][j]+=A.a[i][k]*B.a[k][j];
	return C;
}
mat getM(db p,db v,db a){
	mat A;A.n=A.m=3;
	A.a[1][1]=1-p,A.a[2][1]=p*v,A.a[2][2]=1,A.a[3][1]=p*a,A.a[3][2]=1,A.a[3][3]=1;
	return A;
}
mat Trans[50];
mat qp(mat A,int b){
	if(b==0){
		mat B;B.n=B.m=3;
		B.a[1][1]=B.a[2][2]=B.a[3][3]=1;
		return B;
	}
	mat T=qp(A,b>>1);T=T*T;
	if(b&1)return T*A;
	return T;
}
mat getIM(db p,db v,db a){
	mat IT;IT.n=IT.m=3,IT.a[1][1]=1.0/(1-p),IT.a[2][1]=-p*v/(1-p),IT.a[2][2]=1;
	IT.a[3][1]=(p*v-p*a)/(1-p),IT.a[3][2]=-1,IT.a[3][3]=1;
	return IT;
}
int dcmp(db x){
	if(x<-eps)return -1;
	if(x>eps)return 1;
	return 0;
}
signed main(){
	cin>>n>>t;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>p[i],L[i]={p[i],p[i]*a[i],i},V=max(V,b[i]*p[i]);
	sort(L+1,L+n+1);
	for(int i=1;i<=n;i++){
		while(tp>1&&dcmp(itsect(L[stk[tp-1]],L[i])-itsect(L[stk[tp-1]],L[stk[tp]]))<=0)--tp;
		stk[++tp]=i;
	}
	// for(int i=1;i<=tp;i++)cout<<L[stk[i]].id<<" ";
	// cout<<endl;
	int lst=0;mat cur;
	cur.n=1,cur.m=3,cur.a[1][1]=0,cur.a[1][2]=0,cur.a[1][3]=1;
	for(int j=1;j<=tp;j++){
// 		cerr<<"____________________________________"<<endl;
// 		cerr<<"At "<<L[stk[j]].k<<"x+"<<L[stk[j]].b<<endl;
		db R=(j==tp?1e18:itsect(L[stk[j]],L[stk[j+1]]));
// 		cerr<<"R="<<R<<endl;
		mat T=getM(p[L[stk[j]].id],V,a[L[stk[j]].id]);
		mat IT=getIM(p[L[stk[j]].id],V,a[L[stk[j]].id]);
		mat D=cur*T;
		// cerr<<"D : ["<<D.a[1][1]<<","<<D.a[1][2]<<","<<D.a[1][3]<<"]"<<endl;
		Trans[0]=T;
		for(int i=1;i<=35;i++)Trans[i]=Trans[i-1]*Trans[i-1];
		for(int i=35;i>=0;i--)if(lst+(1ll<<i)<=t){
			mat CUR=cur*Trans[i],lst1=CUR*IT,lst2=lst1*IT;
			if(dcmp(V*lst1.a[1][2]-lst1.a[1][1]-R)<=0){
				cur=CUR,lst+=(1ll<<i);
				// cerr<<"add "<<(1ll<<i)<<endl;
			}
		}
	}
	printf("%.7lf\n",cur.a[1][1]);
	return 0;
}