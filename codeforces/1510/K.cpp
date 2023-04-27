#include<bits/stdc++.h>
using namespace std;
int n,a[2005];
signed main() {
	cin>>n;
	for(int i=0;i<n+n;i++)
		cin>>a[i];
	int cyc=(n%2==0?4:2*n),pos=-1;
	for(int i=0;i<cyc;i++) {
		if(is_sorted(a,a+n+n)) {
			pos=i;
			break;
		}
		if(i%2) for(int j=0;j<n;j++) swap(a[j],a[j+n]);
		else for(int j=0;j<n+n;j+=2) swap(a[j],a[j+1]);
	}
	cout<<min(pos,cyc-pos);
}