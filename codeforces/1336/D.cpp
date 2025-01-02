#include<bits/stdc++.h>
using namespace std;
void tiaoshi(){cout<<"Florr"<<endl;}
int n, a[105], b[105], ans[105], d1[105], d2[105];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	cin>>a[n]>>b[n];
	for(int i=n-1; i>=0; i--){
		cout<<"+ "<<(i>2?i:i%2+1)<<endl;
		cout.flush();
		cin>>a[i]>>b[i];
		d1[i]=a[i]-a[i+1];
		d2[i]=b[i]-b[i+1];
	}
	int t=d1[0];
	for(int i=1; i<=n+3; i++)if(i*(i-1)/2==t)ans[1]=i-1;
	ans[3]=d2[0]-d2[2]-1;
	ans[2]=d2[2]/(ans[3]+1);
	ans[4]=d2[1]/(ans[3]+1)-ans[1]-2;
	for(int i=5; i<=n; i++){
		ans[i]=(d2[i-2]-ans[i-4]*ans[i-3])/(ans[i-1]+1)-ans[i-3]-1;
	}
	cout<<"! ";ans[n]++;
	for(int i=1; i<=n; i++)cout<<ans[i]<<' ';
	cout<<endl;
	return 0;
}

