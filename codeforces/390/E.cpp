// LUOGU_RID: 157084926
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=4e6+10;
int n,m,w;
template<class T>  
struct Tree
{  
    ll c[2][N];  
    int maxn;  
    void init(int x)
	{  
        maxn = x+10;
		memset(c,0,sizeof c);  
    }  
    inline int lowbit(int x)
	{ 
		return x&-x; 
	}  
    ll sum(ll *b,int x)
	{  
        ll ans=0;  
        if (x==0)ans=b[0];  
        while (x)
		{
			ans+=b[x],x-=lowbit(x);  
		}
        return ans;  
    }  
    void change(ll *b,int x,ll value)
	{  
        if (x==0)b[x]+=value,x++;  
        while (x<=maxn)b[x]+=value,x+=lowbit(x);  
    }  
    ll get_pre(int r)
	{  
        return sum(c[0],r)*r+sum(c[1],r);  
    }  
    void add(int l,int r,ll value)
	{  
        change(c[0],l,value);  
        change(c[0],r+1,-value);  
        change(c[1],l,value*(-l+1));  
        change(c[1],r+1,value*r);  
    }  
    ll get(int l, int r)
	{  
        return get_pre(r)-get_pre(l-1);  
    }  
};
Tree<ll> x, y;  
int main()
{
	scanf("%d%d%d",&n,&m,&w);
	x.init(n); 
	y.init(m); 
	int tmp;
	ll all=0;
	while(w--)
	{
		scanf("%d", &tmp);
		int x1,x2,y1,y2,v;
		if(tmp == 0)
		{
			scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&v);
			all+=v*(x2-x1+1)*(y2-y1+1);
			x.add(x1,x2,v*(y2-y1+1));
			y.add(y1,y2,v*(x2-x1+1));
		}
		if(tmp == 1)
		{
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			printf("%I64d\n",y.get(1,y2)-y.get(1,y1-1)-(all-x.get(1,x2)+x.get(1,x1-1)));	
		}
	}
	return 0;
}