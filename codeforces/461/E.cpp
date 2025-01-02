#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define int long long
#define N 600005
const ll mod = 1051131;
const ll inf = 1e17;
const int INF = 1e9+10;
const double eps = 1e-9;
inline ll read()
{
   ll f=0,g=1;
   char ch=getchar();
   while(ch<'0'||ch>'9') {if(ch=='-') g=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') f=(f<<1)+(f<<3)+(ch^48),ch=getchar();
   return f*g;
}

int n,t[N][4],End[N],cnt,m;
int Calc[4][4][15],Len;
char T[N];

void Insert(int x)
{
   int Rt=0; int St=T[x]-'A';
   for(int i=x;i<=min(m-1,Len+x-1);i++)
   {
      int Now=T[i]-'A';
      if(!t[Rt][Now]) t[Rt][Now]=++cnt;
      Rt=t[Rt][Now];
      if(!End[Rt]) {End[Rt]=1; Calc[St][Now][i-x+1]++;}
   }
}

struct Matrix
{
   int a[4][4];

   void Clear() {memset(a,0,sizeof a);}

   Matrix operator * (const Matrix &A)
   {
      Matrix Ans; 
      for(int i=0;i<4;i++) for(int j=0;j<4;j++) Ans.a[i][j]=n+1;
      for(int k=0;k<=3;k++) for(int i=0;i<=3;i++) for(int j=0;j<=3;j++)
      Ans.a[i][j]=min(Ans.a[i][j],a[i][k]+A.a[k][j]);
      return Ans;
   }

   Matrix operator ^ (ll &y)
   {
      Matrix A=*this;
      Matrix Base=A; A.Clear();
      for(int i=0;i<=3;i++) A.a[i][i]=1;
      while(y)
      {
         if(y&1) A=A*Base;
         Base=Base*Base;
         y>>=1;
      }
      return A;
   }
}A;

int Check(ll x)
{
   Matrix Ans=A^x;
   int Res=0;
   for(int i=0;i<=3;i++) for(int j=0;j<=3;j++) Res|=(Ans.a[i][j]<n);
   return Res;
}

ll Solve()
{
   ll l=1,r=n;
   while(l<r)
   {
      ll mid=(l+r)>>1;
      if(Check(mid)) l=mid+1;
      else r=mid;
   }
   return l;
}

ll fast(ll x,ll y)
{
   ll base=x; x=1;
   while(y)
   {
      if(y&1) x*=base;
      base*=base;
      y>>=1;
   }
   return x;
}

signed main()
{
   scanf("%lld",&n); scanf("%s",T);
   m=strlen(T); Len=min(11ll,m+1);
   for(int i=0;i<=m-1;i++) Insert(i);
   for(int i=0;i<=3;i++) for(int j=0;j<=3;j++) for(int k=Len;k>=2;k--)
   if(Calc[i][j][k]!=fast(4,k-2)) A.a[i][j]=k-1;
   printf("%lld\n",Solve());
   return 0;
}


/*
20 18
44 11 78 11 27 70 56 32
1
1 15
*/


 		  			 		   	 		  					 	  	