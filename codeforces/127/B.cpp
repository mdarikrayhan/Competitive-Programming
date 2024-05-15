#include<bits/stdc++.h>
using namespace std;
#define ll long long
int dx[]={0,-1,0,1,1,-1,-1,1};
int dy[]={1,0,-1,0,1,1,-1,-1};
char dir[]={'R','U','L','D'};
#define nl '\n'
#define s_i stoi(string s)
#define i_s to_string(num)
const ll INF=numeric_limits<ll>::max()-1;
#define ll_inf (1LL << 62)
#define inf (1 << 30)
#define SetBit(x, k) (x = (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
int32_t main()
{ fast

  int n;
  cin>>n;
  int ar[n+4];
  map<int,int>m;
  for(int i=1;i<=n;i++)
  {
      cin>>ar[i];
      m[ar[i]]++;

  }

   int ans=0;

   for(auto [i,j]:m)
   {

      if(j%4==0)
      {

          ans+=j/4;
          m[i]=0;
      }
      else
      {
          ans+=j/4;
          m[i]=j%4;


      }


   }
   //cout<<ans<<'\n';
   int p=0;
  for(auto [i,j]:m)
  {
      if(j>=2) p++;
  }

 cout<<ans+p/2;






}




