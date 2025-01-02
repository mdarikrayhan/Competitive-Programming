#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>

void solve(){

	ll n,q;
	cin>>n>>q;
	vll a(n);
	for(int i = 0; i< n ;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
	vll pre(n);
	pre[0]=a[0];

	for(int i = 1;i<n;i++){
		pre[i]=pre[i-1]+a[i];
	}

	while(q--){

		ll p,r;
		cin>>p>>r;
		if(p==r){
			cout<<pre[p-1]<<endl;
		}else{
		ll sum=pre[p-1]-pre[p-r-1];
		cout<<sum<<endl;
		}

	}return;
	
}
int main(){
	
	int t;
	cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		
		int i = 1;
		int j = n;
		while (i<=j)
		{
			cout<<j<<" ";
			j--;
			if(i<=j){
				cout<<i<<" ";
				i++;
			}
		}cout<<endl;
		


	

		


	


	
			
			
		

		

		

		

		

		
	
		
	}
	return 0;

}