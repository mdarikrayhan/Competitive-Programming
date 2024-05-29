#include<bits/stdc++.h>
#define f(i,x,y) for(int i=x;i<=y;i++)
#define pb push_back
#define ll long long
using namespace std;
const int N=4e6,I=1e6;
int n,m,q,a[N],b[N],mnb,mna,mxb,op,p,x,c,k,trc[N];
ll s,trs[N],as,s1;
multiset<int>A,B;
void J(int e,int k=1){int e1=e;++e;while(e<=I)trs[e]+=e1*k,trc[e]+=k,e+=e&-e;}
void Q(int e){++e;s=c=0;while(e>0)s+=trs[e],c+=trc[e],e-=e&-e;}
ll Q1(int e,int fg=1){Q(e-k-1);return 1ll*(e-k)*(m-n-c)+s+1ll*(n-fg)*max(e-k-min(mna,mnb),0);}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	f(i,1,n)scanf("%d",&a[i]),A.insert(a[i]),s1+=a[i];
	f(i,1,m)scanf("%d",&b[i]),B.insert(b[i]),s1-=b[i],J(b[i]);
	while(q--)
	{
		scanf("%d",&op);
		if(op<=2)
		{
			scanf("%d%d",&p,&x);
			if(op==1)s1+=x-a[p],A.erase(A.find(a[p])),A.insert(a[p]=x);
			else J(b[p],-1),J(x),s1+=b[p]-x,B.erase(B.find(b[p])),B.insert(b[p]=x);
		}
		else
		{
			scanf("%d",&k);
			mnb=*B.begin(),mxb=*B.rbegin(),mna=*A.begin();
			as=max(max(Q1(mxb,0),1ll*(mnb-k)*(m-n)+1ll*n*max(mnb-k-mna,0)),Q1(mna));
			auto it=A.upper_bound(mxb+k);
			if(it!=A.end()&&*it!=mna)as=max(Q1(*it),as);
			if(it!=A.begin()&&*--it!=mna)as=max(Q1(*it),as);
			cout<<as+s1<<'\n';
		}
	}
    return 0;
}