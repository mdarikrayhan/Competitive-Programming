#include<bits/stdc++.h>
int t,n,a,x,y,i;
main(){for(std::cin>>t;t--;){std::cin>>n;x=y=0;for (i=0;i<n;++i)std::cin>>a,(i&1?x:y)+=(i^a)&1;std::cout<<(x-y?-1:x)<<"\n";}}
