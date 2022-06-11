#import<iostream>
using namespace std;int d,m,n,x,y;main(){for(cin>>n>>d>>m;m--;cout<<(x-y>d|y-x>d|x+y<d|x+y>n+n-d?"NO":"YES")<<endl)cin>>x>>y;}