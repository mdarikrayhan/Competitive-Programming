/***************************************************/
/*https://codeforces.com/problemset/problem/136/A  */
/*            Author : Md. Arik Rayhan             */
/*        Github : github.com/mdarikrayhan         */
/***************************************************/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=1;i<=n;++i){
        int a;
        cin>>a;
        arr[a]=i;
    }
    for(int i=1;i<=n;++i){
        cout<<arr[i];
        cout<<" ";
    }
}
