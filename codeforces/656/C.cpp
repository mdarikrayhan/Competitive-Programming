// LUOGU_RID: 159477879
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans;
string s;
ll To(char a){
	if('A'<=a&&a<='Z') return a-'A'+1;
	if('a'<=a&&a<='z') return -a+'a'-1;
	return 0;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++) ans+=To(s[i]);
	cout<<ans;
	return 0;
}
