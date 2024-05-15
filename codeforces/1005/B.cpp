#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {

    //int t;cin>>t;
    //while (t--){
        string x,y;cin>>x>>y;
        int count=0;
        if(x.length()<y.length()){
            swap(x,y);
        }
        for (int i = x.length()-1,j=y.length()-1;  j >= 0; --i,j--) {
            if(x[i]==y[j]){
                count+=2;
            }else{
                break;
            }
        }
        cout<<(x.length()+y.length())-count;


    //}






}