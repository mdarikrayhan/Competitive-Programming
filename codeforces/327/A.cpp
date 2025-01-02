#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int c1=0,c0=0,max0=-1;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        if(x==1){
         c1++;
        if(c0>0) c0--;
    }else{
        c0++;
        max0=max(max0,c0);
    }

    }
    cout<<c1+max0<<endl;

    return 0;
}
  			 	       				 					 					