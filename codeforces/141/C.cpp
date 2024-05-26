// LUOGU_RID: 160374741
#include<bits/stdc++.h>
#define int long long
#define N 3005
using namespace std;
int n;
struct node{
	string s;
	int num,ans;
}a[N];
int cmp(node a,node b){
	return a.num<b.num;
}
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].s>>a[i].num;
	stable_sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(a[i].num>=i){
			cout<<-1<<endl;
			return 0;
		}
		a[i].ans=i-a[i].num;
		for(int j=1;j<i;j++){
			if(a[j].ans>=a[i].ans) a[j].ans++;
		}
	}
	for(int i=1;i<=n;i++) cout<<a[i].s<<' '<<a[i].ans*100<<endl;
	return 0;
}

