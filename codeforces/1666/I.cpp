#include<bits/stdc++.h>
using namespace std;
int scan(int a,int b){
	cout<<"SCAN "<<a<<" "<<b<<endl;
	int x;
	cin>>x;
	return x;
}
int dig(int a,int b){
	cout<<"DIG "<<a<<" "<<b<<endl;
	int x;
	cin>>x;
	return x;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int x=scan(1,1)+4,y=scan(1,m)+2-2*m;
		int rs=(x+y)/2,cs=(x-y)/2,rd=scan(rs/2,1)+2-cs,cd=scan(1,cs/2)+2-rs;
		int r1=(rd+rs)/2,r2=(rs-rd)/2,c1=(cd+cs)/2,c2=(cs-cd)/2;
		if(dig(r1,c1)) dig(r2,c2);
		else{
			dig(r2,c1);
			dig(r1,c2);
		}
	}
	return 0;
}