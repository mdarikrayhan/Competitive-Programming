// LUOGU_RID: 158019436
#include <cstdio>
#define log __builtin_log2l
constexpr int N=100010,B=300;
int T,n,Ch,i,j,t,px,py,x[N],y[N],down[N],right[N];
long double f[B],lf[B],LOG,Ma;
char s[N];
template<typename T>
inline void r(T&x){
	while((Ch=getchar())<48);
	x=Ch&15;
	while((Ch=getchar())>47)x=(x<<1)+(x<<3)+(Ch&15);
}
inline void r(char&x){while((x=getchar())<33);}
inline int hook(const int&i,const int&j){return j-down[i]+right[j]-i+1;}
int main(){
	r(n);
	LOG=0;
	down[1]=x[1]=y[1]=px=py=1;
	for(i=2;i<=n;i++){
		r(s[i]);
		if(s[i]=='<')down[++px]=py;
		else right[py++]=px;
		x[i]=px;
		y[i]=py;
	}
	right[py]=px;
	f[0]=1./hook(1,1);
	t=1;
	for(i=2;i<=n;i++){
		__builtin_memcpy(lf,f,t*sizeof*f);
		if(s[i]=='<'){
			f[0]=lf[0]*i/hook(x[i],y[i]);
			for(j=1;j+1<B&&x[i]>j&&y[i]+j<=py;j++)f[j]=(lf[j-1]+lf[j])*i/hook(x[i]-j,y[i]+j);
		}
		else{
			for(j=0;j+1<B&&x[i]>j&&y[i]+j<=py;j++)f[j]=(lf[j]+lf[j+1])*i/hook(x[i]-j,y[i]+j);
			if(x[i]>j&&y[i]+j<=py){
				f[B-1]=lf[B-1]/hook(x[i]-j,y[i]+j);
				j++;
			}
		}
		t=j;
		if((i&1023)==0){
			Ma=0;
			for(j--;~j;j--)if(Ma<f[j])Ma=f[j];
			LOG+=log(Ma);
			for(j=0;j<t;j++)f[j]/=Ma;
		}
	}
	printf("%.10Lf\n",log(f[0])+LOG);
	return 0;
}