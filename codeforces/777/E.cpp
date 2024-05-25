#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
struct A{
	int a, b, h;
	bool operator<(const A &p)const{
		if(b == p.b)	return a > p.a;
		return b > p.b;
	}
}t[N];
int n, cnt, ans;
stack<int> stk;
signed main(){
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++)	scanf("%lld%lld%lld", &t[i].a, &t[i].b, &t[i].h);
	sort(t + 1, t + 1 + n);
	ans = cnt = t[1].h;
	stk.push(1);
	for(int i = 2; i <= n; i++){
		while(!stk.empty() && t[stk.top()].a >= t[i].b){
			cnt -= t[stk.top()].h;
			stk.pop();
		}
		cnt += t[i].h;
		stk.push(i);
		ans = max(ans, cnt);
	}
	printf("%lld", ans);
	return 0;
}