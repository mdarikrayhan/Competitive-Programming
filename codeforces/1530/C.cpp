#include<bits/stdc++.h>
using namespace std;
int T,n,p,q;
int a[200005],b[200005];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) cin>>b[i];
		sort(a+1,a+n+1);sort(b+1,b+n+1);
		for(int i=1;i<=n;i++) a[i]+=a[i-1],b[i]+=b[i-1];
		for(int i=0;;i++){
			p=i*100+a[n]-a[(n+i)/4];
			q=b[n]-b[max((n+i)/4-i,0)];
			if(p<q) continue;
			cout<< i << endl;
			break;
		}
	}
}