#include<bits/stdc++.h>
#define pi 3.1415926535897932384

using namespace std;

int main(){
  long long n;
  cin >> n;
  vector<long long> x(n),y(n),r(n);
  for(int i=0;i<n;i++){cin >> x[i] >> y[i] >> r[i];}
  long long res=0;
  for(int i=0;i<n;i++){
    int lay=0;
    for(int j=0;j<n;j++){
      if(r[i]>=r[j]){continue;}
      long long d=(x[i]-x[j])*(x[i]-x[j]);
      d+=(y[i]-y[j])*(y[i]-y[j]);
      if(d<=r[j]*r[j]){lay++;}
    }
    if(lay<=1 || lay%2==1){res+=r[i]*r[i];}
    else{res-=r[i]*r[i];}
  }
  double dres=res;dres*=pi;
  printf("%.12lf\n",dres);
  return 0;
}
