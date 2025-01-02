// LUOGU_RID: 160510403
#include<bits/stdc++.h>
//#include<windows.h>
//#include<conio.h>
using namespace std;
int n,a[11];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(clock()/CLOCKS_PER_SEC<=1.00);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
	    cout<<a[i]<<" ";
	}
	return 0;
}