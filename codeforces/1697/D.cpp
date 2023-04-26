#include<bits/stdc++.h>
using namespace std;
int n,x;
char c;
string s;
vector<int> v;
int main(){
    cin>>n;
	for(int i=0;i<n;i++){
		int l=-1,r=v.size();
		r--;
		while(l<r){
			int m=(l+r+1)/2;
			cout<<"? 2 "<<v[m]+1<<' '<<i+1<<endl;
			cin>>x;
			if(x==v.size()-m+1){
				r=m-1;
			}else{
				l=m;
			}
		}
		if(l==-1){
			cout<<"? 1 "<<i+1<<endl;
			cin>>c;
			s+=c;
			v.push_back(i);
		}else{
			s+=s[v[l]];
			v[l]=i;
			sort(v.begin(),v.end());
		}
	}
	cout<<"! "<<s<<endl;
	return 0;
}