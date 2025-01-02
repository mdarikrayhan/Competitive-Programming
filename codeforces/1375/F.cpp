// LUOGU_RID: 160230903
#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define max(a,b,c) max(a,max(b,c))
#define min(a,b,c) min(a,min(b,c))
using namespace std;

int k[4],d,he,ma,mi,mid,a,b;
int tmp=1e10;
void up() {
	he=k[1]+k[2]+k[3],ma=max(k[1],k[2],k[3]),mi=min(k[1],k[2],k[3]),mid=he-ma-mi;
	a=mid-mi,b=ma-mid;
}
signed main() {
	cin>>k[1]>>k[2]>>k[3];
	cout<<"First"<<endl;
	up();
	cout<<tmp<<endl;
	cin>>d;
	k[d]+=tmp;
	up();
	tmp=2*ma-mid-mi;
	cout<<tmp<<endl;
	cin>>d;
	k[d]+=tmp;
	up();
	cout<<mid-mi<<endl;
	cin>>d;

	return 0;
}