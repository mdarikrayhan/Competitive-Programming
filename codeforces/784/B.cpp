// LUOGU_RID: 159664051
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,sum=0;
	cin>>n;
	if(n==0)sum++;
	while(n){
		int q=n%16;
		if(q==0||q==4||q==6||q==9||q==10||q==13)sum++;
		if(q==8||q==11)sum+=2;
		n/=16;
	}
	cout<<sum;
	return 0;
}
