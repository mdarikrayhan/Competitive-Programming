#include<bits/stdc++.h>
#include<cstring>
//#define Psych_x7's Code
#define   ll         long long
#define   ull        unsigned long long
#define   pb         push_back
#define   em         emplace_back
#define   ff         first
#define   ss         second
#define   all(v)     (v.begin(), v.end())
#define   rall(v)    (v.rbegin(), v.rend())
#define   pi         acos(-1.0)
#define   FastRead   ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define   bug(a)     cerr << #a << " : " << a << endl
using namespace std;

int main() {
	//code
	ll T,i,j,F,N,k,l,m;
	string S,K;
	cin>>T;
	while(T--){
	    cin>>S>>K;
	    i=0;
	    j=0;
	    N=S.size();
	    k=0;
	    F=0;
	    vector<ll> V;
	    for(i=0;i<N;i++){
	        if(S[i]==K[0]){
	            V.em(i);
	        }
	    }
	    for(i=0;i<V.size();i++){
	        j=V[i];
	       // cout<<V[i]<<endl;
	        while(S[j]==K[k]){
	           // cout<<S[j]<<'*'<<endl;
	            k++;
	            m=j-1;
	            l=k;
	            while(m>=0 && k<K.size() && S[m]==K[k]){
	               // cout<<S[m]<<endl;
	                m--;
	                k++;
	            }if(k==K.size()){
	                F=1;
	                break;
	            }j++;
	            k=l;
	            if(S[j]!=K[k]){
	                k=0;
	                break;
	            }
	        }
	    }
	   // while(i<N){
	   //     if(S[i]==K[k]){
	   //         cout<<S[i]<<endl;
	   //         k++;
	   //         j=i-1;
	   //         l=k;
	   //         while(j>=0 && k<K.size() && S[j]==K[k]){
	   //             j--;
	   //             k++;
	   //         }if(k==K.size()){
	   //             F=1;
	   //             break;
	   //         }i++;
	   //         k=l;
	   //     }
	   //     if(S[i]!=K[k]){
	   //         k=0;
	   //     }
	   // }
	    if(F==1){
	        cout<<"YES"<<endl;
	    }else{
	        cout<<"NO"<<endl;
	    }
	}
	return 0;
}