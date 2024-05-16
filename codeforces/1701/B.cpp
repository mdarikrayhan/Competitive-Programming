#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10,mod=998244353;
typedef long long ll;
typedef pair<ll,ll> PII;
ll n,m,k,x,y;
ll a[N],b[N];
int cnt[N];
int ne[N];


vector<ll> e[N];
bool tf[N];
void __(){
    cin>>n;
    for(int i=1;i<=n;i++) tf[i]=0;
    
    vector<int> v;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n&&!tf[j];j*=2){
            v.push_back(j);
        tf[j]=1;
        }
        
    }
    puts("2");
    for(auto x:v) printf("%d ",x);
    printf("\n");
}

signed main(){
// 	ios::sync_with_stdio(0);
// 	cin.tie(0);
	int _=1;
	cin>>_;
	while(_--){
		__();
	}
	
}