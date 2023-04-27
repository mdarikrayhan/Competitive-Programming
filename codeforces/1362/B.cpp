#include<bits/stdc++.h>
#define test(t) int t;cin>>t;while(t--)
using namespace std;
int main()
{
	test(t)
	{
		int n;cin>>n;set<int>A;
		for(int i=0,x;i<n;i++)cin>>x,A.insert(x);
		int a =-1;
		for(int i=1;i<=1024;i++){
			set<int>B;
			for(auto x : A)B.insert(i^x);
			if(A==B){a=i;break;}
		}
		cout<<a<<endl;
	}
	return 0;
}