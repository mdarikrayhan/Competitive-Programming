#include<iostream>
using namespace std;
void solve(){
	int i,j,n,k=1;
	string s;
	cin>>n>>s;
	while(k<n&&(s[k]<s[k-1]||(k>1&&s[k]==s[k-1])))k++;
	for(i=0;i<k;i++)cout<<s[i]; for(i=k-1;0<=i;i--)cout<<s[i];
	cout<<'\n';
}
int main(){
	int T;
	cin>>T;
	while(T--)solve();
}