#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b,c;
    cin>>n;
    cin>>a;
    cin>>b;
    cin>>c;
    if(n==1) cout<<0;
    else{
        int dis=0;
        int pre=1;
        int j=1;
        while(j<n){
            if(pre==1){
                if(a<b){
                    pre=2;
                    dis=dis+a;
                    j++;
                }
                else{
                    pre=3;
                    dis=dis+b;
                    j++;
                }
            }
            else if(pre==2){
                if(a<c){
                    pre=1;
                    dis=dis+a;
                    j++;
                }
                else{
                    pre=3;
                    dis=dis+c;
                    j++;
                }
            }
            else if(pre==3){
                if(b<c){
                    pre=1;
                    dis=dis+b;
                    j++;
                }
                else{
                    pre=2;
                    dis=dis+c;
                    j++;
                }
            }
        }
        cout<<dis;
    }
}