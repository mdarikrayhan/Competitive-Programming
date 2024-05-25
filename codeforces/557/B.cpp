#include <bits/stdc++.h>
using namespace std;
void solve(){
    int size;
    int max_cap;
    cin>>size>>max_cap;
    std::vector<int> arr(size*2) ;
    for (int i=0;i<size*2;++i){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    int min_f=1e9+1, min_m=1e9+1;
    for (int i=0;i<size;++i){
        min_f=min(min_f,arr[i]);
    }
    for (int i=size;i<size*2;++i){
        min_m=min(min_m,arr[i]);
    }
    double x=min(min_m*1.0,2.0*min_f)/2;
    double ans=min(3*x*size,max_cap*1.0);
    cout<<fixed<<setprecision(10)<<ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();

    return 0;
}