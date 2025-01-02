#include<bits/stdc++.h>
using namespace std;
#define ff fflush(stdout)
int n,m;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cout<<"? "<<2*n+2<<endl;
	for(int i=0;i<n;i++){
		cout<<i<<" "<<0<<endl<<i+1<<" "<<m<<endl;
	}
	cout<<n<<" "<<-1<<endl<<0<<" "<<-1<<endl;
	ff;
	double s,x=0,y=0;
	cin>>s;
	y=m-m*s-0.5;
	cout<<"? "<<2*m+2<<endl;
	for(int i=0;i<m;i++){
		cout<<0<<" "<<i<<endl<<n<<" "<<i+1<<endl;
	}
	cout<<-1<<" "<<m<<endl<<-1<<" "<<0<<endl;
	ff;
	cin>>s;
	x=n-n*s-0.5;
	cout<<"! "<<fixed<<setprecision(10)<<x<<" "<<fixed<<setprecision(10)<<y;
	return 0;
}