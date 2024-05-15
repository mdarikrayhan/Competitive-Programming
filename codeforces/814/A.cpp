#include<bits/stdc++.h>
#include<string>
using namespace std;



int main(){
    int n,k;
    cin>>n>>k;

    int x[n];
    int y[k];

    for(int i=0;i<n;i++){
      cin>>x[i];

    }
    for(int i=0;i<k;i++){
        cin>>y[i];
    }
    sort(y,y+k);

    int j=k-1;

    for(int i=0;i<n;i++){
        if(x[i]==0){
            x[i]=y[j--];
        }
    }
        int t[n];
        for(int i=0;i<n;i++){
            t[i]=x[i];
        }
        sort(t,t+n);

        bool sorted=false;
        for(int i=0;i<n;i++){
            if(t[i]!=x[i]){
                cout<<"Yes"<<endl;
                sorted=true;
                break;
            }
        }
        if(!sorted){
            cout<<"No"<<endl;
        }
    return 0;
}