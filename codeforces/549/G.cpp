#include<bits/stdc++.h>
using namespace std;

const int maxn=2e5+100;
int n,a[maxn];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]+=i;
	}
	sort(a+1,a+1+n);
	bool f=1;a[0]=-1e9-10;
	for(int i=1;i<=n;i++){
		a[i]-=i;
		if(a[i]<a[i-1]){
			f=0;break;
		}
	}
	if(f){
		for(int i=1;i<=n;i++){
			cout<<a[i]<<" ";
		}cout<<endl;
	}else{
		cout<<":("<<endl;
	}
	
	return 0;
}