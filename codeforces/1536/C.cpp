#include<bits/stdc++.h>
using namespace std;
int t,n;
string s;
int main(){
	cin>>t;
	while(t--){
		map<pair<int,int>,int> m;
		cin>>n>>s;
		int a=0,b=0;
		for(int i=0;i<n;i++){
			if(s[i]=='D') a++;
			else b++;
			int c=a/__gcd(a,b);
			int d=(a+b)/__gcd(a,b);
			m[make_pair(c,d)]++;
			cout<<m[make_pair(c,d)]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
	 		    	  	    	 		  	 	   	