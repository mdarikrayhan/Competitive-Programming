/**************************************/
/*      Author : Md. Arik Rayhan      */
/*  Github : github.com/mdarikrayhan  */
/**************************************/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n=0,c=0;
    cin>>n;
    n*=2;
    int arr[n];
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    for (int i=0;i<n;i+=2){
        if(arr[i]+1<arr[i+1]){
            c++;
        }
    }
    cout<<c;
}
   