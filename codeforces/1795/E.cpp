// LUOGU_RID: 159935746
#include<bits/stdc++.h>
#define int long long
#define inf LONG_LONG_MAX/2
using namespace std;
const int N=3e5+10;
int a[N];
int n;
int f[N],g[N];
int s[N];
int cf[N],cg[N];
int cnf[N],cng[N];
int sum(int l,int r){
	return s[r]-s[l-1];
}
int get_be(int en,int d,int cnt){
	return en-d*(cnt-1);
}
int get(int be,int en,int cnt){
	return (be+en)*cnt/2;
}
struct node{
	int i;
	int val; 
};
stack<node>st;
signed main(){
//	freopen(".in","r",stdin);
//	freopen("ans.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			s[i]=s[i-1]+a[i];
		}
		a[n+1]=0;
		a[0]=0;
		f[0]=0;
		f[n+1]=0;
		g[0]=0;
		g[n+1]=0;
		while(st.size()){
			st.pop();
		}
		
		f[0]=0;
//		a[0]=a[1];
//		a[n+1]=a[n];
		st.push({0,-inf});
		for(int i=1;i<=n;i++){
			while(st.size()&&(st.top().val)>=(a[i]-i)){
//				cout<<":"<<st.top().i<<" "<<st.top().val<<endl;
				st.pop();
			}
			node p=st.top();
//			cout<<"ssshshde";
//			cout<<iu
			int pos=p.i;
			pos=max(pos,i-a[i]);
//			cout<<pos<<endl;
			f[i]=f[pos]-a[pos]+a[i]+sum(pos+1,i-1)-get(a[i]-(i-pos-1),a[i]-1,i-pos-1);
			if(i-pos==a[i]){
				f[i]+=sum(1,pos);
				f[i]+=a[pos];
				f[i]-=f[pos];
			}	
			st.push({i,a[i]-i});
//			cout<<pos<<endl;
//			cout<<i<<endl;
		}
		
//		cout<<"sdddffg";
		g[n+1]=0;
		while(st.size()){
			st.pop();
		}
//		cout<<"CJHD";
		st.push({n+1,-inf});
//		cout<<st.top().val<<endl;
		for(int i=n;i>=1;i--){
			while(st.size()&&(st.top().val)>=(a[i]+i)){
				st.pop();
			} 
//			cout<<st.size()<<endl;
			node p=st.top();
			int pos=p.i;
			st.push({i,a[i]+i});
			pos=min(pos,i+a[i]);
			g[i]=g[pos]-a[pos]+a[i]+sum(i+1,pos-1)-get(a[i]-(pos-1-i),a[i]-1,pos-i-1);
			if(a[i]==pos-i){
				g[i]+=sum(pos,n);
				g[i]+=a[pos];
				g[i]-=g[pos];
			}
//			cout<<i<<endl;
		}
//		cout<<"cptbtptp";
		int ans=inf;
//		for(int i=1;i<=n;i++){
//			cout<<g[i]<<" ";
//		}
//		cout<<endl;
		for(int i=1;i<=n;i++){
//			cout<<i<<" "<<f[i-1]<<" "<<g[i+1]<<endl;
			ans=min(ans,f[i]+g[i]-a[i]);
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
/*
1
3
1 1 1

1
4
4 1 2 1

1
5
5 5 5 5 5
hack 
std=11

1
11
1 2 1 2 1 2 3 4 2 1 4

1
4
5 10 15 10
 15
 
1
14
6 7 6 6 6 6 6 6 6 6 6 6 6 6
                
1
4
1 2 3 4 5  
*/