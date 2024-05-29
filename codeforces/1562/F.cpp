#include<bits/stdc++.h>
#define I long long
#define R(i,a,b) for(I i=a;i<=b;i++)
#define G __gcd
using namespace std;
const I N=2e5+5;
I n,v[N],c[99][99],a[N];
I A(I x,I y){cout<<"? "<<x<<" "<<y<<endl;cin>>x;return x;}
I L(I x,I y){return x/G(x,y)*y;}
mt19937 r(time(0));
void F()
{
R(i,1,n)R(j,i+1,n)c[i][j]=c[j][i]=A(i,j);
if(n==3)R(i,1,N){I a[3]={i,i+1,i+2};do if(L(a[0],a[1])==c[1][2]&&L(a[1],a[2])==c[2][3]&&L(a[0],a[2])==c[1][3]){cout<<"! "<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;return;}while(next_permutation(a,a+3));}
cout<<"! ";R(i,1,n){I x=0;R(j,1,n)if(i!=j)x=G(c[i][j],x);cout<<x<<" ";}cout<<endl;
}
void H()
{
I M=-1,p=-1;
R(i,1,250)
{
I g=0,u=r()%n+1;
R(j,1,20){I v;do{v=r()%n+1;}while(u==v);g=G(g,A(u,v));}
if(!v[g]&&g>M)M=g,p=u;
}
R(i,1,n)a[i]=(i==p?M:A(i,p)/M);
cout<<"! ";R(i,1,n)cout<<a[i]<<" ";cout<<endl;
}
int main()
{
v[1]=1;R(i,2,N)if(!v[i])R(j,2,N/i)v[i*j]=1;
I T;cin>>T;while(T--){cin>>n;if(n<99)F();else H();}
}
