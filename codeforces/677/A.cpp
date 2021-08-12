/**************************************/
/*      Author : Md. Arik Rayhan      */
/*  Github : github.com/mdarikrayhan  */
/**************************************/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,h,width=0;
    cin>>n>>h;
    int arr[n];
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    for(int i=0;i<n;++i){
        if(arr[i]<=h){
            width++;
        }
        else{
            width+=2;
        }
    }
    cout<<width;
}
