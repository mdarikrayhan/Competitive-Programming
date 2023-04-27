#include<bits/stdc++.h>
using namespace std;
int t,n,p,x;
long long w,s;
vector<int> ans;
int main(){
	cin>>t;
	while(t--){
		cin>>n>>w; 
		p=s=0;
		for(int i=1;i<=n;i++){
			cin>>x;
			if(x<=w)
				if(x>=(w+1)/2) p=i;
				else if(s<(w+1)/2) ans.push_back(i),s+=x;
		}
		if(p) cout<<1<<endl<<p;
		else if (s>=(w+1)/2){
			cout<<ans.size()<<endl;
			for(auto x:ans)cout<<x<<' '; 
		}
		else cout<<-1;
		cout<<endl;
		ans.clear();
	}
	return 0;
}