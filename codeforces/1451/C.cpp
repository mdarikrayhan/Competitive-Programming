#include <stdio.h>

int main(){
	int T;
	scanf("%d",&T);
	for(int q=0;q<T;q++){
		int n,k;
		scanf("%d%d",&n,&k);
		char s[n+1],t[n+1];
		scanf("%s%s",s,t);
		int A[26]={0},B[26]={0};
		for(int i=0;i<n/2;i++){
			A[s[i]-'a']++; B[t[i]-'a']++;
			A[s[n-i-1]-'a']++; B[t[n-i-1]-'a']++;
		}
		if(n%2!=0){
			A[s[n/2]-'a']++; B[t[n/2]-'a']++;
		}
		int res =1;
		for(int i=25;i>=0;i--){
			if(B[i]>0){
				int tmp = B[i];
				B[i]-=A[i];
				A[i]-=tmp;
				for(int j=i;j>=0;j--){
					while(A[j]>=k&&B[i]>0){
						A[j]-=k;
						B[i]-=k;
					}
					if(B[i]<=0) break;
				}
				if(B[i]>0){
//					printf("%c\n",i+'a');
					res =0; break;
				}
			}
		}
        res ? printf("YES\n") : printf("NO\n");
	}
}