#include<bits/stdc++.h>
using namespace std;
long long a[11];
long long rec(long long n){
	while(n>0){
		if(a[n%10]){
			return 1;
		}
		n/=10;
	}
	return 0;
}
int main(){
    long long n, k, s=0;
	cin>>n;
	k=n;
	while(n>0){
		a[n%10]=1;
		n/=10;
	}
	for(long long i=1; i<=sqrt(k); i++){
		if(k%i==0){
			s+=rec(i);
			if(i*i!= k){
				s+=rec(k/i);
			}
		}
	}
	cout<<s;
}
