#include<bits/stdc++.h>
#include <iomanip>
using namespace std;
int main(){
    double t,n,w,h,pp,lk,max1,red,k,sum,max;
    vector<long long> a;
    vector<int> b;
    
    
        cin>>n>>k;
        lk=0;
        max1=-1;red=0;sum=0;max=0;
        a.clear();b.clear();
    for(int k1=0;k1<n;k1++){
        cin>>pp;
        a.push_back(pp);
    } 
    for(int j=k;j<=n;j++){
        sum=0;
       for(int i=0;i<j;i++){
        
        sum+=(a[i]);
       }
       if(sum/(double)j>max)
       max=sum/(double)j;
       for(int u=j;u<n;u++){
        sum+=a[u];sum-=a[u-j];
        if(sum/(double)j>max)
        max=sum/(double)j;
       }

    }
    cout<<setprecision(16)<<(max)<<endl;
return 0;}