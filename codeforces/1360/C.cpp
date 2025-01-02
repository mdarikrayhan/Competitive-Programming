#include<bits/stdc++.h>
int t,n,a[52],s,o,i;
main(){
	for(scanf("%d",&t);t--;){
		for(scanf("%d",&n),o=0;i<n;) scanf("%d",a+i), o+=a[i++]&1;
		for(std::sort(a,a+n),s=0;--i;) s|=(a[i]-a[i-1]==1);
		puts(o&1&(!s)?"NO":"YES");
	}
}