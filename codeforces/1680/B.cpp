#include <iostream>
#include <cstdint>
#define pii         pair<int,int>
#define fastIO      ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
using namespace std;
void solve()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,f1=0,flag=0;
        cin>>n>>m;
        char ch[n][m];
        pii p;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>ch[i][j];
                if(!f1&&ch[i][j]=='R')
                {
                    p={i,j};
                    f1=1;
                }
                else
                {
                    if(ch[i][j]=='R')
                    {
                        if(j<p.second)
                        {
                            flag=1;
                        }
                    }
                }
            }
        }
        if(flag)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
}


int32_t main()
{
    fastIO
    solve();
}
 		 	     		  	 			  	  		 			