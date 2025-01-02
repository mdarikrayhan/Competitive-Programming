#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=1e5+10;
int n;
char s[N];
int a[N],ans[N];
bool solve(int l,int r)
{
    int L=l,R=r;
    for(int i=1;i<=n;i++)a[i]=s[i]-'0';
    while(l<=r)
    {
        int x=0;
        if(a[l-1]>1)return 0;
        if(l==r){
            x+=a[l-1]*10+a[l];
            if(x%2!=0)return 0;
            ans[l]=x/2;
        }
        else
        {
            int x=a[l-1]*10+a[r];
            if(a[r]==9&&a[l-1]==1&&a[l]==0)
            {
                ans[l]=4,ans[r]=5;
                a[l]=1;
            }
            else
            {
                if((x==0&&l==L)||x==19)return 0;
                if(x>=10)ans[l]=9,ans[r]=x-9;
                else if(x)ans[l]=x,ans[r]=0;
                else ans[l]=0,ans[r]=0;
                if(a[l-1])
                {
                    if(a[l]<a[r])return 0;
                    a[l]-=a[r];
                    int p=-1;
                    for(int i=r-1;i>=l;i--)
                        if(a[i]){
                            p=i;
                            break;
                        }
                    if(p==-1)return 0;
                    a[p]--;
                    for(int i=p+1;i<r;i++)a[i]=9;
                }
                else{
                    if(a[l]<a[r])return 0;
                    a[l]-=a[r];
                }
            }
            if(l+1==r&&a[l]!=0)return 0;
        }
        l++,r--;
    }
    for(int i=L;i<=R;i++)printf("%d",ans[i]);
    return 1;
}
int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    if(solve(1,n))return 0;
    if(n>1&&solve(2,n))return 0;
    printf("0\n");
    return 0;
}
  	     	    				 			  	  	  	