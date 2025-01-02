// LUOGU_RID: 160043244
#include<bits/stdc++.h>
using namespace std;
#define int long long

//int t[30000000];
int a[]={	2, 3, 5, 7, 13, 17, 19, 31, 61, 89, 107, 127, 521, 607, 1279, 2203, 2281, 3217, 4253, 4423, 9689, 9941, 11213, 19937, 21701, 23209, 44497, 86243, 110503, 132049, 216091, 756839, 859433, 1257787, 1398269, 2976221, 3021377, 6972593, 13466917, 20996011};
int qpow(int a,int b,int p){
  int ans=1;
  while(b){
    if(b&1)ans=ans*a%p;
    a=a*a%p;
    b>>=1;
  }
  return ans;
}
signed main(){
  //for(int i=1;i<=5000;++i)for(int j=1;j<=5000;++j)t[i/2+j+i*j]=1;
  //for(int i=1;i<=100000;++i)if(!t[i])cout<<i<<endl;
  int n;cin>>n;
  cout<<qpow(2,a[n-1]-1,1e9+7)-1;
//  int cnt=1;
//  for(int i=2;i<1e18;i*=2){
//    int t=i-1;
//    for(int x=1;x<=t;++x){
//      int m=t-x/2;
//      if(m%(x+1))continue;
//      else{
//        cout<<t<<' '<<x<<' '<<m/(x+1)<<' '<<cnt<<endl;
//        break;
//      }
//    }
//    ++cnt;
//  }
  return 0;
}