#include<bits/stdc++.h>
using namespace std;
 
#define all(x) x.begin(),x.end()
#define fi first
#define se second
 
#define int long long //tehlikeli
 
#define pb push_back 
#define sp <<' '<<
 
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef vector<bool> vb;
 
#define FOR(i,a) for(int i=0;i<(a);i++)
#define FORE(i,a,b) for(int i=(a);i<(b);i++)
#define contp(a) for(auto el:a) {cout<<el.fi<<'-'<<el.se<<' ';}cout<<endl
#define cont(a) for(auto el:a) {cout<<el<<' ';}cout<<endl
#define topla(a,b) (a+b)%MOD
#define carp(a,b) (a*b)%MOD
#define cikar(a,b) (a-b)%MOD
 
const int MAXN=2e5+5;
const int INF=1e9;
const int MOD=1e9+7;

int exp(int x,int us){
    int res=1;
    while(us){
        if(us%2) res=res*x;
        x=x*x;
        us/=2;
    }

    return res;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        int bas1=1;
        int bas2=1;
        FORE(i,1,9){
            
            if(b/exp(10,i)>0){
                bas2++;
            }
            if(a/exp(10,i)>0){
                bas1++;
            }
        }

        //cout<<"bas:" sp bas1 sp bas2<<endl;

        int cev1=-1;
        int cev2=-1;

        FORE(i,0,bas1+1){
            cev1=cev1+(a/exp(10,i));
        }

        FORE(i,0,bas2+1){
            //cout<<"i" sp i sp "cev2" sp cev2<<endl;
            cev2=cev2+(b/exp(10,i));
        }

        //cout<<"cev" sp cev1 sp cev2<<endl;

        cout<<cev2-cev1<<endl;



    }

}