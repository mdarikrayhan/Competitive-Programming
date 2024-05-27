// LUOGU_RID: 160480595
#include <iostream>
using namespace std;
int main() {
    int n, a, b, c; cin >> n >> a >> b >> c;
    int ans=0;
    for(int i=0;i<=a;i+=2){
        for(int j=0;j<=c;j++){
            if(n-(i/2+j*2)<=b&&n-(i/2+j*2)>=0){
                ans++;
            }
        }
    }
    cout<< ans << endl;
    return 0;
}
