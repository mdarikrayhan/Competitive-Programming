#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1000000007;
ll binarySearchArray(ll nums[],ll low,ll high,ll num){
	while(low<=high) {
        ll mid=low+(high-low)/2;
        if(num==nums[mid]){
            return mid;
        }
        if(num>nums[mid]){
            low=mid+1;
        }
        if(num<nums[mid]){
            high=mid-1;
        }
    }
	return -1;
}
ll binarySearchVector(vector<int> nums,ll low,ll high,ll num){
	while(low<=high) {
        ll mid=low+(high-low)/2;
        if(num==nums[mid]){
            return mid;
        }
        if(num>nums[mid]){
            low=mid+1;
        }
        if(num<nums[mid]){
            high=mid-1;
        }
    }
	return -1;
}
ll gcd(ll a,ll b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
ll lcm(int a,int b){
	return (a/gcd(a,b))*b;
}
ll power(ll a,ll b) {
    ll res=1;
    while(b>0){
        if(b&1){
            res*=a;
		}
        a*=a;
        b>>=1;
    }
    return res;
}
ll powermod(ll a,ll b,ll m){
	ll res=1;
	a%=m;
    while(b>0){
        if(b&1){
            res=(res*a)%m;
		}
        a=(a*a)%m;
        b>>=1;
    }
    return res;
}
bool prime(ll n){
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){
			return false;
		}
	}
	return true;
}
void lower(string &s){
	transform(s.begin(),s.end(),s.begin(),::tolower);
}
void upper(string &s){
	transform(s.begin(),s.end(),s.begin(),::tolower);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,num,fc=0,zc=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num;
        if(num==0){
            zc++;
        }
        else{
            fc++;
        }
    }
    if(zc==0){
        cout<<-1;
    }
    else{
        fc=(fc/9)*9;
        for(int i=0;i<fc;i++){
            cout<<5;
        }
        if(fc/9==0){
            cout<<0;
        }
        else{
            for(int i=0;i<zc;i++){
                cout<<0;
            }
        }
    }
    cout<<"\n";
}