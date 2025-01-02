// LUOGU_RID: 153327509
#define private public
#include<iostream>
#include<random>
using namespace std;
int n;
unsigned int a[10001],r;
unsigned int f(unsigned int x){
    unsigned int res=(x^x>>18)^((x^x>>18)<<15&0xefc60000UL);
    for(int i=1;i<=4;i++){
        res^=res<<7&0x9d2c5680UL&(1UL<<7)-1<<7*i;
    }
    for(int i=2;i>=0;i--){
        res^=res>>11&(1UL<<11)-1<<11*i;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>n;
    for(int i=1;i<=min(n,624);i++){
        cout<<'?'<<' '<<i<<' '<<i<<endl;
        cin>>a[i];
    }
    if(n>624){
        mt19937 g(0);
        g._M_p=624;
        for(int i=1;i<=624;i++){
            g._M_x[i-1]=f(a[i]);
        }
        for(int i=625;i<=n;i++){
            a[i]=g();
        }
    }
    r=a[1];
    for(int i=1;i<=n;i++){
        r=min(r,a[i]);
    }
    cout<<'!'<<' '<<r<<endl;
    return 0;
}