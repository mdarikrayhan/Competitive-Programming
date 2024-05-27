// LUOGU_RID: 159820255
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
const int M=31;
int n,a[N],lx[N],rx[N],lt[N],rt[N],ap[M];
long long ans=0;
stack<int> stk;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
//	stk.push(0);
	for(int i=1;i<=n;i++)
	{
		while(!stk.empty()&&a[stk.top()]<a[i]) stk.pop();
		if(!stk.empty()) lx[i]=stk.top()+1;
		else lx[i]=1;
		stk.push(i);
	}
	while(!stk.empty()) stk.pop();
//	stk.push(n+1);
	for(int i=n;i>=1;i--)
	{
		while(!stk.empty()&&a[stk.top()]<=a[i]) stk.pop();
		if(!stk.empty()) rx[i]=stk.top()-1;
		else rx[i]=n;
		stk.push(i);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=29;j++)
			if((a[i]>>j)&1) ap[j]=i;
			else lt[i]=max(lt[i],ap[j]);
	}
	for(int i=0;i<=29;i++) ap[i]=n+1;
	for(int i=n;i>=1;i--)
	{
		rt[i]=n+1;
		for(int j=0;j<=29;j++)
			if((a[i]>>j)&1) ap[j]=i;
			else rt[i]=min(rt[i],ap[j]);
	}
	for(int i=1;i<=n;i++)
	{
	//	cout<<lx[i]<<" "<<rx[i]<<" "<<lt[i]<<" "<<rt[i]<<endl;
		if(lx[i]<=lt[i]&&rt[i]<=rx[i])
			ans+=1ll*(rx[i]-i+1)*(i-lx[i]+1)-1ll*(rt[i]-i)*(i-lt[i]);
			else	if(lx[i]<=lt[i]) ans+=1ll*(lt[i]-lx[i]+1)*(rx[i]-i+1);
					else if(rt[i]<=rx[i]) ans+=1ll*(i-lx[i]+1)*(rx[i]-rt[i]+1);
	//	cout<<ans<<endl;
	}
	printf("%lld\n",ans);
	return 0;
}//11:16