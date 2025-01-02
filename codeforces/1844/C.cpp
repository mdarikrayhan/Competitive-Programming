#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long int> vect(n);
        for(int i=0;i<n;i++){
            cin>>vect[i];
        }

        long long int odd_max=0, even_max = 0;
        for(int i=0;i<n;i+=2){

            if(vect[i]>0){
                odd_max+=vect[i];
            }
        }
        

        for(int j=1;j<n;j+=2){
            if(vect[j]>0){
                even_max+=vect[j];
            }
        }
        
        long long int final_ans = max(odd_max, even_max);
        if(final_ans!=0){
            cout<<final_ans<<endl;
        }
        else{
            cout<<*max_element(vect.begin(), vect.end())<<endl;
        }

    }
    return 0;
}