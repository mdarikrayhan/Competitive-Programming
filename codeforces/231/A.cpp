#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int T = 1,cnt=0;
cin >> T;
for (int i = 1; i <= T; i++)
{
    int a,b,c;
    cin>>a>>b>>c;
    int sum=a+b+c;
    if(sum>=2)
    {
        cnt++;
    }
}
cout<<cnt<<nl;
return 0;
}