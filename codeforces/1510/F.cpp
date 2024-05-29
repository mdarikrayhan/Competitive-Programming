// LUOGU_RID: 102151566
#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
const int N=20010;
int n,x,y,_,i,j;
ld L,ans;

struct P {
	ld x,y;
	P(){}
	P(ld _x,ld _y): x(_x),y(_y){}
	ld len(){ return sqrt(x*x+y*y);}
	P operator+(const P &p)const { return P(x+p.x,y+p.y);}
	P operator-(const P &p)const { return P(x-p.x,y-p.y);}
	ld operator*(const P &p)const { return x*p.y-y*p.x;}
	void rot(ld cost,ld sint){
		ld _x=x*cost-y*sint,_y=x*sint+y*cost;
		x=_x,y=_y;
	}
}p[N],I0,I1,I2;

inline ld Fabs(ld x)
{
	return x>=0?x:-x;
}

P work(P F1,P F2,P d,ld r)
{
	ld _=d.len();d.x/=_,d.y/=_;
	ld deltax=F1.x-F2.x,deltay=F1.y-F2.y;
	ld l=(r*r-deltax*deltax-deltay*deltay)/2/(d.x*deltax+d.y*deltay+r);
	return P(F1.x+l*d.x,F1.y+l*d.y);
}

ld work2(P F1,P F2,P P1,P P2,ld r)
{
	ld S=Fabs((P1-F1)*(P2-F1));
	P O=P((F1.x+F2.x)/2,(F1.y+F2.y)/2);
	F1=F1-O,F2=F2-O,P1=P1-O,P2=P2-O;
	ld _=F1.len(),cost=F1.x/_,sint=-F1.y/_;
	F1.rot(cost,sint),F2.rot(cost,sint);
	P1.rot(cost,sint),P2.rot(cost,sint);
	ld a=r/2,c=F1.x,b=sqrt(a*a-c*c);
	S-=Fabs(P1*P2);
	P1.x*=b,P1.y*=a,P2.x*=b,P2.y*=a;
	return(a*b*acos((P1.x*P2.x+P1.y*P2.y)/P1.len()/P2.len())+S)/2;
}

int main()
{
	cin>>n>>_,L=_;
	for(int i=1;i<=n;i++)
		scanf("%d%d",&x,&y),p[i]=p[i+n]=P(x,y);
	for(int i=1;i<=n;i++)
		L-=(p[i]-p[i+1]).len();
	for(int i=2;i<n;i++)
		ans+=(p[i]-p[1])*(p[i+1]-p[1])/2;
	i=1;
	for(j=2;j<=n;j++)
	{
		L+=(p[j]-p[j-1]).len();
		I1=work(p[1],p[j],p[1]-p[n],L);
		I2=work(p[j],p[1],p[j]-p[j+1],L);
		if ((I1-p[1])*(I2-p[1])>0)
			break;
	}
	I0=work(p[1],p[j],p[1]-p[n],L);
	while(i<=n)
	{
		I1=work(p[i],p[j],p[i+1]-p[i],L);
		I2=work(p[j],p[i],p[j]-p[j+1],L);
		if ((I1-p[i])*(I2-p[i])<1e-12)
		{
			ans+=work2(p[i],p[j],I0,I2,L);
			L+=(p[j+1]-p[j]).len(),I0=I2,j++;
		} 
		else 
		{
			ans+=work2(p[i],p[j],I0,I1,L);
			L-=(p[i+1]-p[i]).len(),I0=I1,i++;
		}
	} 
	return printf("%.10lf\n",(double)ans),0;
}