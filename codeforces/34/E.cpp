#include<bits/stdc++.h>
using namespace std;

double eps=1e-9;

int main(){

int n,i,j;
double t,x[15],v[15],m[15];

cin>>n>>t;

for(i=0;i<n;i++)
cin>>x[i]>>v[i]>>m[i];

while(1){

double tmin=999999;
for(i=0;i<n;i++){
for(j=0;j<n;j++){
if(fabs(x[i]-x[j])>eps && fabs(v[i]-v[j])>eps){
double temp=(x[i]-x[j])/(v[j]-v[i]);
if(temp>0 && temp<tmin) tmin=temp;
}
}
}
if(tmin>=t) break;
t-=tmin;
for(i=0;i<n;i++) x[i]+=tmin*v[i];
for(i=0;i<n;i++){
for(j=0;j<i;j++){
if(fabs(x[i]-x[j])<eps){
double vi=((m[i]-m[j])*v[i]+2*m[j]*v[j])/(m[i]+m[j]);
double vj=((m[j]-m[i])*v[j]+2*m[i]*v[i])/(m[i]+m[j]);
v[i]=vi;
v[j]=vj;
}
}
}
}
for(i=0;i<n;i++) x[i]+=t*v[i];
for(i=0;i<n;i++)
printf("%0.9lf\n",x[i]);
return 0;
}