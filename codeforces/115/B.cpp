#include<bits/stdc++.h>
#define int long long int
#define mod 100000000
#define int_max 1e18
#define inf 10000001
#define hae printf("YES\n")
#define na printf("NO\n")

using namespace std;
int i,j,K,L,ts=0;
// start journey



void solve(){
    int n,m;
    cin >> n >> m;
    char ch[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> ch[i][j];
        }
    }
    vector<int>ind,fst,lst;
    for(int i=0; i<n; i++){
        int a=-1,b=-1,s=0;
        for(int j=0; j<m; j++){
            if(ch[i][j]=='W'){
                if(s==0){
                    a=j;
                    s=1;
                }
                b=j;
            }
        }
        if(i==0 && a==-1){
            ind.push_back(0);
            fst.push_back(0);
            lst.push_back(0);
        }
        if(a!=-1){
            ind.push_back(i);
            fst.push_back(a);
            lst.push_back(b);
        }
    }
    int point=0;
    int ans=0;
    for(int i=0; i<ind.size(); i++){
        if(ind[i]%2==0){
            if(fst[i]<point){
                ans+=abs(point-fst[i]);
                point=fst[i];
            }
            if(lst[i]>point){
                ans+=abs(point-lst[i]);
                point=lst[i];
            }
        }
        else{
            if(lst[i]>point){
                ans+=abs(point-lst[i]);
                point=lst[i];
            }
            if(fst[i]<point){
                ans+=abs(point-fst[i]);
                point=fst[i];
            }
        }
    }
    for(int i=0; i<ind.size()-1; i++){
        ans+=abs(ind[i]-ind[i+1]);
    }
    cout << ans << endl;


}


int32_t main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    int t=1;
    //cin >> t;
    while(t--){
        solve();
    }
}