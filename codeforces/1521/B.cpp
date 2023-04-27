#include<iostream>
using namespace std;
int i,x,m,n,s;
main(){for(cin>>n;m=s=2e9,cin>>n;){for(i=0;i++<n;)cin>>x,x<m?m=x,s=i:0;for(cout<<n-1<<' ';n;n--)n^s?printf("%d %d %d %d\n",n,s,m+abs(n-s),m):0;}}