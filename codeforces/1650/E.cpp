/*
Tips:
你数组开小了吗？
你MLE了吗？
你觉得是贪心，是不是该想想dp？
一个小时没调出来，是不是该考虑换题？
打 cf 不要用 umap！！！

记住，rating 是身外之物。

该冲正解时冲正解！

Problem:

算法：

思路：

*/
#include<bits/stdc++.h>
using namespace std;
//#define map unordered_map
#define forl(i,a,b) for(register long long i=a;i<=b;i++)
#define forr(i,a,b) for(register long long i=a;i>=b;i--)
#define forll(i,a,b,c) for(register long long i=a;i<=b;i+=c)
#define forrr(i,a,b,c) for(register long long i=a;i>=b;i-=c)
#define lc(x) x<<1
#define rc(x) x<<1|1
#define mid ((l+r)>>1)
#define cin(x) scanf("%lld",&x)
#define cout(x) printf("%lld",x)
#define lowbit(x) (x&-x)
#define pb push_back
#define pf push_front
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl '\n'
#define QwQ return 0;
#define ll long long
#define ull unsigned long long
#define lcm(x,y) x/__gcd(x,y)*y
#define Sum(x,y) 1ll*(x+y)*(y-x+1)/2
#define aty cout<<"Yes\n";
#define atn cout<<"No\n";
#define cfy cout<<"YES\n";
#define cfn cout<<"NO\n";
#define xxy cout<<"yes\n";
#define xxn cout<<"no\n";
#define printcf(x) x?cout<<"YES\n":cout<<"NO\n";
#define printat(x) x?cout<<"Yes\n":cout<<"No\n";
#define printxx(x) x?cout<<"yes\n":cout<<"no\n";
ll t;
ll n,m;
ll a[200010],b[200010],cz2[200010];
struct node{
	ll x,id;
}cz[200010];
bool cmp(node x,node y){
	return x.x<y.x;
}
ll f(ll x)// del x 
{
	ll k=0;
	forl(i,1,n)
		 if(i!=x)
		 	b[++k]=a[i];
	ll ans=0;
	forl(i,1,n-1)
		cz2[i]=b[i]-b[i-1];
	forl(i,1,n-1)
		ans=max(ans,cz2[i]/2);
	ans=max(ans,m-b[n-1]);
	sort(cz2+1,cz2+n);
//	cout<<ans<<' '<<cz2[1]<<endl;
	return min(ans,cz2[1]);
}
void solve()
{
	ll ans=0;
	cin>>n>>m;
	forl(i,1,n)
		cin>>a[i],cz[i].x=a[i]-a[i-1],cz[i].id=i;
	sort(cz+1,cz+1+n,cmp);
	ans=max(ans,f(cz[1].id));
	ans=max(ans,f(max(cz[1].id-1,1ll)));
	ans=max(ans,f(min(cz[1].id+1,n)));
	cout<<ans-1<<endl;
}
int main()
{
	IOS;
	t=1;
	cin>>t;
	while(t--)
		solve();
    /******************/
	/*while(L<q[i].l) */
	/*    del(a[L++]);*/
	/*while(L>q[i].l) */
	/*    add(a[--L]);*/
	/*while(R<q[i].r) */
	/*	  add(a[++R]);*/
	/*while(R>q[i].r) */
	/*    del(a[R--]);*/
    /******************/
	QwQ;
}
