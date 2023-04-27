#include<bits/stdc++.h>
using namespace std;
long long a[101][101],n,m;
int main(){
int k;
cin>>k;
while (k--){
cin>>n>>m;
for (int i=0;i<n;i++)
for (int j=0;j<m;j++)
cin>>a[i][j];
for (int i=0;i<n;i++)
sort(a[i],a[i]+m);
for (int i=m-1;i>=1;i--){
int p=0;
for (int j=0;j<n;j++)
if (a[j][0]<a[p][0])
p=j;
rotate(a[p],a[p]+1,a[p]+i+1);
}
for(int i=0;i<n;i++){
for(int j=0;j<m;j++){
cout<<a[i][j]<<" ";
}
cout<<endl;
}
}
}