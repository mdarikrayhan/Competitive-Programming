#include <bits/stdc++.h>
using namespace std;
string s[8];
void dfs(int x,int y,int k)
{
	if (k>=7) {cout<<"WIN"; exit(0);}
	for (int i=-1;i<=1;i++)
		for (int j=-1;j<=1;j++)
		{
			int xx=x+i,yy=y+j;
			if (xx<0 || yy>7 || yy<0|| xx>7) continue;
			if (xx-k>=0 && s[xx-k][yy]=='S') continue;
			if (xx-k>=1 && s[xx-k-1][yy]=='S') continue;
			dfs(xx,yy,k+1);
		}
}
int main()
{
	for (int i=0;i<8;i++) cin>>s[i];
	dfs(7,0,0);
	cout<<"LOSE";
}
