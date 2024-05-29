#include<bits/stdc++.h>
using namespace std;

int n,m,f;
vector<vector<int>> vec;

int main(){
	cin>>n>>m;
	if(n==1&&m==1) return cout<<"YES"<<endl<<1<<endl,0;
	if(n>m){
		swap(n,m);
		f=1;
	}
	vec.resize(n);
	
	if(n<3&&m<=3) return cout<<"NO"<<endl,0;
	cout<<"YES"<<endl;
	if(n==1){
		int p=(m+1)/2+1;
		if(m&1) vec[0].push_back(1);
		for(int i=1+(m&1),j=p;i<p;i++,j++){
			vec[0].push_back(j);
			vec[0].push_back(i);
		}
		for(int j=0;j<m;j++){
			cout<<vec[0][j]<<" ";
			if(f) cout<<endl;
		}
		cout<<endl;
		return 0;
	}
	else if(n==3&&m==3){
		cout<<"6 1 8"<<endl;
		cout<<"7 5 3"<<endl;
		cout<<"2 9 4"<<endl;
		return 0;
	}else{
		if(f) swap(n,m);
		vec.resize(n);
		for(int i=0;i<n;i++){
			for(int j=1;j<=m;j++){
				vec[i].push_back(i*m+j);
			}
		}
		
		if(m>=n){
			for(int i=0;i<n;i++){	
				int cnt=2*(i&1);
				while(cnt--){
					for(int j=0;j<m-1;j++){
						swap(vec[i][j],vec[i][j+1]);
					}
				}
			}
			for(int j=0;j<m;j++){
				int cnt=j&1;
				while(cnt--){
					for(int i=0;i<n-1;i++){
						swap(vec[i][j],vec[i+1][j]);	
					}
				}
			}		
		}else{
			for(int j=0;j<m;j++){
				int cnt=2*(j&1);
				while(cnt--){
					for(int i=0;i<n-1;i++){
						swap(vec[i][j],vec[i+1][j]);
					}
				}
			}
			for(int i=0;i<n;i++){
				int cnt=i&1;
				while(cnt--){
					for(int j=0;j<m-1;j++){
						swap(vec[i][j],vec[i][j+1]);
					}
				}
			}
		}
		
		
	}
	
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<vec[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
	return 0;
}