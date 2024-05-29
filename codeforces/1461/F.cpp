#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=1e5+10;
int n,a[N],f[30],las[30];
char s[10];
bool vis[N];
int p[N],cnt,Sum[N],Sum2[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    scanf("%s",s+1);
    int m=strlen(s+1);
    if(m==1)
    {
        putchar(a[1]+'0');
        for(int i=2;i<=n;i++)
        putchar(s[1]),putchar(a[i]+'0');
    }
    else if(m==2&&((s[1]=='+'&&s[2]=='-')||(s[2]=='+'&&s[1]=='-'))){
        putchar(a[1]+'0');
        for(int i=2;i<=n;i++)
        putchar('+'),putchar(a[i]+'0');
    }
    else if(m==2&&((s[1]=='*'&&s[2]=='-')||(s[2]=='*'&&s[1]=='-'))){
        putchar(a[1]+'0');
        for(int i=2;i<=n;i++){
            if(a[i]==0)putchar('-');
            else putchar('*');
            putchar(a[i]+'0');
        }
    }
    else
    {
        for(int l=1,r;l<=n;l=r+1)
        {
            r=l;
            if(a[l]==0)continue;
            while(r<n&&a[r+1]!=0)r++;
            bool flag=0;
            ll sum=1,sum2=0;
            int L,R;L=R=0;cnt=0;
            Sum[0]=1;
            for(int i=l;i<=r;i++){
                sum*=a[i];sum2+=a[i];
                if(a[i]!=1){
                    if(!L)L=i;R=i;
                    p[++cnt]=i;
                    Sum[cnt]=sum;
                    Sum2[cnt]=sum2;
                }
                if(sum>1e6)flag=1;
            }
            if(cnt<=1)continue;
            if(flag)
                for(int i=L+1;i<=R;i++)vis[i]=1;
            else{
                memset(f,0,sizeof f);
                for(int i=1;i<=cnt;i++)
                {
                    for(int j=0;j<i;j++)
                    {
                        int x=Sum[i]/Sum[j]-(Sum2[i]-Sum2[j+1]+a[p[j+1]]);
                        if(f[j]+x>=f[i]){
                            f[i]=f[j]+x;
                            las[i]=j;
                        }
                    }
                }
                int now=cnt;
                while(now){
                    int t=las[now];
                    for(int i=p[t+1]+1;i<=p[now];i++)
                        vis[i]=1;
                    now=t;
                }
            }
        }
        putchar(a[1]+'0');
        for(int i=2;i<=n;i++)
        {
            if(vis[i])putchar('*');
            else putchar('+');
            putchar(a[i]+'0');
        }
    }
    return 0;
}
 		 			 	   	  		 		  					  	