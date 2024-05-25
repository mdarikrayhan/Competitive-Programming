#include<bits/stdc++.h>
#define rp(n) for(decltype(n) i=0;i<n;i++)
#define rp2(n,j) for(decltype(n) j=0;j<n;j++)
#define ll long long int
#define set(a,n,k) for(int lambda=0;lambda<n;lambda++){a[lambda]=k;}
#define out(a,n,k) for(int lambda=0;lambda<n;lambda++){cout<<a[lambda]<<k;}
#define ain(a,n) for(int lambda=0;lambda<n;lambda++){cin>>a[lambda];}
#define v1(type,x) type x;cin>>x;
#define v2(type,x,y) type x,y;cin>>x>>y;
#define v3(type,x,y,z) type x,y,z;cin>>x>>y>>z;
#define remax(maxo,new) maxo=max(maxo,new);
#define endl '\n'
using namespace std;
int main() {
    int n;
    cin>>n;
    int ins;
    cin>>ins;
    int l=1;
    int r=n;
    rp(ins)
    {
        string s,a;
        cin>>s;
        cin>>s;
        cin>>a;
        cin>>s;
        int x;
        cin>>x;
        // cout<<a[0]<<endl;
        if(a[0]=='r')l=max(l,x+1);
        else r=min(r,x-1);
        // cout<<l<<" "<<r<<endl;

    }
    if(l>0 && r>=l && r<=n)
    {
        cout<<r-l+1<<endl;
    }
    else cout<<-1<<endl;
  return 0;
}