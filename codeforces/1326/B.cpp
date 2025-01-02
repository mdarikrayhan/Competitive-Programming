#include <bits/stdc++.h>
 
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    long long a[n];
    for(int i=0;i<n;i++)
    {
        long long c;
        scanf("%lld",&c);
        a[i]=c;
    }
    long long s[n];
    s[0]=a[0];
    long long maximum=s[0];
    for(int i=1;i<n;i++)
    {
        s[i]=max(s[i-1],maximum)+a[i];
        maximum=max(maximum,s[i]);
    }
    for(int i=0;i<n;i++)
    {
        printf("%lld",s[i]);
        if(i!=n-1)
        {
            printf(" ");
        }
    }
    return 0;
}