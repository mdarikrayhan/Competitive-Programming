#include<bits/stdc++.h>
#define f(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
const int N=4e2;
int n,cs,l[N],r[N],a[N],si[N],f[N][2][3],v[N][2][3];
int M(int x,int y,int ty){return ty?min(x,y):max(x,y);} 
void D(int e)
{
	if(a[e]!=-1)si[e]=0;
	else{D(l[e]),D(r[e]),si[e]=si[l[e]]+si[r[e]]+1;if(si[r[e]]&1)swap(l[e],r[e]);}
}
int D(int e,int ty,int fg)
{
	if(a[e]!=-1)return a[e];
	if(si[e]==1)return M(a[l[e]],a[r[e]],ty^(fg==2));
	if(v[e][ty][fg]++)return f[e][ty][fg];
	int as,t=si[l[e]]&1;
	if(!fg)
	if(si[e]&1)as=M(D(l[e],ty,t),D(r[e],ty,t),ty);
	else as=M(M(D(l[e],ty,0),D(r[e],!ty,0),!ty),M(D(r[e],ty,1),D(l[e],!ty,1),!ty),ty);
	else
	if(si[e]&1)
	{
		as=D(e,!ty,0);
		if(t||si[r[e]])as=M(M(D(l[e],1^ty^t,0),D(r[e],ty^t,si[l[e]]<2&&fg==1?2:1),!ty),as,ty);
		if(t||si[l[e]])as=M(M(D(r[e],1^ty^t,0),D(l[e],ty^t,si[r[e]]<2&&fg==1?2:1),!ty),as,ty);
	}
	else as=M(D(r[e],ty,0),D(l[e],ty,!si[r[e]]&&fg==1?2:1),ty);
	return f[e][ty][fg]=as;
}
signed main()
{
	scanf("%d",&cs);
	while(cs--)
	{
		memset(v,0,sizeof(v));
		scanf("%d",&n);
		f(i,0,n-1){scanf("%d",&a[i]);if(a[i]==-1)scanf("%d%d",&l[i],&r[i]);}
		D(0);cout<<D(0,0,0)<<'\n';
	}
	return 0;
}