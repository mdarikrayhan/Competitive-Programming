// LUOGU_RID: 158443123
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,t0,t1,ans;
string s,a;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s>>a;
		if(a[0]=='s') t0++;
		else t1++;
	}
	ans=max(t0,t1);
	for(int i=1;i<=n;i++)
		if(i*i>=n&&(i*i+1)/2>=ans){
			cout<<i;
			return 0;
		}
	return 0;
}
