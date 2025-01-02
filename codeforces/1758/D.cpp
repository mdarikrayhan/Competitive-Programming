#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<3*n<<' ';
		for(int i=2;i<=n-1;i++){
			cout<<2*i+3*n-1<<' ';
		}
		cout<<5*n<<endl;
	}
	return 0;
}
