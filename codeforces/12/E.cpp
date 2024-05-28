#include <stdio.h>

int main()
{
     int n;
     scanf("%d", &n);
     int a[n][n] = {0}, i, j;
     
     for(i=0;i<n;i++)
     {
          for(j=0;j<n;j++)
          {
               if(i+j<n)
               {
                    a[i][j]=i+j;
               }
          }
     }
     for(i=1;i<n/2;i++)
     {
          a[n-1][i]=2*i;
          int k=i+1;
          for(j=n-2;j>=k;j--)
          {
               a[j][n+k-j-2]=i;
               //printf("%d %d %d\n",j,n-j,i);            
          }
     }
     for(i=n/2;i<n;i++)
     {
          a[n-1][i]=2*(i-n/2)+1;
          int k=i+1;
          for(j=n-2;j>=k;j--)
          {
               a[j][n+k-j-2]=i;
              // printf("%d %d %d\n",j,n-j,i);            
          }
          
     }
     for(i=0;i<n;i++)
     {
          a[i][n-1]=a[n-1][i];
     }
     for(i=0;i<n;i++)
     {
          a[i][i]=0;
     }
     for(i=0;i<n;i++)
     {
          for(j=0;j<n;j++)
          {
               printf("%d ",a[i][j]);
          }
          printf("\n");
     }
     
     printf("\n");
     return 0;
}
