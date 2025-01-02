// LUOGU_RID: 160457388
#include<bits/stdc++.h>
using namespace std;
int n,m,minx=10000,miny=10000,ans;
char a[21][21];
bool check(int h,int w){
//	cout<<h<<" "<<w<<"\n";
	map<string,bool>mp;
	bool f=1;
	for(int i=1;i<=n;i+=h){
		for(int j=1;j<=m;j+=w){
			string s1,s2,s3,s4;//0
			for(int k=i;k<=i+h-1;k++){
				for(int l=j;l<=j+w-1;l++){
					s1+=a[k][l];
				}
			}
//			cout<<s1<<"\n";
			if(w==h){
				for(int l=j;l<=j+w-1;l++){
					for(int k=i+h-1;k>=i;k--){
						s2+=a[k][l];
					}
				}
			}
//			cout<<s2<<"\n";
			for(int k=i+h-1;k>=i;k--){
				for(int l=j+w-1;l>=j;l--){
					s3+=a[k][l];
				}
			}
//			cout<<s3<<"\n";
			if(w==h){
				for(int l=j+w-1;l>=j;l--){
					for(int k=i;k<=i+h-1;k++){
						s4+=a[k][l];
					}
				}
			}
//			cout<<s4<<"\n\n";
			if(mp[s1]||mp[s2]||mp[s3]||mp[s4]){
				f=0;
			}
			mp[s1]=1,mp[s2]=1,mp[s3]=1,mp[s4]=1,mp[""]=0;
		}
//		cout<<"\n";
	}
//	cout<<"\n";
	return f;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(n%i||m%j){
				continue;
			}
			if(check(i,j)){
				ans++;
				if(i*j<minx*miny||i*j==minx*miny&&i<minx){
					minx=i;
					miny=j;
				}
			}
		}
	}
	cout<<ans<<"\n";
	cout<<minx<<" "<<miny;
} 