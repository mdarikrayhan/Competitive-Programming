// LUOGU_RID: 156389943
#include<bits/stdc++.h>
int main() {
	int n,p,k,l,r;
	std::cin>>n>>p>>k;
	if(p-k>0)
	  l=p-k;
	else {
    	l=1;
	}
	if(n-p-k>0)
	  r=p+k;
	else  r=n;
	if(l!=1)
	  printf("<< ");
	for(int i=l;i<=r;i++)
	  if(i==p) printf("(%d) ",i);
	  else {
	      printf("%d ",i);
	  }
	if(r!=n)
	  printf(">>");
	std::cout<<'\n';
}