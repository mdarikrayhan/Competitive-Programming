#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>vec;
    for(int b=0;b<n;b++){
        long long int d;
        cin>>d;
        vec.push_back(d);
    }
    long long int e=abs(vec[0]);
    for(int f=1;f<n;f++){
        e=e+abs(vec[f]-vec[f-1]);
    }
    cout<<e<<"\n";
} 