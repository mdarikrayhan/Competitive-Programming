#include<bits/stdc++.h>
using namespace std;
bitset<2001>b[2000];
string s;
int cur[1000][2][2],p[1000];
string op,cvd;
int ans[2000];
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int n,k,m,i,j,c=0,x,cp;
	cin>>n>>k;
	for(i=0;i<n;i++)
	{
		cur[i][0][0]=1;
		cur[i][1][1]=1;
	}
	for(i=0;i<k;i++)
	{
		cin>>op>>m;
		for(j=0;j<m;j++)
		{
			cin>>p[j];
			p[j]--;
		}
		if(op=="mix")
		{
			cin>>cvd;
			for(j=0;j<m;j++)
			{
				x=p[j];
				if(cur[x][0][0])b[c][x*2]=1;
				if(cur[x][1][0])b[c][x*2+1]=1;
			}
			if(cvd=="R"||cvd=="B")b[c][n*2]=1;
			c++;
			for(j=0;j<m;j++)
			{
				x=p[j];
				if(cur[x][0][1])b[c][x*2]=1;
				if(cur[x][1][1])b[c][x*2+1]=1;
			}
			if(cvd=="R"||cvd=="Y")b[c][n*2]=1;
			c++;
		}
		if(op=="RY")
		{
			for(j=0;j<m;j++)
			{
				x=p[j];
				cur[x][0][0]^=cur[x][0][1];
				cur[x][1][0]^=cur[x][1][1];
			}
		}
		if(op=="RB")
		{
			for(j=0;j<m;j++)
			{
				x=p[j];
				cur[x][0][1]^=cur[x][0][0];
				cur[x][1][1]^=cur[x][1][0];
			}
		}
		if(op=="YB")
		{
			for(j=0;j<m;j++)
			{
				x=p[j];
				swap(cur[x][0][0],cur[x][0][1]);
				swap(cur[x][1][0],cur[x][1][1]);
			}
		}
	}
	cp=0;
	for(i=0;i<c;i++)
	{
		if(cp==n*2)break;
		if(b[i][cp]==0)
		{
			for(j=i+1;j<c;j++)
			{
				if(b[j][cp]==1)
				{
					swap(b[i],b[j]);
					break;
				}
			}
		}
		if(b[i][cp]==0)
		{
			cp++;
			i--;
			continue;
		}
		for(j=i+1;j<c;j++)
		{
			if(b[j][cp]==1)b[j]^=b[i];
		}
	}
	for(i=c-1;i>-1;i--)
	{
		for(cp=0;cp<n*2;cp++)
		{
			if(b[i][cp]==1)break;
		}
		if(cp==n*2)
		{
			if(b[i][n*2]==1)
			{
				cout<<"NO\n";
				return 0;
			}
			continue;
		}
		for(j=cp+1;j<n*2;j++)
		{
			if(b[i][j]==1&&ans[j]==1)b[i][n*2]=b[i][n*2]^1;
		}
		if(b[i][n*2]==1)ans[cp]=1;
		else ans[cp]=0;
	}
	cout<<"YES\n";
	for(i=0;i<n;i++)
	{
		if(ans[i*2]==1&&ans[i*2+1]==1)cout<<'R';
		if(ans[i*2]==1&&ans[i*2+1]==0)cout<<'B';
		if(ans[i*2]==0&&ans[i*2+1]==1)cout<<'Y';
		if(ans[i*2]==0&&ans[i*2+1]==0)cout<<'.';
	}
	cout<<'\n';
	return 0;
}