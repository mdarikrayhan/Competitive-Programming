#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define nmax 200007
#define fi first
#define se second
#define ll long long
ll t=1,n,m=0,i=0,j=0,d=0,x=0,a[nmax],b[nmax],y=0;
string s;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>s;
    n=s.size();
    if(n%2==1){cout<<-1;return 0;}
    for(i=0;i<s.size();++i)
    {
        if(s[i]=='L')x++;
        if(s[i]=='R')x--;
        if(s[i]=='U')y++;
        if(s[i]=='D')y--;
    }
    d=abs(x)/2+abs(y)/2;
    x=(x%2+2)%2;
    y=(y%2+2)%2;
    if(x>0)d++;
    cout<<d;
}
