#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    string a[n][m];
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>a[i][j];           
        }
    }
    int t; cin>>t;
    vector<string>v;
    for(int i=0;i<=t;++i){
        string s;
        getline(cin,s);  
        v.push_back(s);    
    }
    int c1=0;
    int l=0,u=0;
    map<int,string>blue;
    int b=0,r=0;
    int y=(m+1)/2, x= (n+1)/2;
    for(int i=1;i<=t;++i){
        if(c1==1){
            if(v[i][3]=='T'){
                // cout<<l<<" "<<u<<endl;
                c1=0;
                y-= l; x-= u;
                // cout<<x<<" "<<y<<endl;               
                if(a[x-1][y-1]=="RG"){
                    b++;
                    blue[i-1]=" BLUE GOAL";
                    y=(m+1)/2; x= (n+1)/2;
                }
                else if(a[x-1][y-1]=="BG"){
                    r++;
                    blue[i-1]=" RED GOAL";
                    y=(m+1)/2; x= (n+1)/2;
                }
                l=0,u=0;
                // cout<<x<<" "<<y<<endl;
            }
            if(v[i][3]=='L'){
                l++;
            }
            else if(v[i][3]=='R'){
                l--;
            }
            else if(v[i][3]=='U'){
                u++;
            }
            else if(v[i][3]=='D'){
                u--;
            }
        }
        if(v[i][3]=='C'){
            c1=1;
        }
    }
    for(auto it: blue){
        cout<<it.first<<it.second<<endl;
    }
    cout<<"FINAL SCORE: "<<r<<" "<<b<<endl;
}