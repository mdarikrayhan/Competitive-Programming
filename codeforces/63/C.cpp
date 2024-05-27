#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    vector<pair<string,pair<int,int>>> a(n);
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        int x,y;
        cin>>x>>y;
        a[i] = {s,{x,y}};
    }
    vector<string> v;
    
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(i == j) continue;
            for(int k=0;k<10;k++){
                if(i == k || j == k) continue;
                for(int l=0;l<10;l++){
                    if(l == i || j == l || k == l) continue;
                    string s;
                    s+=(i+'0');
                    s+=(j+'0');
                    s+=(k+'0');
                    s+=(l+'0');
                    v.push_back(s);
                }
            }
        }
    }
    
    // cout<<v.size()<<endl;
    int count = 0;
    string ans;
    for(auto it1:v){
        bool check = true;
        for(auto it2:a){
            int bull=0,cow=0;
            for(int i=0;i<4;i++){
                if(it1[i] == it2.first[i]) bull++;
                else{
                    bool cows = false;
                    for(int j=0;j<4;j++){
                        if(it1[j] == it2.first[i]){
                            cows = true;
                        }
                    }
                    if(cows) cow++;
                }
                // cout<<bull<<" "<<cow<<endl;
            }
            if(bull != it2.second.first || cow != it2.second.second) check = false;
        }
        if(check == true){
            count++;
            ans = it1;
        }
    }
    if(count == 0){
        cout<<"Incorrect data";
    }
    else if(count == 1){
        cout<<ans;
    }
    else{
        cout<<"Need more data";
    }
    
    return 0;
}
