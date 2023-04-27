#include<bits/stdc++.h>
using namespace std;
#define l1 long long
int main(){ int t; cin>>t; while(t--){ l1 n,x,m; cin>>n>>x>>m; l1 p=x,y=x,l,r;
 while(m--){ cin>>l>>r; if(p>=l && p<=r)p=l; if(y>=l && y<=r)y=r;
 } cout<<y-p+1<<"\n";
}
}