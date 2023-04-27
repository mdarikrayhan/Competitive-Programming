#include<bits/stdc++.h>

using namespace std;

string s,t;
int tt,n,m;

int main()
{
	cin>>tt;
	while(tt--){
		int f=0;
		cin>>s>>t;
		for(int i=0;i<s.size();i++){
			string s1=s.substr(0,i+1),s2=s.substr(0,i);
			reverse(s2.begin(),s2.end());
			s1+=s2;
			if(s1.find(t)!=-1){
				f=1;
				break;
			}
		}
		cout<<(f?"YES":"NO")<<endl;
	}
}