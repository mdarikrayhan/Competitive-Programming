#include<cstdio>
char a[100001],b[100001];
int main(){
	int t,n,i,sum;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		scanf("%s%s",a,b);
		sum=0;
		for(i=0;i<n;i++){
			if(a[i]==b[i]){
				if(i+1<n&&a[i+1]==b[i+1]&&a[i]!=a[i+1]) sum+=2,i++;
				else if(a[i]=='0') sum+=1;
			}
			else sum+=2;
		}
		printf("%d\n",sum);
	}
}