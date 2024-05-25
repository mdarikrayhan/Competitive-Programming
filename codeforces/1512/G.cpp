#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e7;
long long s[maxn],d[maxn];
int main(){
	for (int i=1;i<=1e7;i++) {
		for (int j=1;j<=1e7/i;j++) {
			s[i*j]+=i;
		}
	}
	for(int i=1e7;i>=1;i--) {
		if(s[i]<=1e7) {
			d[s[i]] =i;
		}
	}
	int t;
	cin>>t;
	while (t--) {
		int n;
		cin>>n;
		if(!d[n])cout<<-1<<endl;
		else cout<<d[n]<<endl;
	}
}