/***************************************************/
/*https://codeforces.com/problemset/problem/1030/A  */
/*            Author : Md. Arik Rayhan             */
/*        Github : github.com/mdarikrayhan         */
/***************************************************/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,sum=0;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        sum+=a;
    }
    if(sum==0){
    cout<<"EASY";}
    else{
    cout<<"HARD";}
}
