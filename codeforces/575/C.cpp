#include<cstdio>
unsigned v[820000],a[2][25][25]; int n,l,r,D;
unsigned query(int x){ return l=x*25,r=l+24,((v[l>>5]>>(l&31))|(v[r>>5]<<(31-(l&31))<<1))&33554431u; }
void modify(int x, unsigned y){ l=x*25,r=l+24,v[l>>5]^=y<<(l&31),v[r>>5]^=y>>(31-(l&31))>>1; }
void update(int x, unsigned y){ unsigned r=query(x); if (y>r) modify(x,r^y); }
int main(){
	scanf("%d",&n); D=(1<<n)-1;
	for (int i=0; i<2; i++) for (int j=0; j<n; j++) for (int k=0; k<n; k++) scanf("%u",&a[i][j][k]);
	for (int i=0; i<=n/2; i++){
		for (int j=0; j<=D; j++){
			int p=__builtin_popcount(j),val=query(j);
			if (p>=i) for (int s=D^j; s; s^=s&-s) update(j|(s&-s),val+a[0][p][__builtin_ctz(s)]);
		}
		if (i==n/2) return printf("%u\n",query(D)),0;
		for (int j=D; ~j; j--){
			int p=__builtin_popcount(j),val=query(j); modify(j,val);
			if (p>=i) for (int s=D^j; s; s^=s&-s) update(j|(s&-s),val+a[1][p][__builtin_ctz(s)]);
		}
	}
}