#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
priority_queue<ll,vector<ll>,greater<ll> >q;
main() {
	ll n,k,i,a,b,w;
	scanf("%lld%lld",&n,&k);
	for(i=1; i<=k; i++)
		q.push(0);
	while(n--) {
		scanf("%lld%lld",&a,&b);
		w=max(q.top(),a)+b;
		printf("%lld\n",w);
		q.pop();
		q.push(w);
	}
}