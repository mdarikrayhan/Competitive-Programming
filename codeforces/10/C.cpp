// LUOGU_RID: 159818023
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
int n;
__int128 ans; 
__int128 calc(int x){
	if(!x) x=9;
	return n/9+(n%9>=x);
}
void print(__int128 x){
	if(x>9) print(x/10);
	cout<<(char)(x%10|48);
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			ans+=calc(i)*calc(j)*calc(i*j%9);
	for(int i=1;i<=n;i++)
		ans-=n/i;
	print(ans);
	cout<<'\n';
	return 0;
}
