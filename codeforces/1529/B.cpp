#include<bits/stdc++.h>
using namespace std;
 int main()
{
 int t; cin>>t; while(t-->0){
  int n; cin>>n; int a[n]; for(int i=0;i<n;i++) cin>>a[i];
  int p=n-1; sort(a,a+n);
  for(int i=0;i<p;i++){
   if(a[i+1]-a[i] < a[p]){
    p--; i--;
   }
  }
  cout << p+1 << endl;
 }
}