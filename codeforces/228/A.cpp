/***************************************************/
/*https://codeforces.com/problemset/problem/288/A  */
/*            Author : Md. Arik Rayhan             */
/*        Github : github.com/mdarikrayhan         */
/***************************************************/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[4];
    cin>>arr[0]>>arr[1]>>arr[2]>>arr[3];
    int count=0;
    for(int i=0;i<4;i++){
        for(int j=i+1;j<4;j++){
            if(arr[i]==arr[j]){
                count++;
            }
        }
    }
    if(count>3){
        cout<<3;
    }
    else if(count==3){
        cout<<2;
    }
    else{
        cout<<count;
    }
}
