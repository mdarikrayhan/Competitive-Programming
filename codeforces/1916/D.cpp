#include<bits/stdc++.h>
#define maxn 2901
#define int long long
inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();return x*f;}
void write(int x){if(x<0)putchar('-'),x=-x;if(x>9)write(x/10);putchar(x%10+'0');return;}
using namespace std;
int T,n,a[1001],b[1001],cnt;
void print(int x,int y,int z){
	int len=(n+1)/2;
	for(int i=0;i<len;i++) a[i]=0;
	for(int i=0;i<len+len-1;i++) b[i]=0;
	a[len-x]=a[len-y]=a[len-z]=1;
	for(int i=0;i<len;i++)
	 for(int j=0;j<len;j++){
	 	b[i+j]+=a[i]*a[j];
	 }
	for(int i=len+len-2;i>=0;i--) printf("%d",b[i]);
	printf("\n");
}
void printt(int x,int y){
	int len=(n+1)/2;
	for(int i=0;i<len;i++) a[i]=0;
	for(int i=0;i<len+len-1;i++) b[i]=0;
	a[len-x]=1,a[len-y]=3;
	for(int i=0;i<len;i++)
	 for(int j=0;j<len;j++){
	 	b[i+j]+=a[i]*a[j];
	 }
	for(int i=len+len-2;i>=0;i--) printf("%d",b[i]);
	printf("\n");
	cnt--;if(!cnt) return;/*
	for(int i=0;i<len;i++) a[i]=0;
	for(int i=0;i<len+len-1;i++) b[i]=0;
	a[len-x]=1,a[len-y]=4;
	for(int i=0;i<len;i++)
	 for(int j=0;j<len;j++){
	 	b[i+j]+=a[i]*a[j];
	 }
	for(int i=len+len-2;i>=0;i--) printf("%d",b[i]); 
	printf("\n");
	cnt--;if(!cnt) return;*/
	for(int i=0;i<len;i++) a[i]=0;
	for(int i=0;i<len+len-1;i++) b[i]=0;
	a[len-x]=3,a[len-y]=1;
	for(int i=0;i<len;i++)
	 for(int j=0;j<len;j++){
	 	b[i+j]+=a[i]*a[j];
	 }
	for(int i=len+len-2;i>=0;i--) printf("%d",b[i]);
	printf("\n");
	cnt--;if(!cnt) return;
}
void solve(){
	scanf("%d",&n);
	if(n==1){
		printf("1\n");
	}
	else if(n==3){
		printf("169\n196\n961\n");
	}
	else if(n==5){
		printf("16384\n\
31684\n\
36481\n\
38416\n\
43681\n");
	}
	else if(n<=13){
		cnt=n;
		if(cnt){
			printf("196");
			for(int i=4;i<=n;i++) printf("0");
			cnt--;
		}
		printf("\n");
		for(int i=2;i<=(n+1)/2;i++){
			if(!cnt) return;
			printt(1,i);
			if(!cnt) return;
		}
	}
	else if(n>13){
		cnt=n;
		for(int i=2;i<(n+1)/2;i++){
			for(int j=i+1;j<=(n+1)/2;j++)
			 if(i-1!=j-i){
			 	print(1,i,j);
			 	cnt--;
			 	if(!cnt) return;
			}
		}
	}
}
signed main(){
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
/*
1:18
4:27
0:036
7:45
*/