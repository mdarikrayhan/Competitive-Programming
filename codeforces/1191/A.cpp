#include <iostream>
using namespace std;
int main(){
    int x;
    cin>>x;
    int a;
    if(x%4 ==0){
        a=1;
        cout<<a<<" "<<"A"<<endl;
    }
    else if(x%4 ==1){
        a=0;
        cout<<a<<" "<<"A"<<endl;
    }
    else if(x%4 ==2){
        a=1;
        cout<<a<<" "<<"B"<<endl;
    }
    else if(x%4 ==3){
        a=2;
        cout<<a<<" "<<"A"<<endl;
    }
    return 0;
}