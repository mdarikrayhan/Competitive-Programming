#include<bits/stdc++.h>
using namespace std;
int main(){int tc;cin>>tc;while(tc--){int n;cin>>n;
int o,f=1,a;for(int i=1;i<=n;i++){cin>>a,o=0;if(i<23){
for(int j=2;j<=i+1;j++)o|=!!(a%j);f&=o;}}puts(f?"Yes":"No");}}