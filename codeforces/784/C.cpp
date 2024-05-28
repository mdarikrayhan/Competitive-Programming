// LUOGU_RID: 160516153
#include<bits/stdc++.h>
using namespace std;
int n , a[105] , m1 , m2; 
signed main() {
	
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	m1 = a[n];
	sort(a+1,a+n+1);
	m2 = a[n];
	cout << (m1^m2);
	
	return 0;
}