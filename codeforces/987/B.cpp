#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define code() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
    code();
    
    int x,y; cin>>x>>y;

    double a = y*log(x);
    double b = x*log(y);

    if(x == y) cout<<"="<<endl;
    else if(a>b) cout<<">"<<endl;
    else if(b>a) cout<<"<"<<endl;
    else cout<<"="<<endl;

    return 0;
}
  		  				 	 				  	 		 	 		