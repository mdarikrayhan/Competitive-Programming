#include<bits/stdc++.h>
using namespace std;
int a[110];
int main()
{
	int T;
	cin >> T;
	while(T--){
		int n,ans;
		cin >> n;
		for(int i=1;i<=n;i++)
		cin >> a[i];
		sort(a+1,a+n+1);
		for(ans=(n+1)/2;ans;ans--){
			int f=1;
			for(int i=1;i<=ans&&f;i++)
			if(a[i+ans-1]>i)f=0;
			if(f)break;
		}
		cout << ans<< endl;
	}
	return 0;
}