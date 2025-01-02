#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;cin>>n;
  int a[200];
  for(int i=0;i<n;i++)
    cin>>a[i];
sort(a,a+n);
for(int i=n-2;i>=0;i--)
    if(a[n-1]%a[i] || a[i+1]==a[i])
{
cout<<a[n-1]<< ' ' << a[i] << '\n';
break;

}
    return 0;
}
