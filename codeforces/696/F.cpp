#include<iostream>
#include<cmath>
using namespace std;
const int N=1005;
struct Node
{
	double x,y;
	Node operator - (Node A) {return (Node){x-A.x,y-A.y};}
	double operator * (Node A) {return x*A.y-y*A.x;}
	double dis() {return sqrt(x*x+y*y);}
}O[N][N],t[N],E[N];
int n,yes[N][N];
double Or[N][N];
Node Mid(Node a,Node b) {return (Node){(a.x+b.x)/2,(a.y+b.y)/2};}
double disline(int i,Node A) {return abs(E[i]*(A-t[i])/E[i].dis());}
int ch(int R) {return R%n?R%n:n;}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%lf%lf",&t[i].x,&t[i].y);
	for(int i=1;i<=2*n;i++) t[n+i]=t[i];
	for(int i=1;i<=3*n;i++) E[i]=t[i+1]-t[i];
//	for(int i=1;i<=n;i++) printf("E[%d]:(%.2f,%.2f)\n",i,E[i].x,E[i].y);
	for(int L=1;L<=n;L++)
		for(int R=L,nw=L;R==L||E[L]*E[R]>0;R++)
		{
			while(nw<R&&disline(L,t[nw+1])<disline(R,t[nw+1])) ++nw;
//			printf("L=%d,R=%d,nw=%d\n",L,R,nw);
			Node le=t[nw],ri=t[nw+1];
			for(int j=1;j<=42;j++)
			{
				Node mid=Mid(le,ri);
				if(disline(L,mid)<disline(R,mid)) le=mid;
				else ri=mid;
			}
			Node P=Mid(le,ri);
			O[L][ch(R)]=P;
			Or[L][ch(R)]=max(disline(L,P),disline(R,P));
			yes[L][ch(R)]=1;
		}
	double r=1e7;Node o1,o2;
	for(int L=1;L<=n;L++)
		for(int R=L;R<=L+n;R++)
			if(yes[L][ch(R)]&&yes[ch(R+1)][ch(L-1+n)])
			{
				double newr=max(Or[L][ch(R)],Or[ch(R+1)][ch(L-1+n)]);
				if(newr<r) r=newr,o1=O[L][ch(R)],o2=O[ch(R+1)][ch(L-1+n)];
			}
	printf("%.10f\n%.10f %.10f\n%.10f %.10f\n",r,o1.x,o1.y,o2.x,o2.y);
}