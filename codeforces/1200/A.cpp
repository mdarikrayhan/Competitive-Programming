#include <bits/stdc++.h>
using namespace std;
int n;
char x[100010];
bool vis[10];
int main()
{
    cin>>n;int a;
    for(int i=0;i<n;i++)
    {
        cin>>x[i];
        if(x[i]=='L')
            for(a=0;a<10;a++)
            {
                while(vis[a]==1) a++;
                vis[a]=1;
                break;
            }
        if(x[i]=='R')
            for(a=9;a>=0;a--)
            {
                while(vis[a]==1) a--;
                vis[a]=1;
                break;
            }
        if(x[i]>='0'&&x[i]<='9') a=x[i]-'0',vis[a]=0;
    }
    for(int i=0;i<10;i++) cout<<vis[i];
    return 0;
}
