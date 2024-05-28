// LUOGU_RID: 160561322
#include<bits/stdc++.h>
using namespace std;

constexpr int maxn=300002;

int m,a[maxn],dig[maxn];
set<int,greater<int>>act;
set<int,greater<int>>::iterator pos[maxn];

void vAdd(int i)
{
	for(;;i++)
	{
		if(dig[i]==0) pos[i]=act.insert(i).first;
		else if(dig[i]==-1) act.erase(pos[i]);
		dig[i]++;
		if(dig[i]==m)
		{
			dig[i]=0;
			act.erase(pos[i]);
		}
		else break;
	}
}

void vDel(int i)
{
	for(;;i++)
	{
		if(dig[i]==0) pos[i]=act.insert(i).first;
		else if(dig[i]==1) act.erase(pos[i]);
		dig[i]--;
		if(dig[i]==-m)
		{
			dig[i]=0;
			act.erase(pos[i]);
		}
		else break;
	}
}

int main()
{
	ios::sync_with_stdio(false),cin.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		int n,q,i,j;
		cin>>n>>m>>q;
		int len=n+20;
		memset(dig+1,0,len*4);
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
			dig[a[i]]++;
			for(j=a[i];dig[j]==m;dig[j]=0,dig[j+1]++,j++);
		}
		act.clear();
		for(i=1;i<=len;i++) if(dig[i]) pos[i]=act.insert(act.begin(),i);
		while(q--)
		{
			cin>>i;
			vDel(a[i]);
			cin>>a[i];
			vAdd(a[i]);
			for(i=*act.begin();dig[i]==1&&dig[i-1]<0;i--)
			{
				act.erase(act.begin());
				dig[i]=0;
				dig[i-1]+=m;
			}
			if(dig[i]==1&&(act.size()==1||dig[*next(act.begin())]<0)) cout<<i<<' ';
			else cout<<i+1<<' ';
		}
		cout<<'\n';
	}
	return 0;
}
