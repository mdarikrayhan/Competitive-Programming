#include<bits/stdc++.h>
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
#define ll long long
#define pip pair<int,pii>
using namespace std;
const int N=22;
const int mod=1e9+7;
int n,c,w[N][N],to[N];
pip p[N*N];
int main()
{
	cin>>n>>c;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>w[i][j];
	int tot=0;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(w[i][j])
				p[tot++]=mp(w[i][j],mp(i,j));
	sort(p,p+tot);int ans=1e9;
	for(int i=1;i<(1<<n);i++)
	{
		bool ok=1;int cur=c*__builtin_popcount(i);
		for(int j=0;j<n;j++)to[j]=w[0][j]*((i&1)||((i>>j)&1));to[0]=-2;
		for(int j=1;j<n;j++)
		{
			int mi=-1;
			for(int k=0;k<n;k++)
				if(to[k]>0&&(mi==-1||to[k]<to[mi]))
					mi=k;
			if(mi==-1){ok=0;break;}
			else{
			//	cout<<mi<<" "<<to[mi]<<"?\n";
				cur+=to[mi];to[mi]=-2;
				for(int k=0;k<n;k++)
					if(((i>>k)&1)||((i>>mi)&1))
						if(to[k]==0||(to[k]!=-2&&w[mi][k]<to[k]&&w[mi][k]))
							to[k]=w[mi][k];
			}
		}
	//	if(ok&&cur==13)cout<<i<<"\n",exit(0);
		if(ok)ans=min(ans,cur);
	}cout<<ans;
	return 0;
}