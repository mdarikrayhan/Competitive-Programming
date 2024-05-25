#include<bits/stdc++.h>>
 
using namespace std;
const int maxn=2*1e5+5;
char c[maxn];
int l=0,r=0,u=0,d=0;
int n;
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin>>n;
    int cnt=1;
    for(int i=0;i<n;i++)
    {
         cin>>c[i];
         if(c[i]=='R')
         {
             if(l==1)
                 cnt++,l=u=d=0;
            r=1;
         }
         if(c[i]=='L')
         {
             if(r==1)
                 cnt++,r=u=d=0;
             l=1;
         }
         if(c[i]=='U')
         {
             if(d==1)
                 cnt++,r=l=d=0;
             u=1;
         }
         if(c[i]=='D')
         {
             if(u==1)
                 cnt++,r=l=u=0;
             d=1;
         }
    }
    cout<<cnt<<endl;
}
