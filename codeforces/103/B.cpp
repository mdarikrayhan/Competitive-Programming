// LUOGU_RID: 159155859
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int sb=105;
int n,m,ans,t=1;
int f[sb];
int get(int x) {
	if(f[x]==x) return x;
	else return f[x]=get(f[x]);
}
int main() {
	cin>>n>>m;
	for(int i=1; i<=n; i++) f[i]=i;
	if(n!=m) {
		cout<<"NO";
		return 0;
	}
	for(int i=1; i<=n; i++) {
		int a,b;
		cin>>a>>b;
		f[get(a)]=get(get(b));
	}
	for(int i=2; i<=n; i++)
		if(get(i)!=get(i-1)) {
			cout<<"NO";
			return 0;
		}
	cout<<"FHTAGN!";
	return 0;
}
