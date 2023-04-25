#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n;
string s;
main(){
	cin>>t;
	while(t--){
		int sum=0,res=0,ns=0;
		cin>>n>>s;
		map<int,int> a;a[0]=1;
		stack<int> S;
		for(int i=0;i<n;a[--sum]++,i++,res+=i*(n-i+1)){
			if(s[i]=='(')
				sum+=2,S.push(i);
			else{ 
				if(S.empty())continue;
				res-=(S.top()+1)*(n-i)<<1;
				S.pop(); 
			}
		}
		for(auto x:a)
			ns+=x.second,res+=ns*(n+1-ns);
		cout<<res/2<<endl;
	}
}