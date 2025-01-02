#include<bits/stdc++.h>
using namespace std;
#define	INF	1000001
int main() {

    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, q, m, a, b, c,arr[1001]={},cnt,sum,i;
	cin>>n;

	for (i=0;i< n;i++) cin>>q;

	for (i=1;i<=n;i++) arr[i]=INF;

	cin>>m;
	for (i=0;i<m;i++) {
		cin>>a>>b>>c;
		if (arr[b]>c) arr[b]=c;
	}

	cnt=0;
	sum=0;
	for(i=1;i<=n;i++){
		if(arr[i]==INF) cnt++;
		else sum+=arr[i];
	}

	if(cnt==1) cout<<sum<<'\n';
	else cout<<-1<<'\n';

	return 0;
}

