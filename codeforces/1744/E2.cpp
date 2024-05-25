#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i,j,k,n,m,t,a,b,c,d,r1,r2;

int main(){
cin>>t;
while(t--){
cin>>a>>b>>c>>d;
vector<ll> v1,v2;
for(i=1;i*i<=a;i++){
if(!(a%i)){
v1.push_back(i);v1.push_back(a/i);
}
}
for(i=1;i*i<=b;i++){
if(!(b%i)){
v2.push_back(i);v2.push_back(b/i);
}
}
for(auto i:v1)for(auto j:v2){
k=i*j;
r1=(a/k+1)*k;
if(r1>c)continue;
r2=(b/(a*b/k)+1)*(a*b/k);
if(r2>d)continue;
cout<<r1<<' '<<r2<<'\n'; goto z;
}
cout<<"-1 -1\n";
z:;
}
}
 					  			  	  			  		 	 	 	