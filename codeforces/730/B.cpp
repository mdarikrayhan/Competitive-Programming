#include<cstdio>
#include<iostream>
using namespace std;
int t,n;
char s[5];
int sum,maxx[55],minn[55];
int main(){
	cin>>t;
	while(t--){
		sum=0;
		cin>>n;
		for(int i=1;i<n;i+=2){
			cout<<"? "<<i<<" "<<i+1<<"\n";
			fflush(stdout);
			cin>>s;
			if(s[0]=='>'){
			    maxx[sum]=i;
				minn[sum]=i+1;
			}
			else{
			    maxx[sum]=i+1;
				minn[sum]=i;
			}
			sum++;
		}
		if(n&1){
		    maxx[sum]=n;
			minn[sum]=n;
			sum++;
		}
		for(int i=1;i<sum;i++){
			cout<<"? "<<maxx[i-1]<<" "<<maxx[i]<<"\n";
			fflush(stdout);
			cin>>s;
			if(s[0]=='>'){
			    maxx[i]=maxx[i-1];
			}
			cout<<"? "<<minn[i-1]<<" "<<minn[i]<<"\n";
			fflush(stdout);
			cin>>s;
			if(s[0]=='<'){
				minn[i]=minn[i-1];
			}
		}
		cout<<"! "<<minn[sum-1]<<" "<<maxx[sum-1]<<"\n";
		fflush(stdout);
	}///
	return 0;
}
