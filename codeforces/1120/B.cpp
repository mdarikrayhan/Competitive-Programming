#include <bits/stdc++.h>
std::queue<int> ss;
int N,x,y,f[100009],exi[100009];
char a[100009],b[100009];
void up(int i) {
	if(exi[i]) return;
	if(f[i]>0) {
		if(a[i]<9&&a[i+1]<9) ss.push(i),exi[i]=1;
	}
	if(f[i]<0) {
		if(a[i]>0&&a[i+1]>0) ss.push(i),exi[i]=1;
	}	
}
signed main(void) {
	scanf("%d %s %s",&N,a+1,b+1);
	for(int i=1;i<=N;i++) {
		a[i]-='0';
		if(i&1) x+=a[i];else x-=a[i];
	}
	for(int i=1;i<=N;i++) {
		b[i]-='0';
		if(i&1) y+=b[i];else y-=b[i];
	}
	if(x!=y) {
		printf("-1");
		return 0;
	}
	long long as=0;
	for(int i=1;i<N;i++) {
		f[i]=(b[i]-a[i])-f[i-1];
		as+=abs(f[i]);
		up(i);
	}
	printf("%lld\n",as);
	as=std::min(as,100000ll);
	while(as--) {
		assert(!ss.empty());
		int m=ss.front();ss.pop();exi[m]=0;
		if(f[m]==0) continue;
		if(f[m]>0&&(a[m]==9||a[m+1]==9)) continue;
		if(f[m]<0&&(a[m]==0||a[m+1]==0)) continue;
		if(f[m]>0) {
			a[m]++;a[m+1]++;f[m]--;
			printf("%d 1\n",m);
		} else {
			a[m]--;a[m+1]--;f[m]++;
			printf("%d -1\n",m);	
		}
		if(m+1<N) up(m+1);
		if(m>1) up(m-1);
		up(m);
	}
}