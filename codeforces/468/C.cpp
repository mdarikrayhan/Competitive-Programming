// LUOGU_RID: 160240542
#include<iostream>
using namespace std;
long long a,b,mod,big=1e18;
int main()
{  	
	cin>>mod;
	a=mod-big%mod*9%mod*9%mod;
	b=a+big-1;
	cout<<a<<" "<<b<<endl;
}
