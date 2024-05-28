#include<bits/stdc++.h>
#define eps 1e-8
using namespace std;

double n,r,v;
double s,f;

int main(){
scanf("%lf%lf%lf",&n,&r,&v);
while(n--){
scanf("%lf%lf",&s,&f);
double L=0,R=1e10;
for(int o_o=1;o_o<=200;o_o++){
double mid=(L+R)/2;
double t=mid*v+r*fabs(sin(v*mid/r));
if(t*2>f-s)R=mid;
else L=mid;
}
printf("%.9f\n",L+R);
}
return 0;
}