// LUOGU_RID: 160043587
#include<cstdio>
int t[1000002],h[1000002],l[1000002],r[1000002],cnt[1000002];
int main() {
	int n,p=0;
	long long ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		scanf("%d",t+i);
	for(int i=1;i<n;++i)
		if(t[i]>t[p])			//寻找最大值
			p=i;
	for(int i=0;i<=n;++i)
		h[i]=t[(i+p)%n];		//转环为链
	for(int i=1;i<=n;++i) {
		l[i]=i-1;					//初始化为i左边第一个
		while(l[i]&&h[i]>=h[l[i]])
			l[i]=l[l[i]];			//满足条件便递推
	}
	for(int i=n-1;i>=0;--i) {
		r[i]=i+1;						//初始化为i右边第一个
		while(r[i]<n&&h[i]>h[r[i]])
			r[i]=r[r[i]];				//满足条件便递推
		if(r[i]<n&&h[i]==h[r[i]]) {
			cnt[i]=cnt[r[i]]+1;			//递推count数组
			r[i]=r[r[i]];
		}
	}
	for(int i=0;i<n;++i) {
		ans+=cnt[i];			//至少能看到的组数
		if(h[i]<h[0]) {
			ans+=2;				//另外的两组
			if(!l[i]&&r[i]==n)
				ans--;			//特判是同一组的情况
		}
	}
	printf("%I64d\n",ans);
	return 0;
}