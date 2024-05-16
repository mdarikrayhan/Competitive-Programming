#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define ff first
#define ss second
using namespace std;


const int M=1e9 + 7;

int bexp(int a,int b,int m){
	ll ans=1;
	while(b>0){
		if(b&1){
			ans=(ans*1LL*a)%m;
		}
		a=(a*1LL*a)%m;
		b>>=1;
	}

	return ans;
}


// void solve(){
// 	ll n;
// 	cin>>n;

// 	vector<ll> fans;
// 	for(int i=1;i<=n;i++){
// 		ll sqn=(n+1)*(n+1);

// 		ll ans=0;
// 		ll s=0,e=i;
// 		while(s<=e){
// 			ll mid=s+(e-s)/2;

// 			ll check= (i*i)+(mid*mid);

// 			if(check>=n*n){
// 				ans=mid;
// 				e=mid-1;
// 			}
// 			else{
// 				s=mid+1;
// 			}
// 		}

// 		ll ans2=0;
// 		s=0,e=i;
// 		while(s<=e){
// 			ll mid= s+(e-s)/2;

// 			ll check= (i*i)+(mid*mid);

// 			if(check<(n+1)*(n+1)){
// 				ans2=mid;
// 				s=mid+1;
// 			}
// 			else{
// 				e=mid-1;
// 			}
// 		}

// 		// cout<<"i "<<i<<" "<<ans<<" "<<ans2<<endl;

// 		if(i==n) fans.pb(ans2-ans);
// 		else if(ans!=0) fans.pb(ans2-ans+1);
// 		else fans.pb(0);

// 	}

// 	for(auto i: fans){
// 		cout<<i<<" ";
// 	}
// 	cout<<endl;

// 	ll ans=0;
// 	for(int i=1;i<=fans.size();i++){
// 		if(fans[i-1]==i) ans+=fans[i-1]*4+4;
// 		else if(fans[i-1]!=0) ans+=fans[i-1]*8;
// 	}

// 	cout<<ans<<endl;
// 	cout<<endl;

// }

// void solve(){

// 	int n;
// 	cin>>n;

// 	ll arr[n+1];
// 	map<ll,ll> mp;
// 	for(int i=1;i<=n;i++){
// 		cin>>arr[i];
// 		mp[arr[i]]++;
// 	}

// 	ll maxi=0;
// 	for(int i=1;i<=n;i++){
// 		ll ans=0;
// 		for(int j=1;j*j<=i;j++){
// 			if(i%j==0){
// 				ans+=mp[j];
// 				if(i/j!=j){
// 					ans+=mp[i/j];
// 				}
// 			}
// 		}

// 		maxi=max(maxi,ans);
// 	}


// 	cout<<maxi<<endl;
	

// }


// void solve(){

// 	int n;
// 	cin>>n;

// 	vector<int> arr(1000001,0);
// 	for(int i=0;i<n;i++){
// 		int x;
// 		cin>>x;

// 		arr[x]++;
// 	}

// 	 for(int i=1000000;i>=1;i--){

// 		ll multiple=0;

// 		for(int j=i;j<=1000000;j+=i){
// 			multiple+= arr[j];
// 		}

// 		if(multiple>1){
// 			cout<<i<<endl;
// 			return;
// 		}

// 	 }

// }

int numcreator(string s){
	int n=s.size();

	int num=0,pwer=0;
	for(int i=n-1;s[i]!=' ';i--){
		cout<<"str "<<s<<" ff "<<s[i]-'0'<<endl;
		if(s[i]-'0'!=0){
			num+= (s[i]-'0')*pow(10,pwer);
			cout<<"num "<<num<<endl;
		}
		
		pwer++;
	}

// 1000000
	return num;
}

// void solve(){
// 	int n,k;
// 	cin>>n>>k;

// 	vector<int> arr(n+1,0);
// 	vector<int> fac(100001,0);

// 	for(int i=0;i<k;i++){
// 		string s;
// 		int num;
// 		cin>>s>>num;
// 		int no=num;

// 		if(s[0]=='-'){
// 			if(arr[num]==1){
// 				arr[num]=0;
// 				for(int i=2;i*i<=num;i++){
// 					while(num%i==0){
// 						fac[i]=0;
// 						num/=i;
// 					}
// 				}
// 				if(num>1){
// 					fac[num]=0;
// 				}
// 				cout<<"Success"<<endl;
// 			} 
// 			else{
// 				cout<<"Already off"<<endl;
// 			} 
// 		}

// 		if(s[0]=='+'){
// 			if(arr[num]==1){
// 				cout<<"Already on"<<endl;
// 			}
// 			else{
	
// 				vector<int> factors;
// 				int flag=1;
// 				for(int i=2;i*i<=num;i++){
// 					if(num%i==0){
// 						if(fac[i]>0){
// 							cout<<"Conflict with "<<fac[i]<<endl;
// 							flag=0;
// 							break;
// 						} 
// 						factors.pb(i);
// 					}
// 					while(num%i==0){
// 						num/=i;
// 					}
// 				}
// 				if(num>1 && flag){
// 					if(fac[num]>0){
// 							cout<<"Conflict with "<<fac[num]<<endl;
// 							continue;
// 						} 
// 						factors.pb(num);
// 				}

// 				if(flag){
// 					for(int i=0;i<factors.size();i++){
// 					fac[factors[i]]=no;
// 				}
				
// 				arr[no]=1;
// 				cout<<"Success"<<endl;
// 				}
				
// 			}
// 		}

// 	}
// }


void solve(){

	vector<int> isPrime(1001,1);

	isPrime[0]=isPrime[1]=0;

	for(int i=2;i<=1000;i++){
		for(int j=i*i;j<=1000;j+=i){
			isPrime[j]=0;
		}
	}

	int n;
	cin>>n;

	int num=n;

	vector<int> ftr;
	for(int i=0;i<=n;i++){
		if(isPrime[i]==1){
			int pow=i;
			while(pow<=n){
				ftr.pb(pow);
				pow*=i;

			}

		}
	}

	cout<<ftr.size()<<endl;
	for(auto i:ftr){
		cout<<i<<" ";
	}
	cout<<endl;


}

int main(){
	int t=1;
	// cin>>t;

	while(t--){

		solve();
		
	}
}
