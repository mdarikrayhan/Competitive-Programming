#include <bits/stdc++.h>

using namespace std;

bool cross(pair<long long,long long>p,pair<long long,long long>p1,pair<long long,long long>p2){
    return (((__int128)(p.second-p1.second))*(p2.first-p1.first))<=(((__int128)(p.first-p1.first))*(p2.second-p1.second));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for(int &i : a){
        cin >> i;
    }
    long long pref[n+1];
    pref[0]=0;
    for(int i = 1;i<n+1;i++){
        pref[i]=pref[i-1]+a[i-1];
    }
    vector<int>pts;
    pts.push_back(0);
    int sz = 1;
    for(int i = 1;i<n+1;i++){
        while(sz>1&&cross({i,pref[i]},{pts[sz-2],pref[pts[sz-2]]},{pts[sz-1],pref[pts[sz-1]]})){
            pts.resize(sz-1);
            sz--;
        }
        pts.push_back(i);
        sz++;
    }
    int ind = 0;
    double relpref[n];
    for(int i = 0;i<sz;i++){
        int inds = ind;
        while(ind<pts[i]){
            relpref[ind]=(1.0*(ind-inds+1)*(1.0*(pref[pts[i]]-pref[pts[i-1]])/(pts[i]-pts[i-1])))+pref[pts[i-1]];
            ind++;
        }
    }
    cout << fixed << setprecision(10)<< relpref[0] << "\n";
    for(int i = 1;i<n;i++){
        cout << fixed << setprecision(10) << relpref[i]-relpref[i-1] << "\n";
    }
    return 0;
}
