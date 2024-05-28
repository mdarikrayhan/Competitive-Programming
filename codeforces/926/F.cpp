#include <stdio.h>


int main(){
	int n, i;
	long long p, m, t, add, last=0, cur=0, bel, wyn=0;
	
	scanf ("%d %lld %lld", &n, &p, &m);
	for (i=0;i<n;i++){
		scanf ("%lld %lld", &t, &add);
		if (cur>=0)	bel=last+cur/p;
		else bel=last-1;
		
		if (bel<t)	wyn=wyn+t-bel-1;
		
		cur=cur-(t-last)*p+add;
		last=t;		
	}
	t=m+1, add=0;
	
	if (cur>=0)	bel=last+cur/p;
	else bel=last-1;
	
	if (bel<t)	wyn=wyn+t-bel-1;
	
	printf ("%lld", wyn);
	
return 0;}