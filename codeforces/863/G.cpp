#include"bits/stdc++.h"
using namespace std;
int a[7],b[7];
struct seq
{
    int now[7];
}temp;
bool eq(seq &x,seq &y)
{
    for(int i=0;i<7;i++)if(x.now[i]!=y.now[i])return 0;
    return 1;
}
void pr(seq &x,seq &y)
{//cout<<"<<<<<<<<<"<<y.now[1]<<" "<<y.now[2]<<" "<<y.now[3]<<" "<<y.now[4]<<endl;
    for(int i=0;;i++)if(x.now[i]!=y.now[i])
    {
        if(x.now[i]+1==y.now[i])cout<<"inc "<<i<<endl;
        else cout<<"dec "<<i<<endl;
        return;
    }
}
vector<pair<int,int>>save;
void add(pair<int,int>x,pair<int,int>y,int n1,int n2)
{
    for(int i=0;i<=n1;i++)
    {
        for(int j=1;j<=n2;j++)save.push_back(y);
        y.first=-y.first;y.second=-y.second;
        //if(i==n1)break;
        save.push_back(x);
    }
}
void add(pair<int,int>x,int n)
{
    while(n--)save.push_back(x);
}
void solve(int a1,int a2,int b1,int b2)
{
    for(int i=0;i<7;i++)temp.now[i]=0;
    if(b1&1)
    {
        if(b2==1)
        {
            b2=a2;
            solve(a1,a2,b1,b2);
            for(auto &pr:save)pr.second=a2-pr.second+1;
            return;
        }
        if(b1==a1)
        {
            b1=1;
            solve(a1,a2,b1,b2);
            for(auto &pr:save)pr.first=a1-pr.first+1;
            return;
        }
        save.push_back({b1,b2});
        add({-1,0},b1-1);
        add({0,-1},1);
        add({1,0},{0,-1},b1-1,b2-2);
        add({0,1},{1,0},b2-1,a1-b1-1);
        add({0,1},{-1,0},a2-b2-1,a1-1);
        save.pop_back();
        for(int i=1;i<save.size();i++)
        {
            save[i].first+=save[i-1].first;
            save[i].second+=save[i-1].second;
        }
    }
    else
    {
        save.push_back({b1,b2});
        //add({-1,0},b1-1);
        //add({0,-1},1);
        add({-1,0},{0,1},b1-1,a2-b2);
        save.pop_back();
        add({0,-1},b2-1);
        add({1,0},1);
        add({0,1},{1,0},b2-2,a1-2);//cout<<save.size()<<endl;
        add({0,1},{-1,0},a2-b2,a1-b1-1);
        save.pop_back();
        for(int i=1;i<save.size();i++)
        {
            save[i].first+=save[i-1].first;
            save[i].second+=save[i-1].second;
        }
    }
}
vector<seq>v1,v2;
int main()
{/*
    while(1)
    {
        int a1,a2,b1,b2;
        cin>>a1>>a2>>b1>>b2;
        solve(a1,a2,b1,b2);
        cout<<save.size()<<endl;
        for(auto pr:save)printf("%d %d\n",pr.first,pr.second);
        save.clear();
    }*/
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    if(n==1)
    {
        if(b[1]==1&&a[1]==2)
        {
            cout<<"Cycle"<<endl;
            cout<<"inc 1"<<endl;
            cout<<"dec 1"<<endl;
        }
        else if(b[1]==2&&a[1]==2)
        {
            cout<<"Cycle"<<endl;
            cout<<"dec 1"<<endl;
            cout<<"inc 1"<<endl;
        }
        else if(b[1]==a[1])
        {
            cout<<"Path"<<endl;
            while(--a[1])cout<<"dec 1"<<endl;
        }
        else if(b[1]==1)
        {
            cout<<"Path"<<endl;
            while(--a[1])cout<<"inc 1"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
        return 0;
    }
    int two=0;
    for(int i=1;i<=n;i++)if(a[i]%2==0)two=i;
    if(two)
    {
        cout<<"Cycle"<<endl;
        //for(int i=1;i<=n;i++)temp.now[i]=b[i];
        v2.push_back(temp);
        for(int i=1;i<=n;i++)if(i!=two)
        {
            for(int j=1;j<=a[i];j++)
            {
                if(j&1)
                {
                    for(int k=0;k<v2.size();k++)
                    {
                        temp=v2[k];
                        temp.now[i]=j;
                        v1.push_back(temp);
                    }
                }
                else
                {
                    for(int k=v2.size()-1;k>=0;k--)
                    {
                        temp=v2[k];
                        temp.now[i]=j;
                        v1.push_back(temp);
                    }
                }
            }
            v2=v1;v1.clear();
        }
        for(int i=two;i<=two;i++)
        {
            for(int j=1;j<=a[i];j++)
            {
                if(j&1)
                {
                    for(int k=1;k<v2.size();k++)
                    {
                        temp=v2[k];
                        temp.now[i]=j;
                        v1.push_back(temp);
                    }
                }
                else
                {
                    for(int k=v2.size()-1;k>=1;k--)
                    {
                        temp=v2[k];
                        temp.now[i]=j;
                        v1.push_back(temp);
                    }
                }
            }
            for(int j=a[i];j>=1;j--)
            {
                temp=v2[0];
                temp.now[i]=j;
                v1.push_back(temp);
            }
        }
        int now=0;
        for(int i=1;i<=n;i++)temp.now[i]=b[i];
        int pos;
        for(pos=0;;pos++)if(eq(v1[pos],temp))break;
        int s=v1.size();
        //for(auto s:v1)cout<<s.now[1]<<" "<<s.now[2]<<" "<<s.now[3]<<endl;
        for(int i=0;i<s;i++)v1.push_back(v1[i]);
        for(int i=0;i<s;i++)pr(v1[i+pos],v1[i+pos+1]);
        return 0;
    }
    for(int i=1;i<=n;i++)if(b[i]%2==0)two^=1;
    if(two)
    {
        cout<<"No"<<endl;
        return 0;
    }
    two=1;
    {
        cout<<"Path"<<endl;
        //for(int i=1;i<=n;i++)temp.now[i]=b[i];
        v2.push_back(temp);
        for(int i=1;i<=n;i++)if(i!=two)
        {
            for(int j=1;j<=a[i];j++)
            {
                if(j&1)
                {
                    for(int k=0;k<v2.size();k++)
                    {
                        temp=v2[k];
                        temp.now[i]=j;
                        v1.push_back(temp);
                    }
                }
                else
                {
                    for(int k=v2.size()-1;k>=0;k--)
                    {
                        temp=v2[k];
                        temp.now[i]=j;
                        v1.push_back(temp);
                    }
                }
            }
            v2=v1;v1.clear();
        }
    }
    int s=v2.size();
    for(int i=1;i<=n;i++)temp.now[i]=b[i];
    int pos;
    temp.now[1]=0;
    for(pos=0;;pos++)if(eq(v2[pos],temp))break;//cout<<"ok"<<endl;
    solve(a[1],s,b[1],pos+1);
    for(auto pr:save)
    {
        temp=v2[pr.second-1];
        temp.now[1]=pr.first;
        v1.push_back(temp);
    }
    for(int i=1;i<v1.size();i++)
    {
        pr(v1[i-1],v1[i]);
    }
    return 0;
}
/*
3
3 3 3
2 2 1
*/