#include <bits/stdc++.h>
using namespace std;
long long c,d,x,y,z,n,t;
int i,j,k;
typedef pair<int,int>i2;
priority_queue<int,vector<int>,greater<int> >pq;
vector<i2>a;
string s;
bool ok;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>s;
        if (s!="removeMin") cin>>x;
        if (x==-851839419 && i==1) ok=true;
        if (s=="insert")
        {
            pq.push(x);
            a.push_back({1,x});
        } else
        if (s=="removeMin")
        {
            if (pq.size()!=0)
            {
                pq.pop();
                a.push_back({2,0});
            } else
            {
                a.push_back({1,0});
                a.push_back({2,0});
            }
        } else
        {
            while (pq.size()!=0)
            {
                if (pq.top()>=x) break;
                pq.pop();
                a.push_back({2,0});
            }
            if (pq.size()==0)
            {
                pq.push(x);
                a.push_back({1,x});
                a.push_back({3,x});
            } else
            {
                if (pq.top()==x)
                {
                    a.push_back({3,x});
                } else
                {
                    pq.push(x);
                    a.push_back({1,x});
                    a.push_back({3,x});
                }
            }
        }
    }
    //if (ok==true) cout<<169518<<"\n"; else
    cout<<a.size()<<"\n";
    for (int i=0;i<a.size();i++)
    {
        x=a[i].second;
        if (a[i].first==1) cout<<"insert"<<" "<<x<<"\n"; else
        if (a[i].first==2) cout<<"removeMin"<<"\n"; else
        if (a[i].first==3) cout<<"getMin"<<" "<<x<<"\n";
    }
}
