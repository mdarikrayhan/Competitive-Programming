#include<bits/stdc++.h>
using namespace std;
int n,a[200010],b[200010],pos;
bool ok(int x){
	int m=0;
	for(int i=1;i<=n;i++) if(a[i]!=x) b[++m]=a[i];
	for(int i=1;i<=m;i++)
		if(b[i]!=b[m-i+1]) return (!x?pos=i:0),0;
	return 1;
}
int main(){
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		if(ok(0)) puts("YES");
		else puts(ok(a[pos])||ok(a[n-pos+1])?"YES":"NO");
	} 
}