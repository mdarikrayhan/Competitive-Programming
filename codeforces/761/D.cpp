// LUOGU_RID: 160160498
#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,p,id,lj;
}arr[1000005];
int n,l,r;
bool cmpp(node x,node y){
	return x.id<y.id;
}
bool cmp(node x,node y){
	return x.p<y.p;
}

int main(){
	cin>>n>>l>>r;
	for(int i=1;i<=n;i++){
		cin>>arr[i].a;
		arr[i].id=i;
	}
	for(int i=1;i<=n;i++){
		cin>>arr[i].p;
	}
	sort(arr+1,arr+1+n,cmp);
	arr[1].b=l;
	arr[1].lj=l-arr[1].a;
	for(int i=2;i<=n;i++){
		if(arr[i-1].lj<l-arr[i].a){
			arr[i].b=l;
			arr[i].lj=l-arr[i].a;
		}
		else{
			arr[i].b=arr[i-1].lj+1+arr[i].a;
			arr[i].lj=arr[i-1].lj+1;
		}
		if(arr[i].b>r){
			cout<<-1;
			return 0;
		}
	}
	sort(arr+1,arr+1+n,cmpp);
	for(int i=1;i<=n;i++){
		cout<<arr[i].b<<" ";
	}
	return 0;
}
//arr[i].c>=l-arr[i].a