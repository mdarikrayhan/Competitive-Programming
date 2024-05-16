#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=30;
const int Len=208;
int fun[Len];
int zhi[Len];
int idx;
int find(int i);
bool cmp(int a,int b);
int main(void)
{
    int n;
    cin>>n;
    fun[207]=207;
    zhi[207]=1;
    map<string,int> m;
    map<int,int> cnt;
    m["POLYCARP"]=207;
    for(int i=0;i<n;i++)
    {
        string a,b,c;
        cin>>a>>b>>c;
        if(a.size()<2||a.size()>24)
            continue;
        for(int i=0;i<a.size();i++)
            if(a[i]>=97&&a[i]<='z')
                a[i]-=32;
        for(int i=0;i<c.size();i++)
            if(c[i]>=97&&c[i]<='z')
                c[i]-=32;
        if(m[c]==0)
            continue;
        if(fun[Len-1]!=find(m[c]))
            continue;
        idx++;
        m[a]=idx;
        fun[m[a]]=find(m[c]);
        zhi[m[a]]=zhi[m[c]]+1;
    }
    sort(zhi,zhi+Len,cmp);
    cout<<zhi[0]<<endl;
    return 0;
}

int find(int i)
{
    if(fun[i]==i)
        return i;
    return find(fun[i]);
}

bool cmp(int a,int b)
{
    return a>b;
}