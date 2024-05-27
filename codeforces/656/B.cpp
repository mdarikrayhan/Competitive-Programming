// LUOGU_RID: 160142439
#include<iostream>
using namespace std;
int n,sum,m[16],r[16];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>m[i];
    for(int i=1;i<=n;i++)cin>>r[i];
    for(int i=1;i<=720720;i++){
    	for(int j=1;j<=n;j++)
           if(i%m[j]==r[j]){
		   	sum++;break;
			   }
	} 
    printf("%.6lf",1.0*sum/720720);       
    return 0;
}