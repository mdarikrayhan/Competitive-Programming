#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=2e5+10;
int n,a[N],ans;
int main()
{
    // freopen("1.in","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int l=1,r;l<=n;l=r+1){
        ans++;r=l;
        int A=0,B=0,cnt=(a[l]!=-1);
        if(cnt)A=l;
        while(r<n&&cnt!=2){
            cnt+=(a[++r]!=-1);
            if(a[r]!=-1){
                if(cnt==1)A=r;
                else B=r;
            }
        }
        if(cnt==2)
        {
            if((a[B]-a[A])%(B-A)!=0)r--;
            else{
                ll k=(a[B]-a[A])/(B-A),b=a[A]-A*k;
                if(1ll*k*l+b<=0)r--;
                else
                while(r<n&&(a[r+1]==-1||a[r+1]==1ll*k*(r+1)+b)&&1ll*k*(r+1)+b>0)r++;
            }
        }
    }
    printf("%d",ans);
    return 0;
}
  	  	  				 		 	     	 				