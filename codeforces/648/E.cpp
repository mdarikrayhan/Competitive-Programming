#include <bits/stdc++.h>

#define fi first
#define se second
#define mk make_pair
#define pb push_back

using namespace std;

int xr[10020];
priority_queue < pair < int , int > > q;

int n,k,ans[100200];
bool ff[12][10020];
bool f[10200];
int i;
int a[1000200];
int fr[10020];
int prv[100200];
vector < pair < pair < int , int > , int > > all;
vector < int > pr;

int main()
 {
  cin>>n>>k;
  xr[0]=1;
  for (i=1;i<=10;i++)
   xr[i]=(xr[i-1]*10)%k;
  for (i=1;i<=n;i++)
   {
    scanf("%d",&a[i]);
    int dig=0,x=a[i]%k;
    int y=a[i];
    while (y)
     {
      y/=10;
      dig++;
     }
    if (!dig) dig++;
    if (!ff[dig][x])
     {
      ff[dig][x]=1;
      all.pb(mk(mk(x,dig),a[i]));
     }
   }

  q.push(mk(0,0));
  while (q.size() > 0)
   {
    int now=q.top().se;
    int dis=-q.top().fi;
    q.pop();
    if (now == 0 && dis)
     {
      while (prv[now] != 0)
       {
        pr.pb(fr[now]);
        now=prv[now];
       }
      pr.pb(fr[now]);
      cout<<"YES"<<endl;
      for (i=pr.size()-1;i>=0;i--)
       printf("%d",pr[i]);
      return 0;
     }
    if (f[now]) continue;
    f[now]=1;

    for (int i=0;i<all.size();i++)
     {
      int nxt=(now*xr[all[i].fi.se]+all[i].fi.fi)%k;
      int cst=all[i].fi.se;

      if (!ans[nxt] || ans[nxt] > dis+cst)
       {
        ans[nxt]=dis+cst;
        prv[nxt]=now;
        fr[nxt]=all[i].se;
        q.push(mk(-dis-cst,nxt));
       }
     }
   }

  cout<<"NO"<<endl;

 }