// LUOGU_RID: 154964603
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> PII;
signed main(){
	int n;
	cin>>n;
	priority_queue<PII,vector<PII>,greater<PII>> heap;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		heap.push({b,a});
	}
	int m;
	cin>>m;
	int ans=0;
	int f=1;
	vector<int> fac(m);
	for(int i=0;i<m;i++){
		cin>>fac[i];
	}
	for(int i=m-1;i>0;i--){
		fac[i]=fac[i]-fac[i-1];
	}
	for(int i=0;i<m;i++){
		int k=fac[i];
		while(heap.size()&&k){
			auto u=heap.top();
			heap.pop();
			if(u.second>=k){
				ans+=(f)*(u.first)*(k);
				f++;
				u.second-=k;
				k=0;
				heap.push(u);
				break;	
			}else{
				ans+=f*u.first*u.second;
				k-=u.second;
			} 
		}
	}
	while(heap.size()){
		auto u=heap.top();
		heap.pop();
		ans+=f*u.first*u.second;
	} 
	cout<<ans<<endl; 
}