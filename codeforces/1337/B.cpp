#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
	int x,n,m;
	cin>>x>>n>>m;
	while(x>18 && n--){
		x=x/2+10;
	}
	float y=x;
	while(m--){
		y=y-10;
	}
	if(y<=0){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
	//cout<<y;
}
}