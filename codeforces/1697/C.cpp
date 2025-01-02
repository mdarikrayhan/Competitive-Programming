#include<bits/stdc++.h>
using namespace std;
int q,n;string s,t;
int main(){
	cin>>q;
	while(q--){
		cin>>n>>s>>t;
		for(int i=0;i<n;i++){
			int j=i+1;
			if(s[i]==t[i])continue;
			while(j<n&&s[j]==s[i])j++;
			if(j<n&&s[j]==t[i]&&s[j]==s[i]+1)swap(s[j],s[i]);
		}
		if(s==t)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}