#include<bits/stdc++.h>
using namespace std;
int t,n,p,i,c,ans,a[110];
map<int,int>m;
int main(){
	cin >> t;
	while(t--){
		cin >> n >> p;
		for(int i=1;i<=n;i++)cin >> a[i],m[a[i]]=1;
		ans=p;i=a[n];
		for(;m[i]&&i>0;i--)ans--;
		if(i>0){
			c=n-1;
			while(c&&a[c]==p-1)c--;
			if((a[c]+1)%p==i)for(i--,ans--;m[i]&&i>0;i--)ans--;
		}else for(;m[i]&&ans!=0;i=(i+p-1)%p)ans--;
		cout << ans << '\n';m.clear();
	}
	return 0; 
}