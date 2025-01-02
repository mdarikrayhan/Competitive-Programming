#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

int main(){
	IOS
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		ll sum=0;
		vector<int> a(n);
		for(int i=0;i<n;++i){
			cin>>a[i];
			sum+=a[i];
		}
		if(sum%n!=0){
			cout<<"No"<<'\n';
			continue;
		}
		int ok=1;
		vector<int> v1(30);
		vector<int> v2(30);
		vector<int> v3(30);
		for(int i=0;i<n;++i){
			int x=abs(a[i]-sum/n);
			if(x==0) continue;
			int m=-1,l=-1;
			for(int j=0;j<30;++j){
				if((1<<j)&x){
					m=j;
					if(l==-1) l=j;
				}
			}
			if(m==l){
				if(a[i]>sum/n) v2[l]++;
				else v3[l]++;
			}
			else if((1<<(m+1))-(1<<l)==x){
				if(a[i]>sum/n){
					v1[m+1]++;
					v1[l]--;
				}else{
					v1[m+1]--;
					v1[l]++;
				}
			}
			else{
				ok=0;
				break;
			}
		}
		for(int i=29;i>0;--i){
			int k=v1[i]+v2[i]-v3[i];
			if(k>0){
				if(v3[i-1]>=k){
					v3[i-1]-=k;
					v2[i-1]+=k;
				}else{
					ok=0;
					break;
				}
			}else{
				if(v2[i-1]>=abs(k)){
					v2[i-1]-=abs(k);
					v3[i-1]+=abs(k);
				}else{
					ok=0;
					break;
				}
			}
		}
		if(v1[0]+v2[0]-v3[0]!=0){
			ok=0;
		}
		if(ok){
			cout<<"Yes"<<'\n';
		}else{
			cout<<"No"<<'\n';
		}
	}
	return 0;
}

