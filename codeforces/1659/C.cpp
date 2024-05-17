// fannhkn
#include<bits/stdc++.h>
#define int long long
#define forinc(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=2e5+10;
int n,a,b,x[N],nxt[N];

void sol()
{
   cin>>n>>a>>b;
   forinc(i,1,n) cin>>x[i];
   for(int i=1;i<=n;i++) nxt[i] = nxt[i-1] + x[i];
   int kq=1e16;
   for(int i=0;i<=n;i++)
   {
      kq=min(kq,x[i] * a + b * (nxt[n] - nxt[i] - (n - i - 1) * x[i]));
   }
   cout<<kq<<"\n";
}
int32_t main()
{
   if(fopen("cay1.cpp","r"))
   {
         freopen("cay1.cpp","r",stdin);
         freopen("cay2.cpp","w",stdout);
   }
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int t;
   cin>>t;
   while(t--)
   {
      sol();
   }
}

