#include<bits/stdc++.h>
using namespace std;using ll=long long;const int N=1e3+10;
int T,n,m,cT,pT,x,y,ans[N],a[N];
int main(){
	scanf("%d",&n);for(int i=1;i<=n;i++)cout<<'T';cout<<endl;cin>>cT;
	for(int i=1;i<=n;i++)cout<<"FT"[a[i]=i&1];cout<<endl;cin>>pT;for(int i=1;i+2<=n;i+=3){
		for(int j=1;j<=n;j++)cout<<"TF"[j>=i&&j<=i+2];cout<<endl;cin>>x;x=(cT-x+3)/2;a[i]^=1;a[i+1]^=1;
		for(int j=1;j<=n;j++)cout<<"FT"[a[j]];cout<<endl;a[i]^=1;a[i+1]^=1;cin>>y;y-=pT;
		if(!y)ans[i]=ans[i+1]=x>1;else ans[i]=a[i]^(y>0),ans[i+1]=ans[i]^1;ans[i+2]=x-ans[i]-ans[i+1];
	}for(int i=n/3*3+1;i<=n;i++){for(int j=1;j<=n;j++)cout<<"TF"[i==j];cout<<endl;cin>>x;ans[i]=x<cT;}
	for(int i=1;i<=n;i++)cout<<"FT"[ans[i]];cout<<endl;return 0;
}