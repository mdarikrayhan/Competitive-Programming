#include<bits/stdc++.h>
using namespace std;
int main(){
    long long x, y ,z;
    char c;
    long long mxt=-2147483647, mxg=-2147483647, mxp=-2147483647;
    string namet, nameg, namep;
    long long n;
    cin>>n;
    while(n--){
        long long t, taxi=0, girl=0, pizza=0;
        string s;
        cin>>t>>s;
        while(t--){
            cin>>x>>c>>y>>c>>z;
            if(x==y and x==z and x%11==0){
                taxi++;
            }
            else if(x/10>x%10 and x%10>y/10 and y/10>y%10 and y%10>z/10 and z/10>z%10){
                pizza++;
            }
            else
                girl++;
        }
        if(taxi>mxt){
            mxt=taxi;
            namet=s;
        }
        else if(taxi==mxt){
            namet+=(", "+s);
        }
        if(pizza>mxp){
            mxp=pizza;
            namep=s;
        }
        else if(pizza==mxp){
            namep+=(", "+s);
        }
        if(girl>mxg){
            mxg=girl;
            nameg=s;
        }
        else if(girl==mxg){
            nameg+=(", "+s);
        }
    }
    cout<<"If you want to call a taxi, you should call: "<<namet<<'.'<<endl;
    cout<<"If you want to order a pizza, you should call: "<<namep<<'.'<<endl;
    cout<<"If you want to go to a cafe with a wonderful girl, you should call: "<<nameg<<'.'<<endl;
}
