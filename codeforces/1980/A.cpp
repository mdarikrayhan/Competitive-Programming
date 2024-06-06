#include<iostream>
#include<math.h>
#include<algorithm>
#include<string>
#include<string.h>
#include<cstdio>
#include<vector>
#define ll long long

using namespace std;

const int N=10001;
int T,n,m,ans;
int k[10];

int main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		ans=0;
		char c;
		for(int i=1;i<=n;i++){
			cin>>c;
			k[c-'A'+1]++;
		}
		for(int i=1;i<=7;i++){
			ans+=max(0,m-k[i]);
			k[i]=0;
		}
		cout<<ans<<"\n";
	}
}