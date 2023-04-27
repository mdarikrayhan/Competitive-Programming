#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{ll t;
cin>>t;
while(t--)
{ll n,k;
cin>>n>>k;

k--;
while(k--)
{string x=to_string(n);
sort(x.begin(),x.end());
if(x[0]=='0')break;
n=n+((x[0]-'0')*(x[x.length()-1]-'0'));
}
cout<<n<<endl;
}
}