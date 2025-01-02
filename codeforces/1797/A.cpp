#include<bits/stdc++.h>
using namespace std;
int n,m;
int check(int x,int y)
{
    int cnt=4;
    if(x==1||x==n) cnt--;
    if(y==1||y==m) cnt--;
    return cnt;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        int ans=4;
        ans=min(check(x1,y1),ans);
        ans=min(ans,check(x2,y2));
        cout<<ans<<endl;
    }

    return 0;
}

