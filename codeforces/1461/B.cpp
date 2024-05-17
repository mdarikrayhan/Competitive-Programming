#include <bits/stdc++.h>
typedef  long long int ll;
 
using namespace std;

 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int arr[n][m+1];
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                char ch;
                cin>>ch;
                if(ch=='.')
                {
                    arr[i][j]=0;
                }
                else
                {
                    arr[i][j]=1;
                }
            }
        }
        for(int j=0;j<n;j++)
            {
                arr[j][0]=0;
            }
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                arr[i][j]=arr[i][j-1]+arr[i][j];
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                int c=0;
                for(int k=0;k<n;k++)
    {
        
        if(j+k<=m && j-k>0 && i+k <n && (arr[i+k][j+k]-arr[i+k][j-k-1])==(2*k+1))
        {
            c++;
        }
        else
        break;
    }
                
                
                    ans+=c;
            }
        }
        cout<<ans<<endl;
    }






}