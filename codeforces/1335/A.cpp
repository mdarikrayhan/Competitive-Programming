/***************************************************/
/*https://codeforces.com/problemset/problem/1336/A */
/*            Author : Md. Arik Rayhan             */
/*        Github : github.com/mdarikrayhan         */
/***************************************************/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        long long int n;
        cin>>n;
        if(n<=2){
            cout<<0<<endl;
        }
        else{
            cout<<(n-1)/2<<endl;
        }
    }
}
