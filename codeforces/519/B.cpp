#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    long long unsigned int a;
    cin>>n;
    multiset<long long unsigned int>::iterator it;
    multiset<long long unsigned int> s1;
    multiset<long long unsigned int> s2;
    multiset<long long unsigned int> s3;
    for (int i = 0; i < n; i++)
    {
        cin>>a;
        s1.insert(a);
    }
    for (int i = 0; i < n-1; i++)
    {
        cin>>a;
        s2.insert(a);
    }
    for (int i = 0; i < n-2; i++)
    {
        cin>>a;
        s3.insert(a);
    }
    for (long long unsigned int i :s2)
    {
        it=s1.find(i);
        s1.erase(it);
    }
    for (long long unsigned int i :s3)
    {
        it=s2.find(i);
        s2.erase(it);
    }
    cout<<*(s1.begin())<<endl;
    cout<<*(s2.begin());

    
    
    
}