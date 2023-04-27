#include <bits/stdc++.h>
using namespace std;
int n,m,i,j,a;
main(){cin>>n;
    while(cin>>n>>m){
        vector<int>v(m);
        while(n--)cin>>j,v[j%m]++;
        a = (v[0]>0) + (!(m&1) && v[m/2]);
        for(i=1,j=m-1;i<j;++i,--j)
            if(v[i]||v[j]) a+=(v[i]==v[j])+abs(v[i]-v[j]);
        cout<<a<<'\n';
    }
}