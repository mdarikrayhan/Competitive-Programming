#include<bits/stdc++.h>
using namespace std;
 
void solve (){
int n,x;
    string str;
    cin>>str; 
    int a,b,c,d,e,f;
    for (int i=0;i<6;i++){
    	if (str[i]=='r'){
    		a=i+1;
    	}else if (str[i]=='b'){
    		b=i+1;
    	}
    	else if(str[i]=='g'){
    		c=i+1;
    	}
    	else if (str[i]=='R'){
    		d=i+1;
    	}
    	else if (str[i]=='B'){
    		e=i+1;
    	}
    	else if(str[i]=='G'){
    		f=i+1;
    	}
    }
    if (a<d and b<e and c<f){
    	cout<<"YES"<<endl;
    }else {
    	cout<<"NO"<<endl;
    }
         
 
}
int main(){
 int t;
 cin>>t;
 while (t--){
 	solve();
 }
}
