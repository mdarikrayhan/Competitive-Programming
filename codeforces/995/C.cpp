#include<bits/stdc++.h>
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
using namespace std;
double dis(long long x,long long y)
{
    return sqrt((double)x*x+(double)y*y);
}
struct node
{
    int x,y,id;
}a[1000003];
int ans[1000003];
int main()
{
    srand(time(0));
    int n=read();
    int x=0,y=0;
    for(int i=1; i<=n; i++) a[i].x=read(),a[i].y=read(),a[i].id=i;
    while(1)
    {
        x=0,y=0;
        for(int i=1; i<=n; i++)
        {
            int p=a[i].x,q=a[i].y;
            if(dis(x+p,y+q)<dis(x-p,y-q)) x+=p,y+=q,ans[a[i].id]=1; else x-=p,y-=q,ans[a[i].id]=-1;
        }      
        if(dis(x,y)<=1.5e6) 
        {
            for(int i=1; i<=n; i++) printf("%d ",ans[i]);
            return 0;
        }
        random_shuffle(a+1,a+n+1);
    }
    return 0;
}