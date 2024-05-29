#include<bits/stdc++.h>
#define pb push_back
#define eps 1e-8

typedef double DO;
using namespace std;
typedef pair<DO, int> pdi;

int main() {
	vector<pdi> vec;
	int n, d; scanf("%d %d", &n, &d);
	while(n--) {
		int x, y, r; scanf("%d %d %d", &x, &y, &r);
		int R2=x*x+y*y; DO R=sqrt(R2);
		
		DO L=(int)(R-r)/d*d;
		if(L<R-r-eps) L+=d;
		
		DO angle=atan2(y, x);
		for(; L<R+r+eps; L+=d) {
			DO delta=acos((R2+L*L-r*r)/2/R/L);
			vec.pb(pdi(angle-delta, 1));
			vec.pb(pdi(angle+delta+eps, -1));
		}
	}
	sort(vec.begin(), vec.end());
	
	int sum=0, ans=0;
	for(pdi p: vec) {
		sum+=p.second;
		if(sum>ans) ans=sum;
	}
	printf("%d", ans);
}