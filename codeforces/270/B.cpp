#include <bits/stdc++.h>
using namespace std;
int n,a[100005];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(n--;n&&a[n]<a[n+1];n--){}
	printf("%d",n);
	return 0;
}