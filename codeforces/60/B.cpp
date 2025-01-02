#include<bits/stdc++.h>
using namespace std;

char a[15][15][15];
int dx[]={0,0,0,0,1,-1};
int dy[]={0,0,1,-1,0,0};
int dh[]={1,-1,0,0,0,0};

int k,n,m;
int ans=0;

void dfs(int h,int x,int y)
{
 ans++;
 a[h][x][y]='#';
 for(int i=0;i<6;i++)
	{
		int hh=h+dh[i],xx=x+dx[i],yy=y+dy[i];
		if(hh<=k&&hh>=1&&xx>=1&&xx<=n&&yy>=1&&yy<=m&&a[hh][xx][yy]=='.')
			dfs(hh,xx,yy);
	}
}

int main()
{
    cin>>k>>n>>m;
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int p=1;p<=m;p++)
            {
                cin>>a[i][j][p];
            }
        }
    }
 int x,y;
 cin>>x>>y;
 dfs(1,x,y);
 cout<<ans<<endl;
    return 0;
}