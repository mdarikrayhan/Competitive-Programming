#include<bits/stdc++.h>
using namespace std;

void solve(){
	long long n;
	cin>>n;
	if(n&1||n<4){
		cout<<-1<<endl;
		return;
	}
	n/=2;
	cout<<(n/3+(n%3!=0))<<" "<<n/2<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
