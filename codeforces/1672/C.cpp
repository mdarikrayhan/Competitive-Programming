#include<iostream>
using namespace std;
 
int T,n,l,r,a,b;
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		a=r=0,l=1;
		for(int i=1;i<=n;++i,a=b){
			cin>>b;
			if(a==b){
				r=i-1;
				if(l==1) l=i;
			}
		}
		cout<<"\n"<<r-l+(l>=r);
	}
	return 0;
}