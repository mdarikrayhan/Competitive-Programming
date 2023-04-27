#include<bits/stdc++.h>
using namespace std;int main(){int q,i,j,k,l,o,p;cin>>k;while(k--){cin>>o>>p;int a[o+1]={0},b[p+1]={0};
    for(i=1;i<=o;i++){for(j=1;j<=p;j++){cin >>l;if(l==1){a[i]=1;b[j]=1;}}}
    l=0;for(i=1;i<=o;i++){l+=a[i];}q   =0;for(i=  1;i<=p;i++)q+=b[i];l=min(p-q,o-l);if(l&1==1)cout<<"Ashish\n";
    else cout<<"Vivek\n";
}return 0;}