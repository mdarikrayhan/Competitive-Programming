#include<bits/stdc++.h>
using namespace std;
int main()
{

int t;
cin>>t;
while(t>0)
{
int n,i;
cin>>n;
int a[n];
vector<int> v;
for(i=0;i<n;i++){cin>>a[i]; v.push_back(a[i]);}
sort(v.begin(),v.end());
int s[n][3],x=0;
for(i=0;i<n;i++){
int j=i;
if(a[i]!=v[i]){ while(a[j]>v[i]){ j++;} 
s[x][0]=i+1;
s[x][1]=j+1;
s[x][2]=j-i;
while(j>i)
{ a[j]=a[j-1];
j--;}
a[i]=v[i];
x++;}
}
cout<<x<<endl;
for(int i=0;i<x;i++)
{ cout<<s[i][0]<<" "<<s[i][1]<<" "<<s[i][2]<<endl;}

t--;
}}