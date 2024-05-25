// Problem: F2. Guess the K-th Zero (Hard version)
// Contest: Codeforces - Codeforces Round 719 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1520/F2
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define INF (1ll<<60)
using namespace std;
typedef long long ll;
const int N=2e5+9;
int L[N],R[N],pos[N];
int sum[N];
int k,n;
ll ask(int l,int r){
	cout<<"?"<<" "<<l<<" "<<r<<endl;
	ll res;
	cin>>res;
	return res;
}
void find(int x){
	cout<<"!"<<" "<<x<<endl;
	for(int i=pos[x];i<=pos[n];i++){
		sum[i]--;
	}
}
bool check(int x){
	if(x-ask(1,x)>=k){
		return true;
	}
	return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	cin>>n;
	int t;
	cin>>t;
	int b=30;
	int temp=ceil(n/b);
	for(int i=1;i<=temp;i++){
		L[i]=(i-1)*b+1;
		R[i]=i*b;
	}
	// cout<<R[temp]<<'\n';
	if(R[temp]<n){
		temp++;
		L[temp]=R[temp-1]+1;
		R[temp]=n;
	}
	for(int i=1;i<=temp;i++){//
		for(int j=L[i];j<=R[i];j++){
			pos[j]=i;
		}
	}
	// for(int i=1;i<=temp;i++){
		// cout<<L[i]<<" "<<R[i]<<'\n';
	// }
	bool ok=false;
	while(t--){
		cin>>k;		
		if(!ok){
			ok=true;
			for(int i=1;i<=temp;i++){
				sum[i]=R[i]-ask(1,R[i]);
			}
		}
		int l=0,r=0;
		while(sum[r]<k){
			r++;
		}
		// if(pos[r]-1==0){
			// l=1,r=n;
		// }else{
			// l=L[pos[r]-1],r=R[pos[r]+1];//[1开始的范围];
		// }
		r=r*b;
		l=r-b;
		r=min(n,r);
		while(l+1!=r){
			int mid=(l+r)>>1;
			if(check(mid)){
				r=mid;
			}else{
				l=mid;
			}
		}
		find(r);
	}
    return 0;
}
