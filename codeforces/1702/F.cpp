#include<bits/stdc++.h>
#define N 200010
using namespace std;
int t,n,a,b;
map<int,int> mp;
 
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		mp.clear();
		for(int i=1;i<=n;i++){
			cin>>a;
			while(a%2==0) a/=2;
			mp[a]++;
		}
		int fl=0;
		for(int i=1;i<=n;i++){
			cin>>b;
			while(b&&mp[b]==0) b/=2;
			if(b) mp[b]--;
			else fl=1;
		}
		if(fl) cout<<"NO\n";
		else cout<<"YES\n";
	}
}