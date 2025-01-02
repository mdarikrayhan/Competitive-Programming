// LUOGU_RID: 159852835
#include<bits/stdc++.h>
using namespace std;
int n,a;
double minn,maxn;
int main(){
	cin>>n>>a;
	minn=a;
	maxn=a+1;
	for(int i=2;i<=n;i++){
		cin>>a;
		minn=max(minn,a*1.0/i);
		maxn=min(maxn,(a+1)*1.0/i);
	}
	minn*=n+1,maxn*=n+1;
	int si=floor(minn);
	int bi=floor(maxn);
	if(maxn==floor(maxn))bi--;
	if(si!=bi){
		cout<<"not unique";
	}
	else cout<<"unique\n"<<si;
}