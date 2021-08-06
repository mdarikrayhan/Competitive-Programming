#include<iostream>
using namespace std;
 
int main()
{
    int w;
    cin>>w;
    if(w==2){
        printf("NO");
    }
    else if(w >=1){
            if(w<=100){
    int m;
    m=(w%2);
    if(m==0){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
 
            }
    else {
    cout<<"NO";
    }
    }
    else{
    cout<<"NO";
    }
    return 0;
}