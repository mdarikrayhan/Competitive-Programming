#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int kmp[2000005];
signed main()
{
ios::sync_with_stdio(false);
cin.tie(0);
string a,b;
int n;
cin >> n >> a >> b;
for(int i=0;i<n-1;i++)
{
if(a[i]=='N') a[i]='S';
else if(a[i]=='W') a[i]='E';
else if(a[i]=='E') a[i]='W';
else if(a[i]=='S') a[i]='N';
}
reverse(a.begin(),a.end());
a+=b;
a=' '+a;
int nw=0;
n=a.size()-1;
for(int i=2;i<=n;i++)
{
while(nw&&a[nw+1]!=a[i]) nw=kmp[nw];
if(a[nw+1]==a[i]) ++nw;
kmp[i]=nw;
}
if(kmp[n]) cout << "NO";
else cout << "YES";
return 0;
}