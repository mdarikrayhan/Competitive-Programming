#include<bits/stdc++.h>
using namespace std;
using ll = long long;
typedef unsigned long long int  lli;
#define s  second
#define f  first
using vi = vector<ll>;
#define pb push_back
#define CEIL(a,b) (a+b-1)/b;
#define yes cout << "YES"<<endl;
#define no cout << "NO"<<endl;
#define setprecision(x) fixed<<setprecision((int)(x))
#define mp make_pair
#define PI  acos(-1.0);
#define io ios::sync_with_stdio(0);cin.tie(0);
const int inf = 1e12; 
const int M = 1e9+7;
const int N = 1e5+10;
int digitsum(int n){
    if(n<10) return n;
    return digitsum(n/10) + (n%10);
}
int main(){ io;
	int t;
    cin>>t;
    while(t--){
        int x,k;
        cin>>x>>k;
        int c = digitsum(x);
        if(c%k==0){
            cout<<x<<endl;
        }else{
            while(digitsum(x)%k!=0){
                x++;
            }
            cout<<x<<endl;
        }
    }
return 0;
}