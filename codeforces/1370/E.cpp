#include <iostream>
 
using namespace std;
 
const int maxn = 1e6 + 10;
 
char a[maxn],b[maxn];
 
int c[maxn],n;
 
 
int get(int x){
	int cur = 0,res = 0;
	for (int i = 0; i < n; i++){
		cur += x * c[i];
		res = max(res,cur);
		if (cur < 0) cur = 0;
	}
	return res;
}
 
int main(){
	cin >> n >> a >> b;
	int s0 = 0,s1 = 0;
	for (int i = 0; i < n; i++){
		if (a[i] != b[i] && a[i] == '1'){ 
			c[i] = 1;
			s1++;
		}
		if (a[i] != b[i] && a[i] == '0'){ 
			c[i] = -1;
			s0++;
		}
	}
	if (s1 != s0){
		cout << -1;
		//system("PAUSE");
		return 0;
	}
	cout << max(get(1),get(-1));
	//system("PAUSE");
	return 0;
}