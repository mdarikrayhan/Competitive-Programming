#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define PB push_back
#define PINT pair<int,int>
template <class T>
using  RPQ =  priority_queue<T,vector<T>,greater<T>>;
template <class T>
using PQ =  priority_queue<T>;
#define F first
#define S second
#define Pyes() cout<<"YES\n"
#define Pno() cout<<"NO\n"
/*std = c++2a*/
int mod=1e9+7;
int mod2=998244353;

int main()
{	
	int N=1;
    //cin>>N;
	while(N--){
        int n;
        cin>>n;
        int a1,a2,a3,b1,b2,b3;
        cin>>a1>>a2>>a3>>b1>>b2>>b3;
        int m=min(a1,b2)+min(a2,b3)+min(a3,b1);
        int d=max({0,b1-a1-a2,b2-a2-a3,b3-a3-a1});
        cout<<d<<" ";
        cout<<m<<endl;
    }
	return 0;
}