// LUOGU_RID: 158605928
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
namespace yjf{
	const int N=2e5+10;
	const int M=27;
	const int INF=0x3f3f3f3f;

	string a,b;

	int stk[M][N],idx[M];
	__int128 sum1[M][N];

	signed main(){
		int n;
		scanf("%d",&n);
		cin>>a>>b;
		a=' '+a;
		b=' '+b;

		// cout<<a<<'\n'<<b<<'\n';
		// return 0;

		for(int i=1;i<=n;i++){
			stk[a[i]-'A'][++idx[a[i]-'A']]=i;
			sum1[a[i]-'A'][idx[a[i]-'A']]=sum1[a[i]-'A'][idx[a[i]-'A']-1]+i;
		}
		
		// for(int i=0;i<26;i++){
		// 	for(int j=1;j<=idx[i];j++){
		// 		cout<<stk[i][j]<<' ';
		// 	}
		// 	cout<<'\n';
		// }

		for(int i=0;i<26;i++){
			stk[i][idx[i]+1]=INF;
		}
		
		__int128 ans=0;
		for(int i=1;i<=n;i++){
			int tmp=lower_bound(stk[b[i]-'A']+1,stk[b[i]-'A']+1+idx[b[i]-'A']+1,i)-stk[b[i]-'A'];
			// cout<<tmp<<'\n';
			int yjf=tmp-1;
			ans+=(__int128)sum1[b[i]-'A'][yjf]*(n-i+1);
			ans+=((__int128)(idx[b[i]-'A']-yjf)*(n+1)-((__int128)sum1[b[i]-'A'][idx[b[i]-'A']]-sum1[b[i]-'A'][yjf]))*i;
		}

		__int128 tmp=0;
		for(int i=1;i<=n;i++){
			tmp+=((__int128)n-i+1)*(n-i+1);
		}
		double res=(double)ans/tmp;

		printf("%.7lf\n",res);

		return 0;
	}
}
signed main(){
	return yjf::main();
}