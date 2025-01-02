// LUOGU_RID: 159741174
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using std::cin;using std::cout;
int n;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n;
	if(n&1) cout<<(n-1)/2;
	else cout<<(n-(1<<(int)log2(n)))/2;
	return 0;
}