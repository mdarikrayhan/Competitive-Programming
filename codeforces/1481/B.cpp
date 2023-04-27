#include<bits/stdc++.h>
using namespace std;
int ain(){int n,k,i;cin>>n>>k;int a[n];for(i=0;i<n;i++)cin>>a[i];i=0;do{i-=!!i;while(i+1<n&&a[i]>=a[i+1])i++;if(i==n-1) return-2;
k--,a[i]++;}while(k);return i;}
signed main(){int t;cin>>t;while(t--)cout<<1+ain()<<' ';}