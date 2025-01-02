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

int main()
{	
	int N;
    cin>>N;
	while(N--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(auto &e:v) cin>>e;
        if(n==1){
            cout<<"T"<<endl;
            continue;
        }
        PQ<int> pq;
        for(auto e:v) pq.push(e);
        while(pq.size()>=2){
            int a=pq.top()-1;
            pq.pop();
            int b=pq.top()-1;
            pq.pop();
            
            if(a>0) pq.push(a);
            if(b>0) pq.push(b);
        }
        cout<<(pq.size()==1?"T":"HL")<<endl;
	}
	return 0;
	
}