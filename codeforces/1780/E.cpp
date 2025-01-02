#include<bits/stdc++.h>
#define int long long
using namespace std;

int T,L,R,sum;

signed main() {
	cin>>T;
	while(T--) {
		cin>>L>>R; sum=0;
		sum=max(L-1,R/2)-L+1;
		for(int i=1,j,v,lst;i<L;i=j+1) {
			v=(L-1)/i; j=(L-1)/v;
			lst=max(R/(v+2),i-1);
			lst=min(lst,j);
			sum+=lst-i+1;
		}
		cout<<sum<<endl;
	}
	return 0;
}