#include<bits/stdc++.h>
using namespace std;
int t,n,a,b;
int main(){
	for(cin>>t;t--;puts("")){
	    cin>>n>>a>>b;int l=1,r=n;
	    if(abs(a-b)>1||a+b>n-2){cout<<-1;continue;}
	    for(int i=1;i<=a+b;i++)cout<<(((a<b)+i)&1?l++:r--)<<" ";
	    while(l<=r)cout<<(a<=b?l++:r--)<<" ";
    }
}