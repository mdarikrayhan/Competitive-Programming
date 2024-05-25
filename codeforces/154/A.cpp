// LUOGU_RID: 160148243
#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int n;
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++){
		string fw;
		cin>>fw;
		int sum1=0,sum2=0;
		for(int i=0;i<s.size();i++){
			if(fw[0]==s[i]){
				sum1++;
			}
			if(fw[1]==s[i]){
				sum2++;
			}
			if(fw[0]!=s[i] && fw[1]!=s[i]){
				if(sum1 && sum2){
					ans+=min(sum1,sum2);
				}
				sum1=0;
				sum2=0;
			}
		}
		if(sum1 && sum2){
			ans+=min(sum1,sum2);
		}
	}
	cout<<ans;
return 0;
}