#include <bits/stdc++.h>
using namespace std;




int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	if(n==1){
		cout<<1<<' '<<1;
		return 0;
	}
	int count=1;
	int max=0,p=0;
	for(int i=0;i<n-1;i++){
		count=1;
		for(int j=i+1;j<n;j++){
			if(arr[j]==arr[i] && arr[i]!=0){
				count+=1;
				arr[j]=0;
				
			}
		}
		if(max<count){
			max=count;
		}
		
	}
	for(int i=0;i<n;i++){
		if(arr[i]!=0){
			p+=1;
		}
		
	}
	cout<<max<<' '<<p;
		
	
	
	return 0;}
	