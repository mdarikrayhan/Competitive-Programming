#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;

struct node{
   double x,t;
   bool operator<(const node&p)const{
      return t>p.t;
   }
}a[N];

double ans=0;
double cnt1=0,cnt2=0;
void slove(){
  int n;
  double T;
  cin>>n>>T;
  for(int i=1;i<=n;i++){
    cin>>a[i].x;
  }
  for(int i=1;i<=n;i++){
    cin>>a[i].t;
    if(a[i].t>T){
     cnt1+=(a[i].t-T)*a[i].x;
    }
    if(a[i].t<T){
     cnt2+=(T-a[i].t)*a[i].x;
    }
  }
  sort(a+1,a+n+1);
  if(a[1].t<T||a[n].t>T){
    cout<<0<<'\n';
    return;
  }
  if(cnt1<cnt2){
        double cnt=cnt1;
       for(int i=1;i<=n;i++){
    if(a[i].t>=T){
     ans+=a[i].x;
     //cnt+=(a[i].t-T)*a[i].x;
    }
    else{
        double m=(T-a[i].t)*a[i].x;
        if(cnt>=m){
            cnt-=m;
            ans+=a[i].x;
        }
        else{
           ans+=cnt/(T-a[i].t);
           break;
        }
    }
  }
 }
  else{
        double cnt=cnt2;
        for(int i=n;i>=1;i--){
    if(a[i].t<=T){
     ans+=a[i].x;
     //cnt+=(T-a[i].t)*a[i].x;
    }
    else{
        double m=(a[i].t-T)*a[i].x;
        if(cnt>=m){
            cnt-=m;
            ans+=a[i].x;
        }
        else{
           ans+=cnt/(a[i].t-T);
           break;
        }
    }
   }
  }
  printf("%.10lf",ans);
  //cout<<ans/T<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);


        slove();

    return 0;
}
