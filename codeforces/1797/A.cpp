#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int T = 1;
cin >> T;
for (int i = 1; i <= T; i++)
{
    long long n,m;
    cin>>n>>m;
    long long ans1=0,ans2=0;
    long long x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    if(x1+1<=n&y1<=m)
    {
        ans1+=1;
    }
    if(x1-1>=1&y1<=m)
    {
        ans1+=1;
    }
    if(x1<=n&y1+1<=m)
    {
        ans1+=1;
    }
    if(x1<=n&y1-1>=1)
    {
        ans1+=1;
    }

    if(x2+1<=n&y2<=m)
    {
        ans2+=1;
    }
    if(x2-1>=1&y2<=m)
    {
        ans2+=1;
    }
    if(x2<=n&y2+1<=m)
    {
        ans2+=1;
    }
    if(x2<=n&y2-1>=1)
    {
        ans2+=1;
    }
   cout<<min(ans1,ans2)<<nl;

}
return 0;
}