#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int t;
        vector<int> arr(3);
        for(int i=0; i<3; i++){
            cin>>t;
            arr[i] = t;
        }
        int d = (abs(arr[0] + arr[2] - (2*arr[1])));
        if((d%3))cout<<"1\n";
        else 
        cout<<"0\n";
        
    }
    return 0;
}