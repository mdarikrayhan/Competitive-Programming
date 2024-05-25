#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[10005];
int n;
int minn = INT_MAX;
int t = 0;
int sum = 0;

signed main(){
	cin >> n;
	
	for(int i = 1;i < 2 * n;i ++){
		cin >> a[i];
		
		int abss = abs(a[i]);
		
		minn = min(minn,abss);
		
		sum += abss;
		
		if(a[i] < 0){
			t ++;
		}
	}
	
	if(t % 2 == 0){
		cout << sum;
		return 0;
	}
	
	if(n % 2 != 0){
		cout << sum;
		return 0;
	}
	
	cout << sum - minn * 2;
	return 0;
}