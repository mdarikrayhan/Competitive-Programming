#include<bits/stdc++.h>
using namespace std;
#pragma GCC target("popcnt")
#define for(i,a,n) for(int i = a; i<=n;i++)
#define revfor(i,n,a) for(int i = n; i >= a; i--)
#define pb push_back
#define Hello (ios_base::sync_with_stdio(false),cin.tie(NULL))
typedef long long ll;
int main(){
	Hello;
	int t=1;
	//cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+1];
		for(i,1,n){
			cin>>a[i];
		}
		int s,f;
		cin>>s>>f;
		ll sum=0;
		int l=s,r=f-1;
		for(i,s,f-1){
			sum+=a[i];
		}
		ll res=sum;	
		int ind=1;
		for(i,2,n){
			sum-=a[r];
			l= l==1? n:l-1;
			sum+=a[l];
			r= r==1? n:r-1;
			if(sum>res){
				ind=i;
				res=sum;
			}
		}
		cout<<ind<<endl;
	}

}