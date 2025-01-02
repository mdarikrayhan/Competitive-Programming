#include<iostream>
using namespace std;
short n,w[2010],s[2010],F[2010][20010];
short f[2][2010][20010],g[2][2010][20010];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
		s[i]=s[i-1]+w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int lim=w[min(int(n),i+1)];
		for(int j=0,k=i;j<=lim;j++)
		{
			while(k&&s[i]-s[k]<=j)
			{
				k--;
			}
			F[i][j]=k;
		}
	}
	for(int i=n;i;i--)
	{
		for(int j=i;j<=n;j++)
		{
			int lim=w[min(int(n),j+1)];
			for(int k=0;k<=lim;k++)
			{
				if(i==j)
				{
					f[i&1][j][k]=w[i];
					g[i&1][j][k]=0;
					continue;
				}
				int t=F[j][k];
				f[i&1][j][k]=max(
				(w[i]>k?g[i+1&1][j][w[i]-k]:f[i+1&1][j][k-w[i]])+w[i],
				t<i?s[j]-s[i-1]:(g[i&1][t][s[j]-s[t]-k]+s[j]-s[t]));
				t+=(s[j]-s[t+1]==k);
				g[i&1][j][k]=min(
				w[i]>=k?f[i+1&1][j][w[i]-k]:g[i+1&1][j][k-w[i]],
				t<i?short(s[j]-s[i-1]):f[i&1][t][s[j]-s[t]-k]);
			}
		}
	}
	cout<<f[1][n][0]<<" "<<s[n]-f[1][n][0]<<endl;
	return 0;
}
  		   	 	  			   	  	 			 	 	