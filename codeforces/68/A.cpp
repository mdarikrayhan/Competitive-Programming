// LUOGU_RID: 160227652
#include<bits/stdc++.h>
using namespace std;
int p1,p2,p3,p4,a,b,ans;
int main(){
	cin>>p1>>p2>>p3>>p4>>a>>b;
	if(a>b)	swap(a,b);
	for(int i=a;i<=b;i++){
		//cout<<i;
		if(i%p1==i && i%p2==i && i%p3==i && i%p4==i)
			ans++; 
	}
	cout<<ans;
	return 0;
}