// LUOGU_RID: 160271638
#include<bits/stdc++.h>
#define int long long
using namespace std;
struct st{
	string name;
	int g;
}a[1005],b[1005];
bool cmp(st a,st b){
	if(a.name!=b.name){
		return a.name<b.name;
	}
	else{
		return a.g>b.g;
	}
}
signed main(){	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].name>>a[i].g;
	}
	sort(a+1,a+n+1,cmp);
	int o=0;
	for(int i=1;i<=n;i++){
//		cout<<a[i].name<<" "<<a[i].g<<endl;
		b[++o].name=a[i].name;
		b[o].g=a[i].g;
		if(a[i].name==a[i+1].name){
			while(1){
				if(a[i].name==a[i+1].name){
					i++;
				}
				else{
					break;
				}
			}
		}
	}
	cout<<o<<endl;
	for(int i=1;i<=o;i++){
		int ans=0;
		for(int j=1;j<=o;j++){
			if(b[j].g>b[i].g){
				ans++;
			}
		}
		cout<<b[i].name<<" ";
		if(ans*1.0/o>0.5){
			cout<<"noob"<<endl;
		}
		else if(ans*1.0/o>0.2){
			cout<<"random"<<endl; 
		}
		else if(ans*1.0/o>0.1){
			cout<<"average"<<endl; 
		}
		else if(ans*1.0/o>0.01){
			cout<<"hardcore"<<endl;
		}
		else{
			cout<<"pro"<<endl;
		}
	}
    return 0;
}