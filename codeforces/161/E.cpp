#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
int p[200020];
int a[10][10];
vector<int>v[5][20000];
int n;
int dfs(int i)
{
int x=0,re=0,j,z,k;
for(j=0;j<i;j++)
x=x*10+a[i][j];
if(i==n-1)
return v[1][x].size();
for(j=0;j<v[n-i][x].size();j++)
{
z=v[n-i][x][j];
for(k=n-1;k>i;k--)
{
a[i][k]=a[k][i]=z%10;
z/=10;
}
re+=dfs(i+1);
}
return re;
}
int t,i,j,x;
char s[10];
int main()
{
for(i=2;i*i<=100000;i++)
if(!p[i])
for(j=i*i;j<=100000;j+=i)
p[j]=1;
for(i=2;i<100000;i++)
if(!p[i])
for(x=i,j=1;j<5;j++)
v[j][x/=10].push_back(i);
scanf("%d",&t);
while(t--)
{
scanf("%s",&s);
for(i=0;s[i];i++)
a[0][i]=a[i][0]=s[i]-'0';
n=i;
printf("%d\n",dfs(1));
}
return 0;
}