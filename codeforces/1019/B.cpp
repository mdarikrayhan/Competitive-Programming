#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;

int check(int m){
	cout<<"? "<<m<<"\n";cout.flush();
	int a,b;cin>>a;
	cout<<"? "<<m+n/2<<"\n";cout.flush();
	cin>>b;
	return a-b;
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    int k,x;
    cout<<"? "<<1<<"\n";cout.flush();
    cin>>k;
    cout<<"? "<<1+n/2<<"\n";cout.flush();
    cin>>x;
    if ((k-x)%2) {
    	cout<<"! "<<-1<<"\n";return 0;
	}
	else if ((k-x)==0){
		cout<<"! "<<1<<"\n";return 0;
	}
	bool dir=((k-x)<0);
	int l=1,r=n/2+1,ans=0;
    while (l<=r){
    	int m=(l+r)>>1;
    	int k=check(m);
    	if (k==0) {
    		ans=m;break;
		}
    	if ((k<0)^dir) r=m;
		else l=m;
	}
	cout<<"! "<<ans<<"\n";
}