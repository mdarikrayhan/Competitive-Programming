#include<iostream>

using namespace std;

int main(){
    int n,top,x,y;
    bool flag=true;
    cin>>n>>top;
    int bottom=7-top;
    while(n>0){
        cin>>x>>y;
        int temp1,temp2;
        temp1=7-x;
        temp2=7-y;
        if(temp1!=top && temp1!=bottom && temp2!=top && temp2!=bottom){
            n--;
            continue;
        }else{
            flag=false;
            n--;
        }
    }
    if(flag){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    return 0;
}
	  	   		  	   	  	  	    					