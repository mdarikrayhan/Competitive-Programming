// Hydro submission #664070489ff061bfd2ea9c46@1715832243974
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,ans=0;
	string s,s1;
	cin>>n>>s>>s1;
	for(int i=0;i<s.size();i++){
		if((s1[i]-'0')==(s[i]-'0')){
			continue;	
		}
		if(s[i]-'0'<5){
			if((s[i]-'0')+(9-(s1[i]-'0')+1)<abs((s1[i]-'0')-(s[i]-'0'))){
				ans+=(s[i]-'0')+(9-(s1[i]-'0')+1);	
			}
			else{
				ans+=abs((s1[i]-'0')-(s[i]-'0'));	
			}
		}else{
			if(9-(s[i]-'0')+((s1[i]-'0')+1)<abs((s1[i]-'0')-(s[i]-'0'))){
				ans+=9-(s[i]-'0')+((s1[i]-'0')+1);	
			}
			else{
				ans+=abs((s1[i]-'0')-(s[i]-'0'));	
			}
		} 
	}
	cout<<ans;
	return 0;
}