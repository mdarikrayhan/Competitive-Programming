#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,a[200004];ll b[200004];
multiset<int>s;ll ans;
void sol(){
	scanf("%d",&n),s.clear(),ans=0,k=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),s.insert(a[i]);
	for(;;){
		k++;auto it=s.lower_bound(k);
		if(it==s.end()){k--;break;}
		ans+=*it,s.erase(it);
	}
	for(int i=n;i;i--){
		b[i]=ans-(ll)k*(k+1)/2;
		auto it=s.lower_bound(a[i]);
		ans-=a[i];
		if(it==s.end())k--;
		else ans+=(*it),s.erase(it);
	}
	for(int i=1;i<=n;i++)printf("%lld ",b[i]);puts("");
}
int main(){
	int tc;scanf("%d",&tc);
	while(tc--)sol();
}