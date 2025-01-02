#include<bits/stdc++.h>
main(){
	int t,n,ans,b,a[200007],i;
	for(scanf("%d",&t);t--;printf("%d\n",ans)){
		for(scanf("%d",&n),i=0;i<n;) scanf("%d",a+i++);
		for(std::sort(a,a+n),i=ans=b=0;i<n;)
			if(++b == a[i++]) ans++, b=0;
	}
}