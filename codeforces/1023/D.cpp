// LUOGU_RID: 159022766
#include <cstdio>
#define ls(p) ((p)<<1)
#define rs(p) (((p)<<1)|1)
const int Nx=200010;
int N,Q,A[Nx],al[Nx],ar[Nx],sl[Nx],sr[Nx],final[Nx],p0;
int col[4*Nx];
void adtag(int p,int ca){col[p]=ca;}
void pushdown(int p)
{
	if(!col[p])
		return;
	adtag(ls(p),col[p]);
	adtag(rs(p),col[p]);
	col[p]=0;
}
void update(int ll,int rr,int p,int L,int R,int ca)
{
	if(L<=ll&&R>=rr)
	{
		adtag(p,ca);
		return;
	}
	pushdown(p);
	int mid=(ll+rr)>>1;
	if(L<=mid)
		update(ll,mid,ls(p),L,R,ca);
	if(R>mid)
		update(mid+1,rr,rs(p),L,R,ca);
}
int query(int ll,int rr,int p,int pos)
{
	if(ll==rr)
		return col[p];
	pushdown(p);
	int mid=(ll+rr)>>1;
	if(pos<=mid)
		return query(ll,mid,ls(p),pos);
	else
		return query(mid+1,rr,rs(p),pos);
}
int main()
{
	scanf("%d%d",&N,&Q);
	int i,j,k;
	sl[0]=1;sr[N+1]=N;
	for(i=1;i<=N;i++)
	{
		scanf("%d",&A[i]);
		if(A[i]==0&&p0==0)
			p0=i;
		if(al[A[i]]==0)
			al[A[i]]=i;
		sl[i]=(A[i-1]==0)?sl[i-1]:i;
	}
	for(i=N;i>=1;i--)
	{
		if(ar[A[i]]==0)
			ar[A[i]]=i;
		sr[i]=(A[i+1]==0)?sr[i+1]:i;
	}
	for(i=1;i<=Q;i++)
	{
		if(al[i]==0)
		{
			if(i!=Q)
				continue;
			if(p0==0)
			{
				printf("NO\n");
				return 0;
			}
			al[i]=ar[i]=p0;
		}
		update(1,N,1,sl[al[i]],sr[ar[i]],i);
	}
	for(i=1;i<=N;i++)
	{
		final[i]=query(1,N,1,i);
		if(A[i]!=0&&A[i]!=final[i])
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	for(i=1;i<=N;i++)
		printf("%d ",final[i]);
	printf("\n");
}