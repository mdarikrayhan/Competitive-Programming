/************************************************************************/
                    
/*  prashant_chaudhary  */  
                    
                    
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
                    
                    
#define fr(i,n)    for(int i=0; i<n; i++)
#define int        long long
#define ull        unsigned long long
#define float      long double
#define pb         push_back
#define vi         vector<int>
#define            umii unordered_map<int,int>
#define mii        map<int,int>
#define pi         3.14159265358979323846264338327950288419716939937510
const int MOD=1e9+7;
#define rn(n)      int n;cin>>n
#define rs(s)      string s;cin>>s
#define setbit(x)  builtin_popcount(x)
#define bit(x,y)   ( ((x)>>(y)) & 1 )
                        
                        
const int N=(2e5+5);
int lcm(int a, int b){
return (a/__gcd(a, b))*b;
}
int factorial(int n){
if(n==0)return 1;
int ans=1;
for(int i=1; i<=n; i++){ans=((ans)*(i));}
return ans;
}
bool isprime(int n){
if(n==2) return 1;
if(n==0 || n==1 || n%2==0) return 0;
for(int i=3; i<=sqrt(n); i+=2){
if(n%i==0){
return 0;
}
}
return 1;
}
int POW(int a,int b){
if(b==0) return 1;
int temp=POW(a,b/2);
if(b%2==0) return (temp*temp)%MOD;
else return (((temp*temp)%MOD)*a)%MOD;
}
                                     
                                     
void solve(){
    int n; cin>>n;
    int a[n]; fr(i,n)cin>>a[i];
    int s=0; int c=1;
    for(int i=n-1;i>=0;i--){
        if(a[i]!=0)c=0;
        if(c)continue;
        s+=a[i];
        if(s>=0 && i!=0){
            cout<<"NO"<<endl;return;
        }
    }
    cout<<(s?"NO":"YES")<<endl;
}
                  
                  
signed main()
{
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
int t=1;cin>>t;
while(t--)
{
solve();
}
    return 0;
}