#include <bits/stdc++.h>
using namespace std;
#define xx first
#define yy second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define aro(x) for(int i=0;i<x.size();i++){cout<<x[i]<<" ";}cout<<endl
#define int long long
#define _ << " " <<
const int mod = 1e9+7;

int32_t main(void){
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int n,m,q;
    cin >> n >> m >> q;
    vector<vector<string>> grid(n,vector<string>(m,"???"));
    map<string,pair<int,int>> ma;
    while(q--){
        string op;
        cin >> op;
        string id;
        if(op=="+1"){
            int x,y;
            cin >> x >> y >> id;
            x--;y--;
            bool found = false;
            for(int i=x;i<n;i++){
                for(int j=0;j<m;j++){
                    if(i==x && j==0)j = y;
                    if(grid[i][j]!="???"){
                        continue;
                    }
                    else{
                        //cout << i+1 _ j+1 << " ->" _ id << endl;
                        found = true;
                        grid[i][j] = id;
                        ma.insert({id,{i,j}});
                        break;
                    }
                }
                if(found)break;
            }
        }
        else if(op=="-1"){
            cin >> id;
            bool found = false;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]==id){
                        found = true;
                        cout << i+1 _ j+1 << endl;
                        grid[i][j] = "???";
                        break;
                    }
                }
                if(found)break;
            }
            if(!found){
                cout << "-1 -1" << endl;
            }
        }
    }
    return 0;
}
