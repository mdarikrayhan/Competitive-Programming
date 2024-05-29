#include <iostream>
#include <bits/stdc++.h>
#define nl               cout<<"\n";
#define int             long long
using namespace std;
const int mod = 1000000007;
void check( int a,  int b)
{
  	int  p=1;
  	for(int i=1;i<b-1;i++)
	{p=(p*a)%b;
    	if(p==1) 
			return;
  	}
  	cout<<a<<endl;
    exit(0) ;  
}
void solve()
{

  	 int n,x; cin>>n>>x;
  	 int a=n+1;
  	for(int i=2;i<=sqrt(a);i++)
	{
    	if(a%i==0) 
		{
      		cout<<-1;
      		return ;
    	}
  	}
  	        for(int i=x-1;i>1;i--)
    	        if(i%a!=0)
      		        check(i,a);
  	                cout<<-1;
                    return; 
                
}
signed main(){
//int t;cin>>t;
//while(t--){ 
solve();
//}
return 0;
}