#include<iostream>
using namespace std;
long long x[100],y[100],vis[100];
long long calcarea(int i,int j,int k){
	return llabs((y[i]-y[j])*(x[i]-x[k])-(y[i]-y[k])*(x[i]-x[j]));
}
int main(){
	int n,i,j,k,T,mxp,q;
	long long curmx,cura;
	cin>>n;
	for(i=0;i<n;i++) cin>>x[i]>>y[i];
	if(n%2==0)cout<<"Alberto"<<endl;
	else{
		cout<<"Beatrice\n";
		cin>>q;
		vis[q-1]=1;
	}
	for(T=(n-2)/2;T>0;T--){
		curmx=1e18;
		for(i=0;i<n;i++){
			if(vis[i]) continue;
			for(j=i+n-1;vis[j%n]==1;j--);
			for(k=i+1;vis[k%n]==1;k++);
                cura=calcarea(i,j%n,k%n);
			if(cura<curmx){
				curmx=cura;
				mxp=i;
			}
		}
		cout<<mxp+1<<endl;
		vis[mxp]=1;
		cin>>q;
		vis[q-1]=1;
	}
	return 0;
}