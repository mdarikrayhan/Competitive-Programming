/***************************************************//*   . .  . Author : Md. Arik Rayhan . . . . . . . .  . . . *//* . .   . . . Github : github.com/mdarikrayhan       .  *//***************************************************/#include<bits/stdc++.h>
using namespace std;
int main()
{
long long int a,b,i,n,t;
cin>>t;
while(t--)
{
cin>>n;
int a[n];
for(i=0;i<n;i++)
cin>>a[i];
sort(a,a+n);
if(n%2)
cout<<a[n/2]<<" ";
for(i=n/2-1;i>=0;i--)
{
cout<<a[n-i-1]<<" "<<a[i]<<" ";
}
cout<<endl;
}
return 0;
}