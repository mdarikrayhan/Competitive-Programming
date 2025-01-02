// LUOGU_RID: 160395931
#include <bits/stdc++.h>
using namespace std;
int n,m,t;
struct Node
{
   int x,y;
}a[10001];
int len[10001];
int used[10001];
int ans[10001];
bool check(int i,int j)
{
    return len[j]==((abs(a[i-1].x-a[i].x)+abs(a[i-1].y-a[i].y))+(abs(a[i+1].x-a[i].x)+abs(a[i+1].y-a[i].y)));
}
void yuchuli()
{
	a[0].x=a[n].x;
    a[0].y=a[n].y;
    a[n+1].x=a[1].x;
    a[n+1].y=a[1].y;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].y;
    for(int i=1;i<=m;i++)cin>>len[i];
    yuchuli();
    for(int i=1;i<=n;i+=2)
  	{
        int akioi=0;
        for(int j=1;j<=m;j++)
        {
            if(used[j]==false&&check(i,j)==true)
            {
                akioi=1;
                used[j]=1;
                ans[i]=j;
                break;
            }
        }
        if(akioi==false)
        {
            t=1;
            break;
        }
    }
    if(t==false)
    {
    	printf("YES\n");
        for(int lxl=1;lxl<=n;lxl++)
  		{
     	  	if(lxl==1)printf("%d",(ans[lxl]?ans[lxl]:-1));
    	   	else printf(" %d",(ans[lxl]?ans[lxl]:-1));
   		}
    }
    else
    {
        memset(used,0,sizeof(used));
        memset(ans,0,sizeof(ans));
        for(int i=2;i<=n;i+=2)
        {
            int akioi=0;
            for(int j=1;j<=m;j++)
  			{
           		if(used[j]==false&&check(i,j)==true)
  				{
                    akioi=1;
                    used[j]=1;
                    ans[i]=j;
                    break;
                }
            }
            if(akioi==false)
 			{
                printf("NO\n");
                return 0;
            }
        }
        printf("YES\n");
   		for(int lxl=1;lxl<=n;lxl++)
  		{
       		if(lxl==1)printf("%d",(ans[lxl]?ans[lxl]:-1));
      	  	else printf(" %d",(ans[lxl]?ans[lxl]:-1));
   		}
    }
    return 0;
}