#include<cstdio>
#include<vector>
#include<algorithm>
#define pb push_back
#define inf 2000000000
using namespace std;
int n,d,s,c[100005],f[100005],l[100005],k;
vector<int> a,b;
int main()
{
	scanf("%d%d%d",&n,&d,&s);
	for (int i=0;i<n;i++)
	{
		scanf("%d%d%d",&c[i],&f[i],&l[i]);
		if (c[i])k++;
		if (l[i]>=d)
		if (c[i]) a.pb(f[i]); else b.pb(f[i]);
	}
	sort(a.begin(),a.end());a.pb(inf);
	sort(b.begin(),b.end());b.pb(inf);
	int Sum=0,Ans=0,sum=0,ans=0;
	for (int i=0;b[i]<=s-Sum;Sum+=b[i++],Ans++);
	if (a[0]<=s)
	{
		int tot=1;
		for (int i=0;i<n;i++)if (c[i])tot=min(n,tot+c[i]-1);
		int l=1,r=0; sum=a[0]; ans=min(k+tot,n);
		while (ans<n)
		{
			int tmp=min(a[l],b[r]);
			if (tmp>s-sum)break;
			ans++; sum+=tmp;
			if(a[l]<=b[r])l++; else r++;
		}
		if (ans>Ans||(ans==Ans&&sum<Sum)){Ans=ans; Sum=sum;} 
	}
	printf("%d %d",Ans,Sum);
	return 0;
}