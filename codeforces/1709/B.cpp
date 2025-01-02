// LUOGU_RID: 159044469
#include<bits/stdc++.h>
    using namespace std;
    long long a[100001],s,t,ans,b[100001],c[100001];
    int main(){
    	int n,m;
    	cin>>n>>m;
    	for(int i=1;i<=n;++i) cin>>a[i];
    	for(int i=2;i<=n;++i){
    		if(a[i-1]>a[i]) b[i]=b[i-1]+a[i-1]-a[i];
            else b[i]=b[i-1];
    	}
    	for(int i=n-1;i>=1;--i){
    		if(a[i+1]>a[i]) c[i]=c[i+1]+a[i+1]-a[i];
            else c[i]=c[i+1];
    	}
    	for(int i=1;i<=m;++i){
    		cin>>s>>t;
    		if(s<t) cout<<b[t]-b[s]<<endl;
    		if(s>t) cout<<c[t]-c[s]<<endl;
    	}
    	return 0;
    }