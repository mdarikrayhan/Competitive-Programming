#include<iostream>
using namespace std;
int t;
long long n,x,ans;
int main(){
	cin>>t;
	while(t--){
		cin>>n>>x;
		for(ans=n;ans&&ans!=x;) ans&=n+=n&-n;
		ans==x?cout<<n<<'\n':cout<<"-1\n";
	}
	return 0;
}