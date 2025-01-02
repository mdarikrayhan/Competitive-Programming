#include <iostream>

using namespace std;
int a[10000000];
int main()
{
    int t;
    cin>>t;
    int n;
    for(int i=0;i<t;i++){
        cin>>n;
for(int i=0;i<n;i++){
    cin>>a[i];
}
a[n]=-1;
for(int i=n-1;i>=0;i--){
    a[i]=max(a[i],a[i+1]-1);
}
for(int i=0;i<n;i++){
    if(a[i]==0){cout<<0<<" ";}else{cout<<1<<" ";}
}
cout<<endl;
    }
    return 0;
}
