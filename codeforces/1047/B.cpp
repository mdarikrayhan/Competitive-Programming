#include<stdio.h>
int a[100000][2];
int s[100000];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[1][0]);
        scanf("%d",&a[i][1]);
        s[i]=a[1][0]+a[i][1];
    }
    int max=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]>max)
        max=s[i];
    }
    printf("%d",max);
    return 0;
}//submitTime:1715762715033
