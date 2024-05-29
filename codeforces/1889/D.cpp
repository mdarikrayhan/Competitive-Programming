#include <bits/stdc++.h>
using namespace std;
#define a first
#define b second
#define pb push_back
//#define endl '\n'
typedef long long llo;

vector<int> pre[100001];
int ans[100001];
int ind[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int x;
			cin>>x;
			x--;
			pre[i].pb(x);
		}
		ans[i]=-1;
		ind[i]=-1;
	}
	for(int i=0;i<n;i++){
		int cur=i;
		int ind2=0;
		vector<int> tt;
		if(ans[i]>=0){
			continue;
		}
		ind[cur]=0;
		tt.pb(cur);
	//	cout<<i<<":"<<endl;

		while(true){
			cur=tt.back();
			/*cout<<tt.back()<<"::"<<endl;;
			for(auto j:tt){
				cout<<j<<";"<<ind[j]<<";";
			}
			cout<<endl;*/
			if(ans[cur]>=0){
				break;
			}
			if(pre[cur].size()==0){
				break;
			}
			
			int x=pre[cur].back();
			ind2+=1;
			if(ind[x]!=-1){
				tt.pb(x);
				while(tt.size()>ind[x]+1){
					int no=tt.back();
					tt.pop_back();
					pre[no].pop_back();
					if(no!=x){
						ind[no]=-1;
					}
				}
			}
			else{
				tt.pb(x);
				ind[x]=tt.size()-1;
			}
		}
		if(ans[tt.back()]>=0){
			for(auto j:tt){
				ind[j]=-1;
				ans[j]=ans[tt.back()];
				//cout<<j<<",";
			}
		}
		else{
			for(auto j:tt){
				ind[j]=-1;
				ans[j]=tt.back();
			//	cout<<j<<",";
			}
		}
		//cout<<endl;
	}
	for(int i=0;i<n;i++){
		cout<<ans[i]+1<<" ";
	}
	cout<<endl;












	return 0;
}