// LUOGU_RID: 160234141
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,sum,t;
struct ha{
    int x,y;
    inline bool operator < (const ha &o) const{
		if(x!=o.x) return x<o.x;
    	return y<o.y;
	}
};
ha a[200005];
priority_queue<int> q;
signed main() {
	scanf("%lld",&t);
	while(t--){
		sum=0;
		scanf("%lld",&n);
	    for(register int i=1;i<=n;++i) scanf("%d%d",&a[i].x,&a[i].y);
	    sort(a+1,a+1+n);
	    for(register int i=n;i>=1;--i){
	        q.push(-a[i].y);
	        if(a[i].x>n-q.size()){
	        	sum+=(-q.top());
				q.pop();
			}
	    }
	    printf("%lld\n",sum);
	    while(!q.empty()) q.pop();
	}
    return 0;
}