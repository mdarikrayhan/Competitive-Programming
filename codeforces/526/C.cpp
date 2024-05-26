// LUOGU_RID: 160328752
// LUOGU_RID: 159889934
#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int c,wr,wb,hr,hb,maxn=0;
	cin>>c>>hr>>hb>>wr>>wb;
	for(int i=0;i<=sqrt(c);i++){
		if(wr*i<c) maxn=max(maxn,i*hr+(c-i*wr)/wb*hb);
		if(wb*i<c) maxn=max(maxn,i*hb+(c-i*wb)/wr*hr);
	}
	cout<<maxn;
	return 0;
}