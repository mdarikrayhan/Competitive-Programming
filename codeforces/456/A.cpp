#include<bits/stdc++.h>
using namespace std;

bool soln(int n, vector<pair<int,int>>v){
    for(int i = 1; i<n; i++){
        if(v[i].second < v[i-1].second){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cin>>n;

    vector<pair<int,int>>v;

    for(int i = 0; i<n; i++){
        int x;
        int y;
        cin>>x>>y;

        v.push_back({x,y});
    }

    sort(v.begin(), v.end());

    if(soln(n,v)){
        cout<<"Poor Alex"<<endl;
    }else{
        cout<<"Happy Alex"<<endl;
    }
    return 0;
}