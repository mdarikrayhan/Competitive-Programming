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
	ll N,M,X,Y,i,Z,C,F,j,max;
	string S;
	cin>>N;
	M=1000;
	cin>>S;
	ll A[N][M];
	for(i=0;i<N;i++){
	    cin>>X>>Y;
	    if(S[i]=='1'){
	        Z=1;
	    }if(S[i]=='0'){
	        Z=0;
	    }C=0;
	    F=0;
	    for(j=0;j<M;j++){
	        if(j<Y){
	            A[i][j]=Z;
	            continue;
	        }if(F==0){
	            if(Z==1){
	                Z=0;
	                F=1;
	            }
	        }if(F==0){
	            if(Z==0){
	                Z=1;
	                F=1;
	            }
	        }
	        if(C<X){
	            A[i][j]=Z;
	            C++;
	        }if(C==X){
	            C=0;
	            F=0;
	        }
	    }
	}max=0;
	for(i=0;i<M;i++){
	    C=0;
	    for(j=0;j<N;j++){
	        C=C+A[j][i];
	    }if(C>max){
	        max=C;
	    }
	}cout<<max<<endl;
	return 0;
}