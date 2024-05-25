#include<bits/stdc++.h>
#define int long long 
using namespace std;
main(){
  ios::sync_with_stdio(false);
  int t; cin>>t;
  while(t--){
    int n,c=0; cin>>n;
    map<int,int> m;
    for(int i=1;i<=n;i++){
      int x; 
	  cin>>x; 
	  m[x]++;
    }
    for(auto [a,f]:m){
      for(int i=2;i<=1000;i++)
        if(!(a%(i*i)))
	c+=m[a]*m[a/i]*m[a/(i*i)];
      c+=f*(f-1)*(f-2); 
    }
    cout<<c<<endl;
  }
  return 0;
}
 			  	 	 		 		  			  	    			