#include<iostream>
using namespace std;
int a,b,n,m,c,d;
int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>n>>m>>a>>b>>c>>d;
		cout<<4-max((a==1||a==n)+(b==1||b==m),(c==1||c==n)+(d==1||d==m))<<endl; 
	}
	return 0;
}