#include <bits/stdc++.h>
using namespace std;

template<class T>
inline T IN(T& num)
{
    num = 0;
    char c = getchar(), f = 0;
    while (c != '-' && (c < '0' || c > '9')) c = getchar();
    if (c == '-') f = 1, c = getchar();
    while ('0' <= c && c <= '9') num = num * 10 + c - '0', c = getchar();
    if (f) num = -num;
    return num;
}

void sol(){
    int n;
    IN(n);
    auto getkey=[](int a,int b){
        int mx=max(a,b);
        int mn=min(a,b);
        return (long long)mn<<32|mx;
    };
    vector<int> cnt(n+1);
    unordered_map<long long,vector<int>> mymap;
    vector<bool> visited(n+1);
    
    for(int i=1;i<=n-2;++i){
        int a,b,c;
        IN(a);
        IN(b);
        IN(c);
        ++cnt[a];
        ++cnt[b];
        ++cnt[c];
        mymap[getkey(a,b)].push_back(c);
        mymap[getkey(a,c)].push_back(b);
        mymap[getkey(c,b)].push_back(a);
    }
    vector<int> v1;//首尾元素
    vector<int> v2;//首尾第2个元素
    
    for(int i=1;i<=n;++i){
        if(cnt[i]==1)
            v1.push_back(i);
        else if(cnt[i]==2)
            v2.push_back(i);
    }
    int s1,s2,e1,e2;
    s1=v1[0];
    e1=v1[2];

    if(mymap.count(getkey(s1,v2[0]))){
        s2=v2[0];
        e2=v2[1];
    }else
    {
        s2=v2[1];
        e2=v2[0];
    }

    cout<<s1<<' '<<s2<<' ';
    visited[s1]=true;
    visited[s2]=true;
    for(int i=3;i<=n;++i){
        long long key=getkey(s1,s2);
        if(!visited[mymap[key][0]]){
            cout<<mymap[key][0]<<' ';
            visited[mymap[key][0]]=true;
            s1=s2;
            s2=mymap[key][0];
        }else{
            cout<<mymap[key][1]<<' ';
            visited[mymap[key][1]]=true;
            s1=s2;
            s2=mymap[key][1];
        }
    }
    cout<<endl;
}

int main(){
    sol();
    return 0;
}