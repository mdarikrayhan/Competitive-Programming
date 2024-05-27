#include <bits/stdc++.h>

using namespace std;

int main(){
	long long ans = 0;
	long long sx = 0, sy = 0;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		ans += (n - 1LL) * (x * x + y * y) - ((x * sx + y * sy) * 2);
		sx += x, sy += y;
	}
	cout << ans << endl; 
	return 0;
}
		   			 	 	  		  	 			   		  	