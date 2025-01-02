#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
string find(string s1){
	string s;
	bool flag=false;
	for(int i=0;i<s1.size();++i){
		if(s1[i]!='0'&&s1[i]!='.'){
			flag=true;
			s+=s1[i]; 
		}
		else if(flag&&s1[i]!='.')s+=s1[i];
		else if(s1[i]=='.'){
			s+=s1[i];
			int t=s.size()-1;
			for(int j=s1.size()-1;j>=i+1;--j){
				if(s1[j]!='0'){
					t=j;
					break;
				}
			}
			for(int j=i+1;j<=t;++j)
				s+=s1[j];
			break;
		}
	}
	return s;
}
signed main(){
	ios::sync_with_stdio(false),cin.tie(nullptr);
	string s1;
	cin>>s1;
	string s;
	bool flag=false;
	s=find(s1);
	flag=false;
	int l=0,r=0;
	for(int i=0;i<s.size();++i){
		if(s[i]=='.')flag=true;
		if(!flag)l++;
		else if(s[i]!='.')r++;
	}
	if(l>0){
		if(l==1){
			for(int i=0;i<s.size();++i){
				if(s[i]!='.')cout<<s[i];
				else if(i==s.size()-1)break;
				else cout<<s[i];
			}
		}
		else{
			string ans,res;
			for(int i=0;i<s.size();++i){
				if(i==0){
					ans+=s[i];
					ans+='.';
				}
				else if(s[i]!='.')ans+=s[i];
			}
			res=find(ans);
			if(res[res.size()-1]=='.'){
				for(int i=0;i<res.size()-1;++i)
					cout<<res[i];
				cout<<"E"<<l-1;
			}
			else cout<<res<<"E"<<l-1;
		}
	}
	else{
		int t;
		for(int i=1;i<s.size();++i){
			if(s[i]!='0'){
				t=i;
				break;
			}
		}
		for(int i=t;i<s.size();++i){
			if(i==t&&i!=s.size()-1)cout<<s[i]<<".";
			else cout<<s[i];
		}
		cout<<"E-"<<t;
	}
	return 0;
}	


