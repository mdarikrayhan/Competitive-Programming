// LUOGU_RID: 159139358
#include<bits/stdc++.h>
using namespace std;
int n,i,j;
string s;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>s;
	for(i=j=0;i<n;j++,i+=j)cout<<s[i];
}